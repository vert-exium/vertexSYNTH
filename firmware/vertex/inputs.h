// Reads every input
// How it works:
// Every ms a check runs (pollISR) which checks:
//    - Which MCP chips have INT set to LOW (means something changed)
//    - Reads the chips over I2C
//    - Translates the encoder to add or remove 
//    - Reads the DATA encoder and buttons from the Teensy not the MCP

// Inputs::update() in loop debounces the button and then 
// sends basic events for now

#pragma once
#include <Arduino.h>
#include <Wire.h>
#include "config.h"

namespace Inputs {

const uint8_t DATA_ID = 24; // the data encoder is ID 24 instead of 1-23

enum EventType : uint8_t {
  EV_NONE,
  EV_TURN,         // id = knob 0-23 or DATA_ID, value = detents (+ clockwise/- ccw)
  EV_PRESS,        // id = knob 0-23 or DATA_ID, encoder pushed down
  EV_RELEASE,      // id = knob 0-23 or DATA_ID, encoder let go
  UV_LONGPRESS,    // id = knob 0-23 or DATA_ID, held down for LONG_PRESS_MS
  EV_BUTTON_DOWN,  // id = ButtonId (BTN_SHIFT, BTN_ARP, etc.)
  EV_BUTTON_UP,    // id = ButtonId
  EV_BUTTON_LONG,  // id = ButtonId, held down for LONG_PRESS_MS
};

struct Event {
  EventType type; // what happened
  uint8_t id;     // from which knob/button
  int16_t value;  // how long it was held, how far it was turned, etc.
};

const uint16_t DEBOUNCE_MS = 5; // a switch must be pressed this long to count
const uint16_t LONG_PRESS_MS = 700; // defines how long the long press is

// MCP memory registers, reading them shows what the pins of it are doing
const uint8_t MCP_IODIRA = 0x00;  // input/output for each pin (1 = input)
const uint8_t MCP_IPOLA = 0x02;   // flip the reading? (0 = no)
const uint8_t MCP_GPINTENA = 0x04; // "filter", which pins are allowed to raise the changed alert
const uint8_t MCP_DEFVALA = 0x06; // not used
const uint8_t MCP_INTCONA = 0x08; // 0 = raise the alert on any change
const uint8_t MCP_IOCON = 0x0A    // general chip settings
const uint8_t MCP_GPPUA = 0x0C;   // built in pull up resistors (1 = on)
const uint8_t MCP_GPIOA = 0x12;   // the live on/off reading of the pins
const uint8_t MCP_OLATA = 0x14;  // what outputs pins should send

// shared between the heartbeat and the main program
// volatile is used so the program knows these could change at anytime
volatile bool chipPresent[NUM_MCP];   // checks if the chip answered when started (is it detected)
volatile uint16_t chipBits[NUM_MCP]; // each chips last reading of it's 16 pins
volatile uint32_t chipReads[NUM_MCP]; // how many readings worked (debug)
volatile uint32_t chipErrors[NUM_MCP]; // how many failed (also debug) ^
volatile int16_t turnCount[NUM_KNOBS + 1]; // clicks counted by the heartbeat
volatile uint8_t directSwitches;  // the 6 switches and DATA encoder push signal

uint8_t quadState[NUM_KNOBS + 1]; // each knobs last A/B position
int8_t quadAcc[NUM_KNOBS + 1];   // partial clicks counted since the last full one

IntervalTimer pollTimer;     // the Teensy's built in timer

// Storage for the bounce filter
// There are 31 total switches
// 0-23 knob push buttons, 24 data push, 25-30 the 6 front buttons
const uint8_t NUM_SWITCHES = NUM_KNOBS + 1 + NUM_BUTTONS; // gets total # of switches
uint32_t rawPrev = 0; // last read value of the switches
uint32_t stable = 0; // the "trusted" state of them
uint32_t longFired = 0; // whether the buttons reported a long press already
uint32_t lastRawChange[NUM_SWITCHES]; // when each switch last changed
uint32_t pressedAt[NUM_SWITCHES]; // same thing but for pressed  

// "to do" queue, the list is a circle where we add
// items to the "head" and read from the "tail"/end of it
const uint8_t QUEUE_SIZE = 64; // length of it
Event queue[QUEUE_SIZE];
uint8_t qHead = 0, qTail = 0;

// volume knob:
float volumeSmooth = 0.0f; // smoothed reading
float volumeReported = -1.0f; // the last value reported to the rest of the script
uint32_t lastVolumeRead = 0;
bool volumeChangedFlag = false;

// Talking to MCP chips (via. I2C connection 1)
// Write two settings in a row, one for row A and one for row B
bool mcpWrite2(uint8_t chip, uint8_t reg, uint8_t valueA, uint8_t valueB) {
  Wire1.beginTransmission(MCP_ADDRESS[chip]); // starts the communication
  Wire1.write(reg); // gets the slot 
  Wire1.write(valueA); // value for row A
  Wire1.write(valueB); // value for row B
  return Wire1.endTransmission() == 0; // checks whether the chip has finishes
}

// writes a single setting, similar to ^
bool mcpWrite1(uint8_t chip, uint8_t reg, uint8_t value) {
  Wire1.beginTransmission(MCP_ADDRESS[chip]);
  Wire1.write(reg);
  Wire1.write(value);
  return Wire1.endTransmission() == 0;
}

// read all 16 pins at once
bool mcpRead16(uint8_t chip, uint16_t &out) {
  Wire1.beginTransmission(MCP_ADDRESS[chip]);
  Wire1.write(MCP_GPIOA);
  if (Wire1.endTransmission(false) != 0) return false; 
  if (Wire1.requestFrom(MPC_ADDRESS[chip], (uint8_t)2) != 2) return false; // requests 2 bytes
  uint8_t a = Wire1.read(); // row A
  uint8_t b = Wire1.read(); // row B
  out = (uint16_t)a | ((uint16_t)b << 8); // combines both, row A = pins 0-7 and row B 8-15
  return true;
}

// checks if anything answers at this address:
bool i2cPing(uint8_t address) {
  Wire1.beginTransmission(address);
  return Wire1.endTransmission() == 0;
}

// makes a list of which pins on this chip have a knob
uint16_t usedPinMask(uint8_t chip) {
  uint16_t mask = 0;
  for (uint8_t k = 0; k < NUM_KNOBS; k++) {
    if (KNOB_WIRING[k].chip != chip) continue;
    mask |= (1u << KNOB_WIRING[k].pinA) | (1u << KNOB_WIRING[k].pinB) | (1u << KNOB_WIRING[k].pinSW);
  }
  return mask & 0x7F7F; // filters out the last pin of each row because they can't be an input on most chips
}

// sets up one chip, returns false if it fails
bool setupChip(uint8_t chip) {
  if (!i2cPing(MCP_ADDRESS[chip])) return false;

  // the PCB only connects the row A alert pin, so this mirrors it to row B
  mcpWrite1(chip, MCP_IOCON, 0x40);

  uint16_t used = usedPinMask(chip);
  mcpWrite2(chip, MCP_IODIRA, 0x7F, 0x7F);
  mcpWrite2(chip, MCP_OLATA, 0x00, 0x00);
  mcpWrite2(chip, MCP_IPOLA, 0x00, 0x00);
  // turn on the built in pull up resistors
  mcpWrite2(chip, MCP_GPPUA, 0x7F, 0x7F);
  // raise the alert when any pin changes
  mcpWrite2(chip, MCP_DEFVALA, 0x00, 0x00);
  mcpWrite2(chip, MCP_INTCONA, 0x00, 0x00);
  mcpWrite2(chip, MCP_GPINTENA, used & 0xFF, used >> 8);

  uint16_t dummy;
  return mcpRead16(chip, dummy); 
}

// works out which way a knob turned
// +1 = quarter click clockwise/right, -1 quarter click ccw/left, 0 = no/impossible movement
const int8_t QUAD_TABLE[16] = {
  0, -1, 1, 0,
  1, 0, 0, -1,
  -1, 0, 0, 1,
  0, 1, -1, 0
};

// feed in a knob's new A/B position
inline void quadStep(uint8_t id, uint8_t now) {
  uint8_t prev = quadState[id];
  if (now == prev) return;
  quadAcc[id] += QUAD_TABLE[(prev << 2) | now]; // add up quarter clicks
  quadState[id] = now;

  // decides if a click happened
  bool atRest = (now == 0b11) || (ENCODER_STEPS_PER_DETEND == 2 && now == 0b00);
  if (atRest) {
    if (quadAcc[id] >= 2) turnCount[id]++; // one click right
    else if (quadAcc[id] <= -2) turnCount[id]--; // one click left
    quadAcc[id] = 0; // reset
  }
}

// pick one knob's A and B 
inline uint8_t knobState(uint8_t k, uint16_t bits) {
  uint8_t a = (bits >> KNOB_WIRING[k].pinA) & 1;
  uint8_t b = (bits >> KNOB_WIRING[k].pinB) & 1;
  return KNOBS_REVERSED ? (uint8_t)((b << 1) | a) : (uint8_t)((a << 1) | b);
}

// the data knob's A and B
inline uint8_t dataState() {
  uint8_t a = digitalReadFast(PIN_DATA_A);
  uint8_t b = digitalReadFast(PIN_DATA_B);
  return DATA_ENCODER_REVERSED ? (uint8_t)((b << 1) | a) : (uint8_t)((a << 1) | b);
}

// the heartbeat, runs every ms
void pollISR() {
  // reads every MCP chip every 20ms
  static uint8_t safetyCounter = 0;
  bool readAll = (++safetyCounter >= 20) || !USE_MCP_INT_PINS;
  if (safetyCounter >= 20) safetyCounter = 0;
 
  for (uint8_t c = 0; c < NUM_MCP; c++) {
    if (!chipPresent[c]) continue;    // skip nonexistent chips
    // if high, skips that chip, no new updates
    if (!readAll && digitalReadFast(MCP_INT_PIN[c]) == HIGH) continue;
 
    uint16_t bits;
    if (!mcpRead16(c, bits)) { chipErrors[c]++; continue; }
    chipReads[c]++;
    chipBits[c] = bits;
 
    // checks every knob on the chip
    for (uint8_t k = 0; k < NUM_KNOBS; k++) {
      if (KNOB_WIRING[k].chip == c) quadStep(k, knobState(k, bits));
    }
  }
 
  // reads DATA knob and
  quadStep(DATA_ID, dataState());
 
  uint8_t sw = 0;
  for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
    if (digitalReadFast(BUTTON_PINS[i]) == LOW) sw |= (1 << i);   // low = pressed
  }
  if (digitalReadFast(PIN_DATA_SW) == LOW) sw |= (1 << 6);
  directSwitches = sw;
}
 
// adds to the to-do queue
void pushEvent(EventType type, uint8_t id, int16_t value) {
  uint8_t next = (qHead + 1) % QUEUE_SIZE;
  if (next == qTail) return;   // ignores if the list is full
  queue[qHead] = { type, id, value };
  qHead = next;
}
 
//  Functions the rest of the program uses

// checks which switches are currently pressed 
uint32_t readRawSwitches() {
  uint32_t raw = 0;
  for (uint8_t k = 0; k < NUM_KNOBS; k++) {
    uint8_t c = KNOB_WIRING[k].chip;
    if (!chipPresent[c]) continue;
    // a knob's button reads 0 when pressed (it connects to ground)
    if (((chipBits[c] >> KNOB_WIRING[k].pinSW) & 1) == 0) raw |= (1ul << k);
  }
  uint8_t direct = directSwitches;
  if (direct & (1 << 6)) raw |= (1ul << DATA_ID);
  for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
    if (direct & (1 << i)) raw |= (1ul << (NUM_KNOBS + 1 + i));
  }
  return raw;
}
 
// runs once when synth gets turned on:
void begin() {
  // Pins directly on the teensy, inputs via. pull up resistors 
  for (uint8_t i = 0; i < NUM_BUTTONS; i++) pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  pinMode(PIN_DATA_A, INPUT_PULLUP);
  pinMode(PIN_DATA_B, INPUT_PULLUP);
  pinMode(PIN_DATA_SW, INPUT_PULLUP);
  for (uint8_t c = 0; c < NUM_MCP; c++) pinMode(MCP_INT_PIN[c], INPUT_PULLUP);
  // volume knob, read from 0-1023, and averages 8 readings
  analogReadResolution(10);
  analogReadAveraging(8);
 
  // starts the i2c connection
  Wire1.begin();
  Wire1.setClock(MCP_I2C_CLOCK);
 
  // finds and sets up each chip
  for (uint8_t c = 0; c < NUM_MCP; c++) {
    chipPresent[c] = setupChip(c);
    chipBits[c] = 0xFFFF;
    uint16_t bits;
    if (chipPresent[c] && mcpRead16(c, bits)) chipBits[c] = bits;
  }
  for (uint8_t k = 0; k < NUM_KNOBS; k++) {
    quadState[k] = knobState(k, chipBits[KNOB_WIRING[k].chip]);
    quadAcc[k] = 0;
    turnCount[k] = 0;
  }
  delayMicroseconds(50); // give the pull-ups a moment to settle
  quadState[DATA_ID] = dataState();
  quadAcc[DATA_ID] = 0;
  turnCount[DATA_ID] = 0;
 
  // start with nothing pressed
  rawPrev = stable = longFired = 0;
  uint32_t now = millis();
  for (uint8_t i = 0; i < NUM_SWITCHES; i++) { lastRawChange[i] = now; pressedAt[i] = now; }
 
  volumeSmooth = analogRead(PIN_VOLUME) / 1023.0f;
 
  // starts the heartbeat (1000 microsends = 1 ms)
  pollTimer.priority(224);
  pollTimer.begin(pollISR, 1000);
}
 
// turns each reading into events
void update() {
  uint32_t now = millis();   // ms since switch on
 
  // collect the # of knob clicks the heartbeat counted
  int16_t turns[NUM_KNOBS + 1];
  noInterrupts(); // temporarily pauses the heartbeat while adding 
  for (uint8_t i = 0; i <= NUM_KNOBS; i++) { turns[i] = turnCount[i]; turnCount[i] = 0; }
  interrupts(); //unpauses heartbeat
  for (uint8_t i = 0; i <= NUM_KNOBS; i++) {
    if (turns[i] != 0) pushEvent(EV_TURN, i, turns[i]);
  }
 
  // the bounce filter for all 31 switches
  uint32_t raw = readRawSwitches();
  for (uint8_t i = 0; i < NUM_SWITCHES; i++) {
    uint32_t bit = 1ul << i;
    if ((raw & bit) != (rawPrev & bit)) lastRawChange[i] = now; // still being changed, restart timer
 
    bool rawOn    = raw & bit;
    bool stableOn = stable & bit;
    bool isButton = (i > DATA_ID);  
    uint8_t id    = isButton ? (i - DATA_ID - 1) : i;  // number them 0-5 if they're buttons
 
    if (rawOn != stableOn && (now - lastRawChange[i]) >= DEBOUNCE_MS) {
      if (rawOn) {
        stable |= bit;
        longFired &= ~bit;
        pressedAt[i] = now;
        pushEvent(isButton ? EV_BUTTON_DOWN : EV_PRESS, id, 0);
      } else {
        stable &= ~bit;
        uint32_t heldMs = now - pressedAt[i]; // how long it was held
        if (heldMs > 32000) heldMs = 32000;
        pushEvent(isButton ? EV_BUTTON_UP : EV_RELEASE, id, (int16_t)heldMs);
      }
    }
    if ((stable & bit) && !(longFired & bit) && (now - pressedAt[i]) >= LONG_PRESS_MS) {
      longFired |= bit;
      pushEvent(isButton ? EV_BUTTON_LONG : EV_LONGPRESS, id, 0);
    }
  }
  rawPrev = raw;
 
  // volume knob, checked every 5ms
  if (now - lastVolumeRead >= 5) {
    lastVolumeRead = now;
    float v = analogRead(PIN_VOLUME) / 1023.0f; // turns 0-1023 to 0.0-1.0
    if (VOLUME_POT_REVERSED) v = 1.0f - v;
    volumeSmooth += (v - volumeSmooth) * 0.2f; // move 20% toward the new reading (smooths it)
    if (fabsf(volumeSmooth - volumeReported) > 0.004f) { // ignore changes too small to matter
      volumeReported = volumeSmooth;
      volumeChangedFlag = true;
    }
  }
}
// takes the next item off of the to-do list, returns false when empty
bool getEvent(Event &e) {
  if (qTail == qHead) return false;
  e = queue[qTail];
  qTail = (qTail + 1) % QUEUE_SIZE;
  return true;
}
 
// checks if button is being held down
bool buttonHeld(uint8_t button) { return stable & (1ul << (DATA_ID + 1 + button)); }
 
// checks if knob is being held down
bool knobHeld(uint8_t id) { return stable & (1ul << id); }
 
// volume knob position
float volume() { return volumeReported < 0 ? volumeSmooth : volumeReported; }
 
// true once every time it moves, then set to false
bool volumeChanged() {
  bool c = volumeChangedFlag;
  volumeChangedFlag = false;
  return c;
}
 
// troubleshooting tools (in serial monitor)
bool     chipFound(uint8_t c)  { return chipPresent[c]; }
uint16_t chipRaw(uint8_t c)    { return chipBits[c]; }
uint32_t chipReadCount(uint8_t c)  { return chipReads[c]; }
uint32_t chipErrorCount(uint8_t c) { return chipErrors[c]; }
uint8_t  knobRawState(uint8_t k)   { return knobState(k, chipBits[KNOB_WIRING[k].chip]); }
 
// print which chips answered on startup
void printChipReport(Stream &out) {
  out.println(F("MCP23017 chips on Wire1 (SDA1 pin 17, SCL1 pin 16):"));
  for (uint8_t c = 0; c < NUM_MCP; c++) {
    out.printf("  %s at 0x%02X : %s   (INT pin %d is %s)\n",
               MCP_NAMES[c], MCP_ADDRESS[c],
               chipPresent[c] ? "FOUND" : "NOT FOUND",
               MCP_INT_PIN[c],
               digitalReadFast(MCP_INT_PIN[c]) ? "HIGH (idle)" : "LOW (pending)");
  }
}
 
// Print every chip pin as 1 or 0, plus each knob's A, B and button.
void printRaw(Stream &out) {
  out.println(F("Raw MCP pins (1 = open/high, 0 = closed to GND):"));
  out.println(F("         GPB7......GPB0  GPA7......GPA0"));
  for (uint8_t c = 0; c < NUM_MCP; c++) {
    uint16_t b = chipBits[c];
    out.printf("  %s :   ", MCP_NAMES[c]);
    for (int i = 15; i >= 8; i--) out.print((b >> i) & 1);
    out.print("        ");
    for (int i = 7; i >= 0; i--) out.print((b >> i) & 1);
    out.printf("   reads=%lu errors=%lu\n", (unsigned long)chipReads[c], (unsigned long)chipErrors[c]);
  }
  out.println(F("Knobs (A B SW):"));
  for (uint8_t k = 0; k < NUM_KNOBS; k++) {
    uint16_t b = chipBits[KNOB_WIRING[k].chip];
    out.printf("  K%-2d %-5s  A=%d B=%d SW=%d%s", k, KNOB_WIRING[k].ref,
               (b >> KNOB_WIRING[k].pinA) & 1, (b >> KNOB_WIRING[k].pinB) & 1,
               (b >> KNOB_WIRING[k].pinSW) & 1, (k % 3 == 2) ? "\n" : "   |");
  }
  out.printf("  DATA  A=%d B=%d SW=%d\n", digitalReadFast(PIN_DATA_A), digitalReadFast(PIN_DATA_B),
             digitalReadFast(PIN_DATA_SW));
}
 
} // namespace Inputs
// All wiring info is in this script

#pragma once
#include <Arduino.h>

// Pins wired directly to the Teensy:
const uint8_t PIN_DATA_A = 2;
const uint8_t PIN_DATA_B = 3;
const uint8_t PIN_DATA_SW = 4;

// The six buttons:

const uint8_t NUM_BUTTONS = 6;
enum ButtonId : uint8_t { BTN_SHIFT, BTN_ENGINE, BTN_VOICE, BTN_SAVE, BTN_ARP, BTN_HOLD };
const uint8_t BUTTON_PINS[NUM_BUTTONS] = { 5, 9, 22, 32, 33, 34 };
const char* const BUTTON_NAMES[NUM_BUTTONS] = { "SHIFT", "ENGINE", "VOICE", "SAVE", "ARP", "HOLD" };

// Pin for the volume pot
const uint8_t PIN_VOLUME = 15;
// Whether the volume knob's direction is reversed
const bool VOLUME_POT_REVERSED = false;


// I2C buses 
const uint32_t MCP_I2C_CLOCK = 400000; // setting the clock high so things respond fast
const uint32_t OLED_I2C_CLOCK = 400000;
const uint8_t OLED_I2C_ADDRESS = 0x3C; 

// MCP23017 port expanders

const uint8_t NUM_MCP = 6;
const uint8_t MCP_ADDRESS[NUM_MCP] = { 0x20, 0x21, 0x22, 0x23, 0x24, 0x25 }; // U1-U6
const uint8_t MCP_INT_PIN[NUM_MCP] = { 26, 27, 28, 29, 30, 31 }; // INT0-INT5
const char* const MCP_NAMES[NUM_MPC] = { "U1", "U2", "U3", "U4", "U5", "U6" };

// Sets each chip to be read every millisecond if false, slower but it works
// without any INT lines so it's good for debug
const bool USE_MCP_INT_PINS = true;

// Which encoder is wired to which MCP pin
// GPA0-GPA7 is 0-7, GPB0-GPB7 is 8-15

#define GPA(n) (n)
#define GPB(n) (8 + (n))

struct EncoderWiring {
  uint8_t chip;  // 0 = U1-5 = U6
  uint8_t pinA;  // encoder pin A
  uint8_t pinB;  // encoder pin B
  uint8_t pinSW; // push switch
  const char* ref; // the reference on the PCB
};

// Knob # go in the physical order they're on the PCB, so it's read left block
// top left to left block bottom right and then same for the right block (the other half)
const uint8_t NUM_KNOBS = 24;
const EncoderWiring KNOB_WIRING[NUM_KNOBS] = {
  // chip (1-6), A, B, SW, PCB ref
  {   0, GPB(0),  GPB(1),  GPB(2),  "ENC1"  },
  {   0, GPB(3),  GPB(4),  GPB(5),  "ENC2"  },
  {   0, GPB(6),  GPA(0),  GPA(1),  "ENC3"  },
  {   0, GPA(6),  GPA(5),  GPA(4),  "ENC4"  },
  {   4, GPB(0),  GPB(1),  GPB(2),  "ENC17" },
  {   4, GPB(3),  GPB(4),  GPB(5),  "ENC18" },
  {   4, GPA(1),  GPA(2),  GPA(3),  "ENC19" },
  {   4, GPA(6),  GPA(5),  GPA(4),  "ENC20" },
  {   5, GPB(6),  GPB(5),  GPB(4),  "ENC21" },
  {   5, GPB(1),  GPB(0),  GPA(6),  "ENC22" },
  {   5, GPA(4),  GPA(5),  GPA(3),  "ENC23" },
  {   5, GPA(1),  GPA(2),  GPA(0),  "ENC24" },
  {   1, GPB(0),  GPB(1),  GPB(6),  "ENC5"  },
  {   1, GPB(4),  GPB(5),  GPB(3),  "ENC9"  },
  {   1, GPA(2),  GPA(3),  GPA(0),  "ENC13" },
  {   1, GPA(6),  GPA(5),  GPA(1),  "ENC6"  },
  {   2, GPB(3),  GPB(4),  GPB(5),  "ENC10" },
  {   2, GPB(2),  GPB(1),  GPB(0),  "ENC14" },
  {   2, GPA(6),  GPA(5),  GPA(4),  "ENC7"  },
  {   2, GPA(3),  GPA(2),  GPA(0),  "ENC11" },
  {   3, GPB(5),  GPB(4),  GPB(6),  "ENC15" },
  {   3, GPB(1),  GPB(0),  GPB(2),  "ENC8"  },
  {   3, GPA(6),  GPA(5),  GPA(4),  "ENC12" },
  {   3, GPA(0),  GPA(1),  GPA(2),  "ENC16" },
};

// How many clicks of signal per detend/click
// 4 = one full cycle per detend (EC11 with 20 detents / 20 pulses)
// 2 = half a cycle (for EC11s with 30 detents / 15 pulses)
// Change this if the EC11 isn't acting correctly
const uint8_t ENCODER_STEPS_PER_DETENT = 4;

// flips ALL encoders
const bool KNOBS_REVERSED = false;
// flip the DATA encoder only
const bool DATA_ENCODER_REVERSED = false;

// Screens

// If a screen appears upside down, change to true
const bool OLED_TOP_ROTATE_180 = false; // OLED 2 or J6
const bool OLED_BOTTOM_ROTATE_180 = false; // OLED 1 or J5

// Audio

const uint8_t NUM_VOICES = 6;  // max number of voices
const float HEADPHONE_VOLUME = 0.6f; // audio shield headphone amp (0.0 - 0.8)
const uint8_t LINE_OUT_LEVEL = 21;  // 13 = loudest, 31 = most quiet
// Audio memory blocks, for delay and voices, each one ~260 bytes
const int AUDIO_MEMORY_BLOCKS = 450;
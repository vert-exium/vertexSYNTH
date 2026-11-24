---
title: "vertex SYNTH"
github: "https://github.com/vert-exium/vertexSYNTH"
description: "A custom aluminum/acrylic/PETG polyphonic synth. I've always wanted a synth but they're expensive and it would be amazing to make one that looks good while functioning well! Runs on a Teensy 4.1 and connects to a MIDI keyboard"
created_at: "2026-11-15"
total_time: "31h 18m"
---

# November 15, 2026: Built the CAD and ideated

Today I lined out the main project and started thinking about components and the general theme.
I also finished the CAD for the side legs, main body, and acrylic top (without any components) <- see last pic.
I took a while and really tried to build a perfect foundation, I played around with different sizes, shapes, fillets, etc. before settling on this design. The acrylic top plate just screws into the top with heat set inserts and same for the side panels 
![Basic prototype of the general shape](https://fabricate.hackclub-assets.com/ee888ea4fead4f4e9051a5031712930828c91aed1aab11e7899b14ed08b14be1/image-png/finishedCADBody.png)
![Early on](https://fabricate.hackclub-assets.com/8e927556d630694e41a753e62906b80fe415c49c5eb880fba4bafadcefbcf230/image-png/wipCAD1.png)
![Started IO holes](https://fabricate.hackclub-assets.com/5ec7f192be43d21ad69ab27cb530cbf847a39947d1def6d44c3d19714fbad1e1/image-png/wipCAD2.png)
![Finished rear IO](https://fabricate.hackclub-assets.com/5cd5f650bc91217ab0def8d4b932e57a55208bbbe4a6d8a4788873c2dbd835e0/image-png/wipCAD3.png)
![Assembled body](https://fabricate.hackclub-assets.com/46007c847c53526c8271099e32bb999fb514834f6462575d20a1ed42321a0732/image-png/wipCADFinishedProto.png)

**Total time spent: 1h 54m**

# November 17, 2026: Started working on BOM & updated CAD

I started working on the bill of materials! I haven't found exact links or finalized the list, but I found most of what I need and thought about how everything will connect together. It's built on a Teensy 4.1 with an Audio Shield which allows it to process high quality audio. The Teensy is a popular choice for audio projects because of how well it can process high quality signals, I think it supports up to 44.1khz which is plenty for my use. I also picked buttons, encoders, etc. and some miscellaneous parts and accessories. Tomorrow I will work more on the BOM and I might CAD a bit. All I did for the CAD today was add holes on the top acrylic panel where components will go, eventually my goal is to model the actual components there too.

![](https://fabricate.hackclub-assets.com/fa7ee787c9b6556cb5067080cfb1973e9de986a12077c2e730b50592ca0aa1d7/image-png/image.png)
![](https://fabricate.hackclub-assets.com/efd31a86aca2ba1132e8881365de4f37dde64e40b58ea9954068c7922d3e3233/image-png/image.png)

**Total time spent: 2h 6m**

# November 20, 2026: Kept working on BOM

Today I continued working on the BOM and actually sourcing part links. It was really hard because Aliexpress has a lot of welcome deals that are unavoidable which made it really annoying to find parts. It ended up being more expensive than I thought but I hope the rest of the build is decently cheap. I have most of what I need in the BOM and I should finalize it in the next few hours! 

![](https://fabricate.hackclub-assets.com/ef9a2073264439f48bb591af4213e874cda30a3d93eae084062eeae0ff3cc78c/image-png/image.png)
![](https://fabricate.hackclub-assets.com/6af47dfd73da9701099e586b2c327a1f32818a22279d041de94d95ab8673ca2b/image-png/image.png)
![](https://fabricate.hackclub-assets.com/364faba8694da80d9b45bb4ea9d1a73a834bd9fb83c5a25fa60e082d1ea5a199/image-png/image.png)

**Total time spent: 2h 24m**

# November 20, 2026: (Somewhat) finalized the BOM

I pretty much finalized the BOM today, except for the PCB (much later) and DigiKey shipping because it takes a while for them to approve adding an address for some reason. Everything should be compatible and my next step will be to CAD the actual components, finalize the layout, and then build the PCB and firmware before shipping! Prices, links, and shipping/tax prices are fully up to date too!

![](https://fabricate.hackclub-assets.com/3d588ea85d4c75d309c4d12b970129667d98d88847c5ad7fd9771ea19b6da23f/image-png/image.png)

![](https://fabricate.hackclub-assets.com/d30428c25e9e9e032e9ee541aed094f61d236b6398213dc05bd5ae3e444d5017/image-png/image.png)

**Total time spent: 42m**

# November 20, 2026: Added components to CAD

I finally added the physical components to my CAD in Onshape! 
First, I had to find as many components as I could on GrabCad so I didn't have to model many myself. Most of them I found without issue, and they were comparable enough to my BOM components that I could use them as a general reference for sizing. After that, I had to make a rough outline of a few of my components myself.

It was pretty difficult to actually add all of the components into my Onshape assembly, because of various reasons. For example, for each component, I had to make a new assembly, and import the component and group it's parts together so that in my final assembly all parts of the component would move together. I also had to add small features to a few components so they would connect properly (like adding a circle on top of the potentiometer's shaft). I'm really happy with how it turned out, especially after putting so much time into it! I managed to save a lot of time by using Replicate which allowed me to quickly add similar connectors for repetitive parts instead of creating a new connector every time.

After this, I realized I was also missing the assembling hardware (inserts, screws), so I went to model those. I modelled a basic version of the heat seat inserts I'm using, and then inserted those into the main assembly. Luckily Onshape has a vast library of premade hardware assets (I used their M3 screws and set them to the length I needed) I also had to chamfer the side panels so the screws would fit flush, which ended up forcing me to mirror the side panel and reimport it into both assemblies (because before the chamfers faced the same way). 


Pictures of various stages:

![](https://fabricate.hackclub-assets.com/af8df27cead8f8205db199291a83002a831e21ab5d2891986594177d6e4da13e/image-png/image.png)
![](https://fabricate.hackclub-assets.com/6f95b56df8029d648a91bc969ec4b53cb723d0305086287c0fad71c709389688/image-png/image.png)
![](https://fabricate.hackclub-assets.com/7de56676c04b608abceef9caadb7337db8e8a261f979b2f6bf40954f2f51ab6e/image-png/image.png)
![](https://fabricate.hackclub-assets.com/acca8698a6b0a9e06899fd2eb2a0bd67a4d55738f9c777b0e6ab0cba6d5726fe/image-png/image.png)
![](https://fabricate.hackclub-assets.com/880eecd10c66046ba7bf0396124e8d01d13bf8e43212ac3a6213454c660cfd86/image-png/image.png)
![](https://fabricate.hackclub-assets.com/dca0eaa09de9fc0dc8f196b59e52a7ee3412f51d6c3ed918f8ac7f0e1663998d/image-png/image.png)
![](https://fabricate.hackclub-assets.com/66c5693e67141c9c277e56150d8b88dbcef7f8db98004cdd88253f152be0f8fd/image-png/image.png)
![](https://fabricate.hackclub-assets.com/93c158e3da2312e60c18bacd8ec0c86103e6bb6565943424e925c448f5bf2185/image-png/image.png)
![](https://fabricate.hackclub-assets.com/f5d8d89569c693d7760127d586be4a4ba16068ee9ef5e99f55fba122b2213c6f/image-png/image.png)
![](https://fabricate.hackclub-assets.com/5d28c6f29fb1b142cc81bc0d7500c33bb4b8190df673d92980084775f3896dbb/image-png/image.png)
![](https://fabricate.hackclub-assets.com/786e9781ae0a184293b3c01ffebd27a96874910b5df2d40028e3b7d390a34963/image-png/image.png)
![](https://fabricate.hackclub-assets.com/971be27b3e9d060ac0bbddded59281b13f76d9300bdeb37c2c946b9dc44b5e56/image-png/image.png)

**Total time spent: 3h 6m**

# November 21, 2026: Started PCB Schematic

I started the PCB schematic! First I had to make sure I didn't need any external KiCad libraries. After that, I started routing the schematic. I completely finished the two 1x24 rows of pins on the Teensy 4.1. Next I need to route the audio shield connections and pots, encoders, buttons, etc. before I route the physical PCB. It was a bit hard to do because I haven't used KiCad much and I haven't used it in a while, but I think I managed to figure it out pretty well. I tried to label everything clearly so it would be easier down the line, so all of the buttons are routed as BTN_ACTION for example.

![](https://fabricate.hackclub-assets.com/f3f2f382d2bb5dee4495473ae680d53587a5bf64e20854a2944ce936ff667b86/image-png/image.png)
![](https://fabricate.hackclub-assets.com/e4eb8e6e7ba769475df1ad268d4d56d6868c0a9866f0bff46d03a44d205abf9c/image-png/image.png)
![](https://fabricate.hackclub-assets.com/d66cda1963d7dd340ae5438fc5b4990b8e821114c07b00bdbac4868adcece1da/image-png/image.png)

**Total time spent: 1h 30m**

# November 21, 2026: Continued working on PCB schematic

I continued my PCB schematic, adding the pins for the audio shield ([link](https://www.sparkfun.com/teensy-4-audio-shield-rev-d.html#content-features)) This fully matches the Teensy pins I routed earlier. Shield_RowA should correspond to Teensy_RowA (1-14) and Shield_RowB should match Teensy_RowB (again, up to pin 14). I added Do Not Connect symbols as I did for my Teensy rows for unused pins and made sure everything worked fine.

![](https://fabricate.hackclub-assets.com/bbdb798f458a2f05c9ce15fd7861691a6ea81b7cd41ad75d023e093a434fd8ff/image-png/image.png)
![](https://fabricate.hackclub-assets.com/b03ed2372addbafd024e52fe1d6142e1f6905b10b21e10de6bac235177efd2c6/image-png/image.png)

**Total time spent: 42m**

# November 21, 2026: Made MCP23017 block for schematic

Another continuation of my PCB schematic!

I worked on the block for the 7 MCP23017. These will get copied over as a template with some small things changed (labels of encoders, pins, etc.)
An explanation for how it works because I think it's fun to write about:
Because there are so many encoders/components, we can't wire most of them directly to the Teensy 4.1 as there are a limited number of pins. Instead, we wire 6 MCP23017s to the Teensy 4.1. Each of those uses 12 pins for encoders (A, B, and S1, the other 2 are ground), and the MCP23017s communicate via. I2C to the Teensy. The 6 buttons get wired to the Teensy directly, and the volume pot and one more encoder also get wired directly to the Teensy. The two OLEDs will get wired right to the Teensy too via. I2C

Basically we just save a ton of pins for super cheap while maintaining full functionality

![](https://fabricate.hackclub-assets.com/57db3105c953954dee32f3ba712a0defb4fed947a96c866af3db3abc0a19a1aa/image-png/image.png)
![](https://fabricate.hackclub-assets.com/3700c28c5c538fbf15c8ca121c14028a35cf1535276bca0503889d8881ca2fad/image-png/image.png)

**Total time spent: 1h 42m**

# November 21, 2026: Copied MCP23017 blocks

Expanding from the last journal, I now expanded the one module I made previously to 6 total. Each one of them has a unique 'id' made mostly by setting A0, A1, and A2 to different power (either GND or 3.3V) (with some additional small things such as renaming INT0 to INT1, 2, etc). You can see in my second screenshot that the active GND pins (15-17 / A0-A2) are different on each one, so U1 is GND for all 3, but U3 is only 15 and 17 active. It was a bit confusing at first but I got the hang of it after I did the first copy!

![](https://fabricate.hackclub-assets.com/3be6a9773842fabb981c24a2b2a6877aa1d17093de70587b50e0b9b78d525ac2/image-png/image.png)
![](https://fabricate.hackclub-assets.com/778d9dda8156f4bb7e17f22e8dbab42c7c25b7dd8c4ac3699283d3fcdc1a20bb/image-png/image.png)

**Total time spent: 42m**

# November 21, 2026: Finished prototype of PCB schematic

I finally finished the rest of the PCB schematic!
Since this is the final major part of the schematic (other than bugfixes/iterations) I wanted to explain what I added and reexplain how the entire PCB works.

![](https://fabricate.hackclub-assets.com/f635f2a44acc303d380592c2d6436bcc234c3e3f42300e4135171016dc0c24d5/image-png/image.png)

Explanation of the new stuff I added:

As you can see, I added quite a bit. First, at the top left, ENC25 is the DATA encoder. It's wired directly to the Teensy, not through a MCP23017, since it only uses a few pins and saves us from complicated wiring (it's connections would be split between two MPCs). There is also RV1 directly to the right of it. This is the volume potentiometer, and it's wired the same (directly to the Teensy). Below ENC25 is a column of our 6 buttons. All that changes is the first pin, which will correspond with the pin on the audio shield/teensy. These are pretty simple, just the six bottom buttons which control stuff like the arp, engine, and other functions like save/shift. The two power flags let KiCad know that the Teensy is supplying power. Below them (J5/J6) are the OLED connections. I'm pretty confident for these from my Aliexpress listing, but they might need to be changed. At the bottom right, there are 8 mounting holes, and above them are 4 pull up resistors we need for I2C connections. The two right ones are most likely not needed (with the X's) but if we do need them for OLED 2, we can always solder a resistor there instead of ordering a new PCB. Lastly, at the bottom are 4 capacitors. The 2 0.1uF ones are for the 2 OLEDs since they can draw current quickly and unexpectedly, the 10 uF ones are for the Teensy/MCPs

Finally a quick re-explanation of the rest of the schematic (after the pic):

![](https://fabricate.hackclub-assets.com/3e4b843fa06caa4b6dec979422b0ada9fcf06091572b197c834a65eba787f27d/image-png/image.png)

At the top left, there is the pins for the Teensy. Buttons and all MCP connections are here as well as other small stuff. To the right, J3 and J4 are the audio shield connections which connect to the Teensy (1-14 on J3 corresponds to 1-14 on J1, same with J4/J2). Next are the 6 MCP23017s, which handle 4 encoders each. We need them because it would be too many pins used on the Teensy. Each one has a unique id and feeds info to the Teensy.

That's pretty much it for the schematic, it's not that complicated but it's pretty repetitive in some spots.

**Total time spent: 2h 36m**

# November 21, 2026: Prepared to route PCB

I'm starting the actual routing of the PCB now!

First, I imported the components from my schematic
![](https://fabricate.hackclub-assets.com/987ee694a168b238b62ca38ef7bd76b62beec2d5563433575e9da93587e3b33b/image-png/image.png)

Next, I made a rectangle as reference for the acrylic panel (the outer rectangle) and the edge of the pcb (on Edge.cuts layer, the smaller rectangle) which defines the actual size of the PCB

![](https://fabricate.hackclub-assets.com/2fcf2f8a34aa98271502c36585bbdc48b4d0b114bcfee54c23a038a9cc71726f/image-png/image.png)

I also added holes for the bottom 6 buttons here

![](https://fabricate.hackclub-assets.com/1dbb378bfdd7c019a5d70eace22561106ecdb9be4097cce3523c043f0f2622d5/image-png/image.png)

Then, I laid out the position of the 24 grid encoders. It took a pretty long time like ~45min because I had to refer to my CAD to get the center coordinate of the holes, and then I translated that to KiCad. In KiCad I made the origin the bottom left of the acrylic reference rectangle so I had to account for that too. It wasn't too bad since several encoders shared the same Y level, and they just varied in the X levels, as it was just a grid. The order of the number on the encoders look weird, but it corresponds perfectly to the function of the encoders. For example, encoders 5-8 are for the filter column, while 21-24 are for aux stuff like arp rate, delay, reverb, etc.

![](https://fabricate.hackclub-assets.com/6b3fe5d9280d6bb70fa61d671682cd1e39b44c6fdfea1f6542510d56fbbe9f70/image-png/image.png)

Next, I completed laying out the front side components. The last encoder (not in the grid), the volume potentiometer, the pads for the buttons, and then the OLED headers and holes for them. Most of it was pretty quick after I translated the grid to coordinates, but it still took a really long time because I wanted to make sure everything was precisely and correctly placed. It looks pretty good now and all that's left is to lay the back side components out (and route everything) before final testing and double checking everything!

![](https://fabricate.hackclub-assets.com/e9a45e214bbfd223b9757489b424068eb1eb4231eee1359a39d13d86455d54c6/image-png/image.png)

When I started laying the back layer, I ran into an issue. On the audio shield and teensy pins, they overlap with the OLED and pot/encoder pins. I had to shift them over in order for everything to fit without issue

![](https://fabricate.hackclub-assets.com/ad981191810e0a2eb8d14849b95bdd55a9ecf07c22860e351eff096ca110a867/image-png/image.png)

After I finished placing them, I noticed a few things were overlapping or didn't look super right. I ran the Design Rules Checker, and I noticed many errors. Most were because nothing was connected, but a few had to do with overlapping parts.

![](https://fabricate.hackclub-assets.com/0afba2179a05b014457cccf017fc5348a41e4389ea8f529487d7a688c9772ec1/image-png/image.png)

To fix these, I ended up having to implement a few fixes
1: I rotated all of the MCP chips so they're horizontal, there's enough space on the PCB for them (see the top chip, it's horizontal and not colliding with any contacts, but the ones below have conflicts)

![](https://fabricate.hackclub-assets.com/fa053630b6e31a98941cb9af5cfea3bd3d8bb6876e020542880e6ed111c25f54/image-png/image.png)

After that, some of the caps (e.g. C1) were colliding with the chips, so I had to move them too, and rotate them vertically. They sit pretty close to the chips now

![](https://fabricate.hackclub-assets.com/5ffa9355b80cd1c6c99bb5a9e0d1bc7000e4d5e66ad38c9630c2192a1602374d/image-png/image.png)

Another fix was increasing the clearance for the button pads, before they were sitting inside of the button holes. You can see the before/after

![](https://fabricate.hackclub-assets.com/de6d627e0959f4927337a217559a9ffcb3ac219cd719b70d31b3ed9bfc974e70/image-png/image.png)


I had to move a bunch of small parts around, but I ended up with this, which I'm pretty happy with. I'm going to pause for today but I only have ~30min - 1hr work to get a decent prototype finished

![](https://fabricate.hackclub-assets.com/749d3b2f7b33eaa0ccf467e4235f774da0c25c222c321e448af6f848156adb3f/image-png/image.png)

**Total time spent: 3h 24m**

# November 22, 2026: Final touches on PCB before routing

Before routing the connections, I decided to add a few small touches. I moved any silkscreen text that was colliding/outside of the board to a better place, and I added some cool text as well as rounding the PCB corners.

![](https://fabricate.hackclub-assets.com/cced1c0c7356e5d186266ece3ed788b71d69768ffe96a0b493c573c987890fdf/image-png/image.png)
![](https://fabricate.hackclub-assets.com/b6270b0a270869cfcc2e85bd277f085478218bb4c6b4666be15b825f5390d13f/image-png/image.png)

This is the full PCB before routing

![](https://fabricate.hackclub-assets.com/3921e7d443f2ea0e533066cfafb6dc1ca27d1b02633f6e07f562ba875f8b8c01/image-png/image.png)

Also running DRC before routing, the only violations are edges of the silkscreen hanging off the PCB. This is fine and it's just visual

![](https://fabricate.hackclub-assets.com/bbc7dcdc04a56da55138be693b4680ae9556490d81f4293d3821a81e4834622b/image-png/image.png)

Also set up the view before routing here

![](https://fabricate.hackclub-assets.com/f98d86a58b954b2a79fea158109795453fb8bdc452d1683b246de93a6376b809/image-png/image.png)

**Total time spent: 1h 6m**

# November 22, 2026: Routed the PCB

After the last journal entry, where I set up for routing, I started routing the PCB. As I did that, I realized the way I set the schematic up, it would result in a mess of routing, so I had to reassign the encoder pins for the U1 MCP chip.

Before
![](https://fabricate.hackclub-assets.com/2275a41d4f049ac11403275e6dc5e20f5590c444596c2512cc0b46dd925cf1f1/image-png/image.png)

After

![](https://fabricate.hackclub-assets.com/5d8598e4c44c1926806f7e12ab3de540e56a2ad7279dabeff28792fb7c09ea29/image-png/image.png)

It's sloppily wired but it should work for the PCB routing.
Then, I started routing the PCB. I made a small mistake on the schematic, where encoder 3 had connections touching, so I also had to reroute that after noticing it.

![](https://fabricate.hackclub-assets.com/3cfdaab46ce94b977a4468e88c54dfb5ebf62b1a91581a347900a55a15c73233/image-png/image.png)

It turns out that I have to rewire basically all of the MCP blocks because of how the chips are oriented on the physical board. Right now, nothing will connect correctly. Instead of messily rewiring like for U1, I decided to use labels to clean everything up!
Before/after for U5, for example

![](https://fabricate.hackclub-assets.com/2a4d8f514d709f0558ee2192f17cd5509fb5369823108444fcde9cd1595873b9/image-png/image.png)


Before I did this for all 4 MCP chips, just to make sure this actually improved the routing and I did everything correctly, I did a test routing of U5. Luckily everything worked, and while the routing wasn't the absolute cleanest, it was a LOT better and more importantly possible to route.

![](https://fabricate.hackclub-assets.com/dac6ea02283d6c0029622bfebe397d27a6d099a2c94ac2774c66d16df8fe428f/image-png/image.png)

I continued this cycle. Basically I would wire the schematic for one chip (e.g. U6) and then I would update the PCB and route it to make sure everything worked correctly. I also moved many encoders to different chips so they were close to them instead of spread out (the order of the encoders is a bit weird, so they're all over the place). This led to much cleaner overall connections. You can see the schematic and routing on the encoders after this. The actual schematic is a bit messy, since now the four encoders next to each chip don't necessarily serve that chip, they might be on a different one.

Schematic:
![](https://fabricate.hackclub-assets.com/9d4bf0e7c11843ac4474b3a5706b457b56e42fd1b640be18bd375b408542922d/image-png/image.png)

Routed PCB so far:

![](https://fabricate.hackclub-assets.com/3270b53dfaa45d6a57652d911550ae392a5e68142b3c2656a7fd0b1bdcf01a59/image-png/image.png)

Then, I started the front side routing. I first started by routing the 3V3 connection. From the Teensy, it splits off to the left and right, and several smaller branches branch off to each of the 6 chips, plus capacitors, the last encoder, etc.

This is the front side currently:

![](https://fabricate.hackclub-assets.com/b17d05b88a0b4a70aa644a805e3a6a333dda42d1326e2ee58e58045422a20d06/image-png/image.png)

I started the I2C bus routing, as you can see from the highlighted connections. They go from the two pull up resistors to each chip (they will later, the pic below only has one routed). 

![](https://fabricate.hackclub-assets.com/b15e64cd210a4300a9b0dd2cc56c817b90ef02f329feb945ca07a0163cc84841/image-png/image.png)

I2C bus now done for the left side, just two connections per chip, plus connections to the pull up resistors.

I then repeated that for the right side, so all of the I2C buses are routed! It was fairly simple because there aren't too many total connections right now but it'll probably get harder to route as time goes on.

![](https://fabricate.hackclub-assets.com/62a99f314303f87b7a323455f48ab4d31b84e3a6df082637886e93aa4c5ecadc/image-png/image.png)


I then routed the six INT lines, one per chip. I started on the right side and then did the left. It was pretty easy to route and I tried to keep it clean.

Picture of the full board so far

![](https://fabricate.hackclub-assets.com/4952cc449c36ca5b3c84d4452b69d2a5bd6959b382205cdf53449b4d292d4ad5/image-png/image.png)

After that, I decided to remove some of the connections on the audio shield, because we aren't stacking it on top of the Teensy, so it'll simplify PCB routing. All connections on the Teensy are still the same, but it's just a lot simpler on the audio shield rows now

![](https://fabricate.hackclub-assets.com/6be048cd224797b13e277a368f43d737b37561eda3b15871839cdc8894f0c58f/image-png/image.png)

Then, I just finished routing the rest of the components. I had about 30-40 more connections to route, including buttons and other data I didn't connect before. I ended up having to use a decent amount of vias per route, and I could probably have routed it more cleanly, but it works well enough. 

I ended up with this for the board. I had to double check that everything would fit correctly and I ran Design Rules Checker in KiCad to make sure I didn't miss anything important. I'm really happy with how I routed everything, even if it's a bit messy in some areas.

![](https://fabricate.hackclub-assets.com/8a8d923faf3290556a568c35248ec6819b815d1d586d21022697f91a992a6864/image-png/image.png)

Since there are so many GND connections, it would be really tedious and an eyesore to route them manually. Instead I'm doing a ground pour which fills in the rest of the board with copper that's connected to ground. 

Example of the settings I used: I placed two, one for the bottom layer, and one for the front/top layer

![](https://fabricate.hackclub-assets.com/57f59e8508b58520e3fe192ee72f3dbff49738aa17ed190cd8ab5afaa0b77d5b/image-png/image.png)

Preview of the filled board:

![](https://fabricate.hackclub-assets.com/b19545e5fbe85c40b7bc2acf3730e08d3ad8acd7532140dcdf2294ebdb631571/image-png/image.png)

Before and after of Design Rules checker, I still have a few errors to fix tomorrow, but this effectively knocked out 90 errors (unconnected GND connections)

![](https://fabricate.hackclub-assets.com/831d323cddf1460b0fae47980031026dcfa33432f1a7898a3db3de65b6f4f96e/image-png/image.png)

After
![](https://fabricate.hackclub-assets.com/d8eac92cce28f0dc5c4dd23876b072595022eba5d2c99f4f76bf7c9cb407176d/image-png/image.png)

That's all for today, this was a really long day but I'm really happy with the result and I'm glad that I'm finishing the PCB tomorrow!

**Total time spent: 6h 48m**

# November 23, 2026: Finished up PCB

Finally after many hours I finished a prototype of the PCB!

First I handled any final errors/warnings. For example, the GND pin for encoder 25 wasn't connected, so I had to make a short connection and place a via. 

![](https://fabricate.hackclub-assets.com/7a74f4f77e102149361294102edc20d85cb06b5e78b0719dfeb60c0216bebf60/image-png/image.png)

I also placed vias every once in a while between the top/bottom to slightly reduce noise, it isn't strictly necessary but I think it'll help a bit especially with audio. After dealing with some final issues, specifically having to place vias in specific pockets to make sure everything was grounded, we can finally run DRC one more time and see zero errors. The two violations are just components near the edge, and the safety area overhangs the PCB slightly, but it won't cause any issues.

![](https://fabricate.hackclub-assets.com/2d16d737e289ba75d8522cd74cc1cbde6e6b8957b4e112c76bb5ad8912843e6d/image-png/image.png)

A 3D view of the PCB

![](https://fabricate.hackclub-assets.com/618af7bd3184ff45e98961830c6ca1529594177a9323c608c17c3d8b3c8fce68/image-png/image.png)

![](https://fabricate.hackclub-assets.com/f12b2d5b4094ca3edd64047ce03099e2ef920d78505f4dafbac470d984fae24f/image-png/image.png)

Now to finish up the PCB, we need to export the STEP file to check in Onshape, and also export the production files (gerbers)

I started by exporting the PCB as a STEP and importing it into my Onshape assembly (pic w/o the body). I ran into some issues, because I had to offset it along the Y axis, but several parts weren't perfectly lined up.

![](https://fabricate.hackclub-assets.com/c2524d285984276bfef3baf0e8856cb667248a2f4263bcba476416614322175b/image-png/image.png)

Examples of parts not lining up

![](https://fabricate.hackclub-assets.com/5093cdf4cf48dd5409659cd855e800213953d89db9493ab3256780c2802d4cbc/image-png/image.png)
![](https://fabricate.hackclub-assets.com/70fe8956a16ca14b0013952e81a57bb6667e6684b4becedccaf76c19525b112c/image-png/image.png)


Unfortunately I wasted ~30 min trying to solve this. I think the issue was when I selected the fastened mate's connectors in Onshape, I selected a connector on the board that was offset from the actual middle. When I used one of the button cutouts, everything aligned, except for the potentiometer.

![](https://fabricate.hackclub-assets.com/11e2c07e54eaeccf76676e69cf29ccc9ad47743974e69ad163c408a86bdf94b9/image-png/image.png)

Potentiometer offset

![](https://fabricate.hackclub-assets.com/227f8963afb3f238d58c4fd96f6cd913a4107025c572bd8d788304ad901ffc82/image-png/image.png)

This turned out to take a while to fix too. It turns out that I also incorrectly mated the pot to the acrylic top at first, so it wasn't in the middle of the hole. It's still slightly offset. For now I'm going to leave it, and I'm going to double check everything physically and measure before I laser cut the acrylic panel. Even if I miss something I can always take a drill bit and enlargen the hole slightly even if it'll look worse. Nothing else is offset right now, except for the buttons, but that's just another visual issue. I just had to fix the mate connector as usual, and everything ended up smooth!

Pot now:

![](https://fabricate.hackclub-assets.com/8138115ca98acbde4d268bd4f791eefc9103d0115bc7e25ec13c953541f596da/image-png/image.png)

Button now (not exact bottom view but it's centered)

![](https://fabricate.hackclub-assets.com/06bd32ca0ab7b69380b89c4a64ec3dc7654140e87f964049f79bf7f5fd152c51/image-png/image.png)

I decided to also export the production files right now so they could be on Github because I'm pretty much done with the PCB anyways. I quickly reran DRC and everything was fine, so I exported the gerbers and zipped them as well. I'm glad it was a bit of a lighter day, and I finally got the PCB and CAD done. Next I'm going to start working on the firmware and try to get as much of it written/working as possible before shipping.

**Total time spent: 2h 36m**

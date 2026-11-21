---
title: "vertex SYNTH"
github: "https://github.com/vert-exium/vertexSYNTH"
description: "A custom aluminum/acrylic/PETG polyphonic synth. I've always wanted a synth but they're expensive and it would be amazing to make one that looks good while functioning well! Runs on a Teensy 4.1 and connects to a MIDI keyboard"
created_at: "2026-11-15"
total_time: "13h 6m"
---

# November 15, 2026: Built the CAD and ideated

Today I lined out the main project and started thinking about components and the general theme.
I also finished the CAD for the side legs, main body, and acrylic top (without any components) 
![Basic prototype of the general shape](https://fabricate.hackclub-assets.com/ee888ea4fead4f4e9051a5031712930828c91aed1aab11e7899b14ed08b14be1/image-png/finishedCADBody.png)
![Early on](https://fabricate.hackclub-assets.com/8e927556d630694e41a753e62906b80fe415c49c5eb880fba4bafadcefbcf230/image-png/wipCAD1.png)
![Started IO holes](https://fabricate.hackclub-assets.com/5ec7f192be43d21ad69ab27cb530cbf847a39947d1def6d44c3d19714fbad1e1/image-png/wipCAD2.png)
![Finished rear IO](https://fabricate.hackclub-assets.com/5cd5f650bc91217ab0def8d4b932e57a55208bbbe4a6d8a4788873c2dbd835e0/image-png/wipCAD3.png)
![Assembled body](https://fabricate.hackclub-assets.com/46007c847c53526c8271099e32bb999fb514834f6462575d20a1ed42321a0732/image-png/wipCADFinishedProto.png)

**Total time spent: 3h 6m**

# November 17, 2026: Started working on BOM & updated CAD

I started working on the bill of materials! I haven't found exact links or finalized the list, but I found most of what I need and thought about how everything will connect together. Tomorrow I will work more on the BOM and I might CAD a bit. All I did for the CAD today was add holes on the top acrylic panel where components will go, eventually my goal is to model the actual components there too.

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

I started the PCB schematic! First I had to make sure I didn't need any external KiCad libraries. After that, I started routing the schematic. I completely finished the two 1x24 rows of pins on the Teensy 4.1. Next I need to route the audio shield connections and pots, encoders, buttons, etc. before I route the physical PCB. It was a bit hard to do because I haven't used KiCad much and I haven't used it in a while, but I think I managed to figure it out pretty well.

![](https://fabricate.hackclub-assets.com/f3f2f382d2bb5dee4495473ae680d53587a5bf64e20854a2944ce936ff667b86/image-png/image.png)
![](https://fabricate.hackclub-assets.com/e4eb8e6e7ba769475df1ad268d4d56d6868c0a9866f0bff46d03a44d205abf9c/image-png/image.png)
![](https://fabricate.hackclub-assets.com/d66cda1963d7dd340ae5438fc5b4990b8e821114c07b00bdbac4868adcece1da/image-png/image.png)

**Total time spent: 1h 42m**

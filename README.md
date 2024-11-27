# Super Mario Sunshine Hyper Chaos Mod
A chaos mod for the BetterSMS Engine with 100 effects!

# Installation
Download the most recent release of the mod [here](https://github.com/AngryMax/zBSMS_Chaos/releases). Two methods of installation are provided:

### BetterSMS Module
If you would like to use a more modular approach (which allows allows for compatibility with mods like Eclipse), set up BetterSunshineEngine by following the directions [here](https://github.com/DotKuribo/BetterSunshineEngine), and then place the kxe file in your extracted ISO's directory `/files/Kuribo!/Mods/`.
NOTE: This mod was developed for v3.1 of BetterSunshineEngine, so compatibility with other versions may vary.

### ISO Patch
If you would like to simply patch the game like any other Sunshine mod, an xDelta file is provided. There are plenty of tutorials for how to patch xDelta files.

# Installing the Code Display script
An optional python script for displaying the active chaos effects is provided [here](https://github.com/MasterMattK/Hyper-Chaos-Code-Display). Installation and usage instructions are provided there.

# Code Wiki
If you'd like to read the documentation on what each code does, read up [here](https://docs.google.com/spreadsheets/d/1CBsjPsnEJkVuYLZ5TRXrL6cL7Uj8XLngio_n3UUDDVY/edit?)

# Some Notes
* This mod is made by two people: MasterMattK and Angry_Max! While I super appreciate people going out of their way to credit me(Angry_Max), MasterMattK also put in an equal amount of work into Hyper Chaos, so be sure to credit him as well!
* Many codes have effects that last longer than the code itself. For example, nearly any code that changes the location, size, rotation, etc. of different objects will leave those objects at their new location, size, rotation, or etc. This is by design, as it leads to near a near infinite set of different circumstances you have to play around!
* Loading zones are often included in codes that move objects around(IE: Object Vortex or Shuffle Objects). This is because we love CBT in the Hyper Chaos household.

# Devolopment Roadmap
Features you can expect in the next update(1.1):
* Seeded RNG for code selection + the ability to input custom seeds
* Important bug/crash fixes if needed
* Balance changes if needed
* Possibly other stuff
* No release date

# Known Bugs
* Poinks(the pink guys that attach to FLUDD) sometimes don't want to attach to FLUDD.
* A crash in Eel involving either "Landing Movement Lock" or "Lucid Dream."
* Touching a shine while "MAMA!" is active causes it to go intangable, and therefor uncollectable.
* "Lucid Dream" has some strange behavior when Mario ca

After 1.1 is released, Hyper Chaos will become a backburner project. This means that in some unkown point in the future, there could be an update with extra/changed codes, new settings, livestream voting, etc. We also would like to add a system for enabling/disabling certain codes, but we've yet to find a practical way to pull that off.

# Quick Notes
* Up on the dpad is a kill button if you're ever softlocked
* Down on the dpad disables the in game GUI which also disables the hyper chaos engine as a byproduct. We couldn't implement an easy fix for this as it's built into this version of the BetterSMS engine, so avoid hitting this button. 

# Credits
* Credit to JoshuaMK and the various contributers for development of [BetterSunshineEngine](https://github.com/DotKuribo/BetterSunshineEngine), which is what makes this mod compatible with various others.
* Credit to JoshuaMK and the various contributers for the [SunshineHeaderInterface](https://github.com/DotKuribo/SunshineHeaderInterface), which we used and modified to interface with the game in our code.
* Special thanks to warspyking for playtesting.

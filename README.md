# JQ6500 rescue tool
  
![JQ6500-16p](https://www.nikolairadke.de/NOKOlino/mp3modul.png)  
  
**07.06.2019** **Hooray**, my whining has been heard. I will release a more user-friendly, 32Bit-runs-on-evey-system-image soon.  
**06.04.2019** **I need help.** I am unable to compile a new Minimal Live Linux. Every Startup ends with a kernal panic after a while. :-( Has anyone some spare time? i want to update the Linux tool to a newer und much easier version.    
**21.11.2018** Added a valueble hint: The tool was compiled for 64Bit-Systems.  

For **JQ6500-16p** owners with no Windows upload software on their device. Right now, it only works on **x86_64** CPUs, a 32Bit version will follow soon.  

What's new? See the [newsblog](https://github.com/NikolaiRadke/JQ6500-rescue-tool/tree/master/NEWS.md). 
  
Some of the **16MBit** and almost every **32MBit** variant come without the windows upload tool, that autostarts, when you plug in the device, makes them, espacially for Windows users, almost useless. Luckily, there ist an existing tool written by [Reinhard Max](https://chiselapp.com/user/rmax/repository/jq6500/home) - for Linux, but Windows users are still left alone. Until now.  
  
This repository provides all the helpless owners with two tools:  
* **Linux Users:** A tool to upload a **missing upload tool** or directly upload MP3 files on your device.  
* **Windows Users:** A very small **ISO image** with a simplified batch script for run the tool above on a **CDROM/DVD** or **USB stick**. It supports both UEFI and BIOS.   

### Which kind of JQ6500-16p module do i have?

There are two common variants: 16MBit und 32MBit. But there are also 8MBit, 64MBit, and even never-seen-by-myself 128MBit modules. To be sure, take a look at the larger IC on the backside, maybe with a magnifying glass. 16 MBit modules are labeled with *25X16* like 25Q16 or 25L1606E, 32 MBit modules are labeled with *25X32* like *25Q32CS16*, so the numbers after the first 3 characters describe the size: A label beginning with *25X128...* should have 128MBit flash. BTW: *25* means *Serial Flash*.   

JQ6500-rescue-tool is a simple package of  
* [Minimal Linux Live](http://minimal.linux-bg.org/#home) from Ivan Davidov  
  with a small frontend and some small modifications. It's a very well documented small distribution!    
* [JQ6500 Linux tool](https://chiselapp.com/user/rmax/repository/jq6500/home) from Reinhard Max  
  with small changes for 32MBit support. It is beerware... ;-)   
* The original MusicDownload.iso, provided by complete JQ6500-16p 16Mbit
  with a patched versions for 8MBit, 32MBit, 64MBit and 128MBit modules.  
  
**Content**

```
JQ6500-rescue-tool/
├── ISO/
|   UEFI/BIOS compatible tool image.
|   └── modified/
|       Modified files for the standard Minimal Linux Live distribution.  
|
└── JQ6500_tool/
    Linux command line tool with source and instructions.  
    └── JQ6500_iso
        The missing images for the JQ6500.
        ├── ISO_8MBit/
        |   ISO for 8Mbit modules.  
        ├── ISO_16MBit/
        |   ISO for 16Mbit modules.  
        ├── ISO_32MBit/
        |   ISO for 32Mbit modules.  
        ├── ISO_64MBit/
        |   ISO for 64Mbit modules.  
        └── ISO_128MBit/
            ISO for 128Mbit modules.
```

## Windows

1. You need the prepared ISO-image from this repository from here [jq6500_rescue_tool.iso](https://github.com/NikolaiRadke/JQ6500-rescue-tool/tree/master/ISO).  
2. Create a bootable medium. **Right click** on *jq6500_rescue_tool.iso* und select **Burn disc image**, insert a blank CDROM oder DVD and press **Burn**.
3. Restart your computer and boot from Disc (usually bei pressing F11, F12, DEL or whatever during startup, see your mainboard manual).
4. Plug in your JQ6500-16p.
5. After boot process (max. 1 minute), you can select **1** for **16MBit** or **2** for **32MBit**. Wait until the flashing process is finished. 
6. Unplug your device.
7. Reboot to Windows by pressing CTRL+ALT+DEL. Yes, reset. Don't forget to boot from harddisk again...
8. Plug in your device again and enjoy the funny Chinese interface :-) Congrats, your module is usable again.  

## Linux

1. Plug in your device.
2. In a terminal, enter the `JQ6500_tool` folder.
3. Run   
   `./jq6500 -r -o 0 JQ6500_iso/ISO_8Mbit/MusicDownload.iso`   for **8MBit** modules or  
   `./jq6500 -r -o 0 JQ6500_iso/ISO_16Mbit/MusicDownload.iso`  for **16MBit** modules or  
   `./jq6500 -r -o 0 JQ6500_iso/ISO_32MBit/MusicDownload.iso`  for **32MBit** modules or  
   `./jq6500 -r -o 0 JQ6500_iso/ISO_64Mbit/MusicDownload.iso`  for **64MBit** modules or  
   `./jq6500 -r -o 0 JQ6500_iso/ISO_128Mbit/MusicDownload.iso` for **128MBit** modules.    
   
This tool can even upload MP3-files to your module. Just type `./jq6500 [PATH_TO_YOUR_FOLDER]/*` This will upload all files in the given folder. Very handy!  

## Related sites

The JQ6500-16p has it issues, but is very easy to handle with an unbeaten price. If you are interested in other project or in programming the module by yourself, here are some related sites you may be interested in.  

**Arduino library**  
  
There is a slim and easy library available, written by [James Sleeman](https://github.com/sleemanj/JQ6500_Serial). He also made a video on how to use the Windows interface for non-Chinese owners and gives some useful hints for a better hardware handling.  

**NOKOlino**  
  
My first project with the JQ6500-16p. And the reason for this repository. [NOKOlino](https://github.com/NikolaiRadke/NOKOlino), a cuddly small speaking monster, is quite succesful but there are many makers without Linux knowledge. NOKOlino is to be for everyone, so i made this tool.  

## At last...

You've got ideas? Suggestions? Bug reports? Feel free to contact me and contribute!

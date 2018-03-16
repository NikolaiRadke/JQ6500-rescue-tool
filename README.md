# JQ6500 rescue tool
  
![JQ6500-16p](https://www.nikolairadke.de/NOKOlino/mp3modul.png)  
  

For **JQ6500-16p** owners with no Windows upload software on their device.  
What's new? See the [newsblog](https://github.com/NikolaiRadke/JQ6500-rescue-tool/tree/master/NEWS.md). 
  
Some of the **16MBit** and almost every **32MBit** variant come without the windows upload tool, that autostarts, when you plug in the device, makes them, espacially for Windows users, almost useless. Luckily, there ist an existing tool written by [Reinhard Max](https://chiselapp.com/user/rmax/repository/jq6500/home) - for Linux, but Windows users are still left alone. Until now.  
  
This repository provides all the helpless owners with two tools:  
* **Linux Users:** A tool to upload a **missing upload tool** or directly upload MP3 files on your device.  
* **Windows Users:** A very small **ISO-Image** with a simplified batch script for run the tool above on a **CDROM/DVD** or **USB stick**. It supports both UEFI and BIOS.   

### Which JQ6500-16p module do i have?
There are two common variants: 16MBit und 32MBit. You can recognize your variant by simply plugging in the module. Does ist hav a **red** LED, it is a **16MBit** module. Is ist a **blue** LED, you've got a **32MBit** module.  

### About this repository

JQ6500-rescue-tool is a simple package of  
* [Minimal Linux Live](http://minimal.linux-bg.org/#home) from Ivan Davidov  
  with a small frontend and some small modifications. It's a very well documented small distribution!    
* [JQ6500 Linux tool](https://chiselapp.com/user/rmax/repository/jq6500/home) from Reinhard Max  
  with small changes for 32MBit support. It is beerware... ;-)   
* The original MusicDownload.iso, provided by complete JQ6500-16p
  with a patched version for 32MBit modules.  
  
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
        ├── 16MBit/
        |   ISO for 16Mbit modules (red LED).  
        └── 32MBit/
            ISO for 32Mbit modules (blue LED).
```

## Windows

1. You need the prepared ISO-Image from this repository from here [jq6500_rescue_tool.iso](https://github.com/NikolaiRadke/JQ6500-rescue-tool/tree/master/ISO).  
2. Create a bootable medium. **Right click** on *jq6500_rescue_tool.iso* und select **Burn disc image**, insert a blank CDROM oder DVD and press **Burn**.
3. Restart your Computer and boot from Disc (usually bei pressing F11, F12, DEL or whatever during startup, see your mainboard manual).
4. Plug in your JQ6500-16p.
5. After boot process (max. 1 minute), you can select **1** for **16MBit** or **2** for **32MBit**. Wait until the flashing process is finished. 
6. Unplug your device.
7. Reboot to Windows by pressing CTRL+ALT+DEL. Yes, reset. Don't forget to boot from harddisk again...
8. Plug in your device again and enjoy the funny Chinese interace :-) Congrats, your module is usable again.  

## Linux

1. Plug in your device.
2. In a terminal, enter the `JQ6500_tool` folder.
3. Run   
   `./jq6500 -o -r 0 JQ6500_iso/16Mbit/MusicDownload.iso` for **16 MBit** modules or  
   `./jq6500 -o -r 0 JQ6500_iso/32MBit/MusicDownload.iso` for **32 MBit** modules.  
   
This tool can even upload MP3-files to your module. Just type `/jq6500 [PATH_TO_YOUR_FOLDER]/*` This will upload all files in the given folder. Very handy!  

## Related sites

The JQ6500-16p has it issues, but is very easy to handle with an unbeaten price. If you are interested in other project or in programming the module by yourself, here are some related sites you may be interested in.  

**Arduino library**  
  
There is a slim and easy library available, written by [James Sleeman](https://github.com/sleemanj/JQ6500_Serial). He also made a video on how to use the Windows interface for non-Chinese owners and gives some useful hints for a better hardware handling.  

**NOKOlino**  
  
My first project with the JQ6500-16p. And the reason for this repository. [NOKOlino](https://github.com/NikolaiRadke/NOKOlino), a cuddly small speaking Monster, is quite succesful but there are many makers without Linux knowledge. NOKOlino is to be for everyone, so i made this tool.  

## At last...

You've got ideas? Suggestions? Bug reports? Feel free to contact me and contribute!

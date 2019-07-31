# JQ6500 rescue tool - V1.0
  
![JQ6500-16p](https://www.nikolairadke.de/NOKOlino/mp3modul.png)  
  
**31.07.2019** Complete rework. Now ist is ready and easy-to-use for (hopefully) everyone.

For **JQ6500-16p** owners with no Windows upload software on their device. The interface language is English You can even easly change your exitisting interface from Chinese to English with this tool.

What's new? See the [newsblog](https://github.com/NikolaiRadke/JQ6500-rescue-tool/tree/master/NEWS.md). 
  
Some of the **16MBit** and almost every **32MBit** and other variants come without the windows upload tool, that autostarts, when you plug in the device, makes them, espacially for Windows users, almost useless. Luckily, there ist an existing tool written by [Reinhard Max](https://chiselapp.com/user/rmax/repository/jq6500/home) - for Linux, but Windows users are still left alone. Until now. Reinhard is also responsible for this new ISO rework and made - well... almost everything :-)    
  
This repository provides all the helpless owners with two tools:  
* **Linux Users:** A tool to upload a **missing upload tool** or directly upload MP3 files on your device.  
* **Windows Users:** A very small **ISO image** with a simplified batch script for run the tool above on a **CDROM/DVD** or **USB stick**. It supports both UEFI and BIOS.   

### Which kind of JQ6500-16p module do i have?

There are two common variants: 16MBit und 32MBit. But there are also 8MBit, 64MBit, and even never-seen-by-myself 128MBit modules. To be sure, take a look at the larger IC on the backside, maybe with a magnifying glass. 16 MBit modules are labeled with *25X16* like 25Q16 or 25L1606E, 32 MBit modules are labeled with *25X32* like *25Q32CS16*, so the numbers after the first 3 characters describe the size: A label beginning with *25X128...* should have 128MBit flash. BTW: *25* means *Serial Flash*.   

JQ6500-rescue-tool is a simple package of  
* [Minimal Linux Live](http://minimal.linux-bg.org/#home) from Ivan Davidov,  
  with a small frontend and some small modifications. It's a very well documented small distribution!    
* [JQ6500 Linux tool](https://chiselapp.com/user/rmax/repository/jq6500/home) from Reinhard Max. Very useful.  
  It is beerware... ;-)   
  
**Content**

```
JQ6500-rescue-tool/
├── ISO/
|   UEFI/BIOS compatible tool image and the Minimal Live Linux bundle extension.  
|   └── bundle-jq6500/
|       Minimal Linux Live distribution bundle for JQ6500 support.  
|
└── JQ6500_tool/
    Linux command line tool source.  
```

## Windows

1. You need the prepared ISO-image from this repository from here [jq6500_rescue_tool.iso](https://github.com/NikolaiRadke/JQ6500-rescue-tool/tree/master/ISO).  
2. Create a bootable medium. **Right click** on *jq6500_rescue_tool.iso* und select **Burn disc image**, insert a blank CDROM oder DVD and press **Burn**.
3. Restart your computer and boot from Disc (usually bei pressing F11, F12, DEL or whatever during startup, see your mainboard manual).
4. Plug in your JQ6500-16p.
5. After boot process (max. 1 minute), select **r**. Wait until the flashing process is finished. 
6. Unplug your device.
7. Reboot to Windows by pressing CTRL+ALT+DEL. Yes, reset. Don't forget to boot from harddisk again...
8. Plug in your device again and enjoy Windows interface :-) Congrats, your module is usable again and speaks a bit more western language.  

## Linux

1. Compile the source file *jq6500.c* by typing `Make`. Or, if you encounter some errors, type `gcc jq6500.c -o jq6500`
2. Plug in your device.
3. In a terminal, enter the `JQ6500` folder.
4. Run `./jq6500 -X` to fix your module.    
   
This tool can even upload MP3-files to your module. Just type `./jq6500 -W [PATH_TO_YOUR_FOLDER]/*` This will upload all files in the given folder. Very handy!  

## Related sites

The JQ6500-16p has it issues, but is very easy to handle with an unbeaten price. If you are interested in other project or in programing the module by yourself, here are some related sites you may be interested in.  

**Arduino library**  
  
There is a slim and easy library available, written by [James Sleeman](https://github.com/sleemanj/JQ6500_Serial). He also made a video on how to use the Windows interface for non-Chinese owners and gives some useful hints for a better hardware handling.  

**NOKOlino**  
  
My first project with the JQ6500-16p. And the reason for this repository. [NOKOlino](https://github.com/NikolaiRadke/NOKOlino_2), a cuddly small speaking monster, is quite succesful but there are many makers without Linux knowledge. NOKOlino is to be for everyone, so i made this tool.  

## At last...

You've got ideas? Suggestions? Bug reports? Feel free to contact me and contribute!

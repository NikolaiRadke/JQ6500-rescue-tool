# JQ6500 rescue tool
  
![JQ6500-16p](https://www.nikolairadke.de/NOKOlino/mp3modul.png)  
  
For **JQ6500-16p** owners with no Windows upload software on their device. 
  
Some of the **16MBit** and almost every **32MBit** variant come without the windows upload tool, that autostarts, when you plug in the device, makes them, espacially for Windows users, almost useless. Luckily, there ist an existing tool written by [Reinhard Max](https://chiselapp.com/user/rmax/repository/jq6500/home) - for Linux, but Windows users are still left alone. Until now.  
  
This repository provides all the helpless owners with two tools:  
* **Linux Users:** A tool to upload a **missing upload tool** or **MP3 files** to your device.  
* **Windows Users:** A very small **ISO-Image** with a simplified batch script for run the tool above on a **CDROM/DVD** or **USB stick**. It supports both UEFI and BIOS.   

## Which JQ6500-16p module do i have?
There are two common variants: 16MBit und 32MBit. You can recognize your variant by simply plugging in the module. Does ist hav a **red** LED, it is a **16MBit** module. Is ist a **blue** LED, you've got a **32MBit** module.  

### About this repository

JQ6500-rescue-tool is a simple package of  
* [Minimal Linux Live](http://minimal.linux-bg.org/#home) from Ivan Davidov
  With a small frontend and some small modifications  
* [JQ6500 Linux tool](https://chiselapp.com/user/rmax/repository/jq6500/home) from Reinhard Max  
  With small changes for 32MBit support  
* The original MusicDownload.iso, provided by complete JQ6500-16p
  With a patched version for 32MBit modules  

## Windows
1. You need the prepared ISO-Image from this repository from here [jq6500_rescue_tool.iso](https://github.com/NikolaiRadke/JQ6500-rescue-tool/tree/master/ISO).  
2. Create a bootable medium. **Right click** on *jq6500_rescue_tool.iso* und select **Burn disc image**, insert a blank CDROM oder DVD and press **Burn**.
3. Restart your Computer and boot from Disc (usually bei pressing F11, F12, DEL or whatever during startup, see your mainboard manual).
4. Plug in your JQ6500-16p.
5. After boot process (max. 1 minute), you can select **1** for **16MBit** or **2** for **16MBit**. Wait until the flashing process is finished. 
6. Unplug your device.
7. Reboot to Windows by pressing CTRL+ALT+DEL. Yes, reset. Don't forget to boot from harddisk again...
8. Plug in your device again and enjoy the funny Chinese interace :-) Congrats, your module is usable again.  

## Linux

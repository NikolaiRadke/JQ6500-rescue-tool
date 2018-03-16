# JQ6500 rescue tool
  
![JQ6500-16p](https://www.nikolairadke.de/NOKOlino/mp3modul.png)  
  
For **JQ6500-16p** owners with no Windows upload software on their device. 
  
Some of the **16MBit** and almost every **32MBit** variant come without the windows upload tool, that autostarts, when you plug in the device, makes them, espacially for Windows users, almost useless. Luckily, there ist an existing tool written by [Reinhard Max](https://chiselapp.com/user/rmax/repository/jq6500/home) - for Linux, but Windows are still left alone. Until now.  
  
This repository provides all the helpless owners with two tools:  
* **Linux Users:** A tool to upload a **missing upload tool** or **MP3 files** to your device.  
* **Windows Users:** A very small **ISO-Image** with a simplified batch script for run the tool above on a **CDROM/DVD** or **USB stick**. It supports both UEFI and BIOS.   

## Which JQ6500-16p module do i have?
There are two common variants: 16MBit und 32MBit. You can recognize your variant by simply plugging in the module. Does ist hav a **red** LED, it is a **16MBit** module. Is ist a **blue** LED, you've got a **32MBit** module.  
  
## Windows
  
1. Create a bootable medium. Either **right click** on *jq6500_rescue_tool.iso* und select **Burn disc image**, insert a blank CDROM oder DVD and press **Burn**.
2. Restart your Computer and boot from Disc (usually bei pressing F11 during startup).
3. Plug in your JQ6500-16p.
4. After boot process (max 1 Minute), you can select **1** for **16MBit** or **2** for **16MBit**. Wait until the flashing process is finished. 
5. Unplug your device.
6. Reboot to Windows by pressing CTRL+ALT+DEL. Yes, reset. Don't forget to boot from Harddisk again...
7. Plug in your device again and enjoy the funny Chinese interace :-) Congrats, your module is usable again.  

### Linux



# Modifications for Minimal Linux Live
  
This folder contains all the files, i modified for the tool image:  
* **.config** -> /  
  Main configuration file.  
* **90_kbd.sh** -> /minimal_overlay/bundles/kbd/  
  Keyboard configuration. Still set to English, but runs the toolkit script after startup.  
* **motd** -> /minimal__rootfs/etc/  
  Modified welcome text.  
* **syslinux.cfg** -> /minimal_boot/bios/boot/syslinux/  
  Modified boot text.  
* **toolkit** -> /minimal_overlay/rootfs/jq6500/  
  The tool frontend.
  
Beside this files, if you want to make your own ISO, you need to copy the following files from this repository to the following folders:

* **jq6500** -> /minimal_overlay/rootfs/jq6500/  
  The compiled tool.  
* **MusicDownload.iso** (8MBit) -> /minimal_overlay/rootfs/jq6500/ISO_8MBit  
* **MusicDownload.iso** (16MBit) -> /minimal_overlay/rootfs/jq6500/ISO_16MBit  
* **MusicDownload.iso** (32MBit) -> /minimal_overlay/rootfs/jq6500/ISO_32MBit  
* **MusicDownload.iso** (64MBit) -> /minimal_overlay/rootfs/jq6500/ISO_64MBit  
* **MusicDownload.iso** (128MBit) -> /minimal_overlay/rootfs/jq6500/ISO_128MBit  


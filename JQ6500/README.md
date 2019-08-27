# Uploading files on the JQ6500 with Linux

It is quite easy with this command line tool, written by [Reinhard Max](https://chiselapp.com/user/rmax/repository/jq6500).  I added a precompiled version (64 Bit). It is free, but it is also *beerware*... ;-)  

1. Check, if ``` ./jq6500 ``` is running.  
2. If not, compile it by yourself, just by typing ``` make ```. 
3. Try again.
4. Connect your JQ6500 module to your system with a micro USB cable. 
5. Test your device by typing  ``` ./jq6500 -S ```. The tool will tell you the detected flash size.  
6. 32 MBit modules: Upload your files by typing ``` ./jq6500 -W ../mp3/male/mp3_32MBit/* ```(32 MBit male voice)  or ``` ./jq6500 -W ../mp3/female/mp3_32MBit/* ``` (32 MBit female voice).  
7. 16 MBit modules: Upload your files by typing ``` ./jq6500 -W ../mp3/male/mp3_16_MBit/* ```(16 MBit male voice)  or ``` ./jq6500 -W ../mp3/female/mp3_16MBit/* ``` (16 MBit female voice). 

If your MP3 files are in another directory, modify the last argument.  

## Repairing a JQ6500 without Windows software with Linux
  
Strangely, some modules come without the integrated Windows software. If you have a friend in need without Linux, the tool can fix the module.

1. Like above, check if the tool is running correctly.  
2. Connect your JQ6500 module to your system with a micro USB cable.  
3. Just type ``` ./jq6500 -X ```. 

That's it. You can now use your module with Windows.  

## Repairing a JQ6500 without Windows software without Linux
  
If you are a Windows user see my [JQ6500-rescue-tool](https://github.com/NikolaiRadke/JQ6500-rescue-tool) repository. There you find a quite simple way to fix your module.   



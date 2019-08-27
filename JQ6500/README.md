# Linux JQ6500 uploader and repair tool

It is quite easy to use command line tool, written by [Reinhard Max](https://chiselapp.com/user/rmax/repository/jq6500).  I added a precompiled version (64 Bit). It is free, but it is also *beerware*... ;-) If you have a runnung linux system, you can just use this tool to repair your module. You can even use your tool to upload files or erase the memory. Just type ``` ./jq6500 ``` to learn more.  

## Is it working?

1. Check, if ``` ./jq6500 ``` is running.  
2. If not, compile it by yourself, just by typing ``` make ```. 
3. Try again.
4. Connect your JQ6500 module to your system with a micro USB cable. 
5. Test your device by typing  ``` ./jq6500 -S ```. The tool will tell you the detected flash size. Yes, the tool is working!  

## Repairing a JQ6500 without Windows software with Linux
  
Strangely, some modules come without the integrated Windows software. If you have a friend in need without Linux, the tool can fix the module.

1. Like above, check if the tool is running correctly.  
2. Connect your JQ6500 module to your system with a micro USB cable.  
3. Just type ``` ./jq6500 -X ```. 

That's it. You can now use your module with Windows.  

## Repairing a JQ6500 without Windows software without Linux
  
Oh yes, you need the ISO image in this repository.  



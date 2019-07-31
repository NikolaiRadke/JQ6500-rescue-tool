#!/bin/sh
clear
echo
echo "*** [31mJQ6500 toolkit[0m ***"
echo
echo "Looking for a JQ6500 MP3-module..."
echo
sleep 1
jq6500 -L
sleep 1
while true; do
    echo
    echo "What do you want to do?"
    echo
    echo " [[31mR[0m] - Repair the module"
    echo " [[31mL[0m] - Look for JQ6500 modules again"
    echo " [[31mS[0m] - Show flash size"
    echo " [[31mX[0m] - Exit"
    echo
    read -p "Choice: " choice
    case "$choice" in
        r|R) jq6500 -X
           echo
           echo "Done."
           echo "Plug in another device. Press any key."
           read
        ;;
        l|L) echo "Looking..."
           sleep 1
	   jq6500 -L
	   sleep 1
        ;;
        s|S) echo "Looking..."
           sleep 1
           jq6500 -S
	   sleep 1
        ;;
        x|X|q|Q) break
        ;;
        *) echo "Unknown option."
    esac
done
echo
echo "[32mBye![0m"
echo
echo "Hint of the day:"
echo "You can use the full power of the jq6500 utility by calling it"
echo "directly from the command line."
echo

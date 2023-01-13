#!/bin/bash

while true; do
    # dwm repo directory
    export DWM_DIR=$HOME/dwm

	# autostart script
	~/scripts/wmrc.sh

	# bar items
	~/dwm/scripts/bar.sh &

	# Log stderror to a file
	dwm 2> ~/.dwm.log
done

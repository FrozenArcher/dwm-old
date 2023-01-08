#!/bin/bash

# autostart script
~/scripts/wmrc.sh

# bar items
~/dwm/scripts/baritems/bar.sh &

while true; do
    # Log stderror to a file
    dwm 2> ~/.dwm.log
done

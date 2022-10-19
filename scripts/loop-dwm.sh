#!/bin/bash

# avoid wmrc apps to start multiple times
~/scripts/wmrc.sh

# bar items
~/dwm/scripts/baritems/bar.sh &

while true; do
    # Log stderror to a file
    dwm 2> ~/.dwm.log
    # No error logging
    #dwm >/dev/null 2>&1
done


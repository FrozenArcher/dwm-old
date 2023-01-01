#!/bin/bash

battery() {
    echo -e $(upower -i $(upower -e | grep BAT) | \
        grep --color=never -E "state|percentage" | \
        ~/dwm/scripts/baritems/process_power.py)
}

dtime() {
    echo -e "\U0001f552 $(date +"%F %R")"
}

volinfo() {
    echo $(amixer sget Master | awk '/Left:/ { printf "%s %s\n",$5,$6 }' | ~/dwm/scripts/baritems/volinfo.py)
}


bar="$(volinfo) | $(battery)  | $(dtime) |"
xsetroot -name "$bar"

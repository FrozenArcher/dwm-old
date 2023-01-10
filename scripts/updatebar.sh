#!/bin/bash

ITEM_PATH="$HOME/dwm/scripts/baritems"

dtime() {
    echo -e "🕓 $(date +"%F %R")"
}

bar="$($ITEM_PATH/volume) | $($ITEM_PATH/battery) | $(dtime) |"
xsetroot -name "$bar"

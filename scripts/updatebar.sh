#!/bin/bash

ITEM_PATH="$HOME/dwm/scripts/baritems"

dtime() {
    echo -e "🕓 $(date +"%m-%d %R")"
}

disk_usage() {
    echo "🖴 $(df -h | grep '/$' | awk '{printf "%s %s/%s\n", $5, $3, $2}')"
}

bar="$($ITEM_PATH/volume) | $(disk_usage) | $($ITEM_PATH/battery) | $(dtime) |"
xsetroot -name "$bar"

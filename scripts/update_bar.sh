#!/bin/bash

ITEM_PATH="$DWM_DIR/scripts/bar_items"

dtime() {
    echo -e "🕓 $(date +"%m-%d %R")"
}

disk_usage() {
    echo "🖴 $(df -h | grep '/$' | awk '{printf "%s %s/%s\n", $5, $3, $2}')"
}

backlight() {
    echo "☉ $(light | cut -d'.' -f1)"
}

bar="$(backlight) | $($ITEM_PATH/volume) | $(disk_usage) | $($ITEM_PATH/battery) | $(dtime) |"
xsetroot -name "$bar"

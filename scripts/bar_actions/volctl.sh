#!/bin/env bash

UPDATE_CMD="sh -c $DWM_DIR/scripts/update_bar.sh"

DEF_SINK="$(pactl get-default-sink)"

if [ $1 == "up" ]; then
    pactl set-sink-volume $DEF_SINK +5%
    $UPDATE_CMD
elif [ $1 == "down" ]; then
    pactl set-sink-volume $DEF_SINK -5%
    $UPDATE_CMD
elif [ $1 == "mute" ]; then
    pactl set-sink-mute $DEF_SINK toggle
    $UPDATE_CMD
fi

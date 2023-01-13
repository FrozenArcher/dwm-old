#!/bin/bash

updcmd="sh -c ~/dwm/scripts/updatebar.sh"

DEF_SINK="$(pactl get-default-sink)"

if [ $1 == "up" ]; then
    pactl set-sink-volume $DEF_SINK +5%
    $updcmd
elif [ $1 == "down" ]; then
    pactl set-sink-volume $DEF_SINK -5%
    $updcmd
elif [ $1 == "mute" ]; then
    pactl set-sink-mute $DEF_SINK toggle
    $updcmd
fi

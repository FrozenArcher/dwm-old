#!/bin/bash

updcmd="sh -c ~/dwm/scripts/updatebar.sh"

if [ $1 == "up" ]; then
    pactl set-sink-volume 0 +5%
    $updcmd
elif [ $1 == "down" ]; then
    pactl set-sink-volume 0 -5%
    $updcmd
elif [ $1 == "mute" ]; then
    pactl set-sink-mute 0 toggle
    $updcmd
fi

#!/bin/bash

# autostart
# ~/scripts/locker &
picom -b --experimental-backends

if [ $? -ne 0 ]; then
	picom -b
fi

~/.fehbg &
fcitx5 -d --verbose 2
cfw &
xfce4-power-manager &

# avoid multiple launch
killall blueberry-tray
killall udiskie

# tray apps
blueberry-tray
udiskie --tray &
nm-applet &

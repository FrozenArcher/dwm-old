#!/bin/bash

run() {
	if ! pgrep -f "$1" ; then
		"$@"
	fi
}

# autostart
~/scripts/locker &

run picom -b
run cfw &
run fcitx5 &
run nm-applet &
run udiskie --tray &
run blueman-applet &

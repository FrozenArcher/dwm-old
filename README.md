# FrozenArcher's DWM fork

based on dwm 6.4

see [upstream](https://dwm.suckless.org/)

**see my [dotfile repository](https://github.com/FrozenArcher/archconfig.git) for scripts used and the complete environment**

## Needed packages

* acpi
* alsa-utils (for `amixer`)
* kitty
* picom-animations-git (aur)
* pulseaudio (for `pactl`)
* trayer

## Installation

```
# git clone via http
git clone https://github.com/FrozenArcher/dwm.git
# or via ssh
git clone git@github.com:FrozenArcher/dwm.git

# compile dwm
cd dwm
./install.sh
```

## My features

* rolling through every layouts
* audio control shortcuts & its realtime refresh bar module
* run autostart script (similar to the autostart patch)
* toggle trayer (script needed)
* rofi apprun menu

## Applied patches

* dwm-systray-6.3.diff
* dwm-fullgaps-toggle-20200830.diff
* dwm-pertag-20200914-61bb8b2.diff
* dwm-fancybar-20220527-d3f93c7.diff
* dwm-actualfullscreen-20211013-cb3f58a.diff

***

## Upcoming features

* rofi power menu
* brightness control

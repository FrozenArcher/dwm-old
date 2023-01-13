# FrozenArcher's DWM fork

based on dwm 6.4

see [upstream](https://dwm.suckless.org/)

**see my [dotfile repository](https://github.com/FrozenArcher/arch-config.git) for scripts used and the complete environment**

## Dependences

The dwm package depends on:

*libx11
*libxinerama
*libxft

My dwm:

* acpi
* kitty
* light
* picom
* pulseaudio (for `pactl`)
* upower
* xfce4-screenshooter
* xorg-xsetroot

Installing dependences in archlinux:
```
yay -S libx11 libxinerama libxft acpi kitty light picom pulseaudio upower xfce4-screenshooter xorg-xsetroot
```

## Fonts

* LXGW Wenkai Mono
* FiraCode Nerd Font
* Twemoji
* Font Awesome 6 Free

Installing fonts in archlinux

```
yay -S nerd-fonts-complete otf-font-awesome ttf-lxgw-wenkai ttf-lxgw-wenkai-mono ttf-twemoji
```

## Installation

``` bash
# git clone via http
git clone https://github.com/FrozenArcher/dwm.git
# or via ssh
git clone git@github.com:FrozenArcher/dwm.git

# compile dwm
cd dwm
sudo ./install
```

## My features

* volume control
* brightness control
* run autostart script (similar to the autostart patch)
* rofi apprun menu
* rofi powermenu

## Applied patches

* dwm-systray-6.3.diff
* dwm-fullgaps-toggle-20200830.diff
* dwm-pertag-20200914-61bb8b2.diff
* dwm-fancybar-20220527-d3f93c7.diff
* dwm-actualfullscreen-20211013-cb3f58a.diff
* dwm-colorbar-6.3.diff

***

## Upcoming features

none

# FrozenArcher's DWM fork

based on dwm 6.4

see [upstream](https://dwm.suckless.org/)

If you use a distro that doesn't use systemd, you should modify some relative scripts.

## Dependences

The dwm package depends on:

* libx11
* libxinerama
* libxft

My dwm:

* acpi
* kitty
* light
* picom
* pulseaudio (for `pactl`)
* rofi
* upower
* xfce4-screenshooter
* xorg-xsetroot

Installing dependences in archlinux:

``` bash
yay -S libx11 libxinerama libxft acpi feh kitty light picom pulseaudio rofi upower xfce4-screenshooter xorg-xsetroot
```

Installing optional dependences:

``` bash
yay -S fcitx5-{im,lua,chinese-addons} blueberry bluez{,-utils} udiskie network-manager-applet clash-for-windows-bin
```

## Fonts

* LXGW Wenkai Mono
* FiraCode Nerd Font
* Twemoji
* Font Awesome 6 Free

Installing fonts in archlinux

``` bash
yay -S ttf-liberation nerd-fonts-complete otf-font-awesome ttf-lxgw-wenkai ttf-lxgw-wenkai-mono ttf-twemoji
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

* Add configuration section in README.md
* Add automatic lock function

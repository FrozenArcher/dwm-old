#!/bin/python3

# upower -i $(upower -e | grep BAT) | grep --color=never -E "state|percentage" | ./process_power.py

def proc_info(info: str) -> str:
    items = info.split(":")
    res = [i.lstrip().rstrip() for i in items][-1]
    return res


state = proc_info(input())
percentage = proc_info(input())
bat_icons = ["  ", "  ", "  ", "  ", "  "]


# battery percentage to icon index
def perctoidx(p: int) -> int:
    id = 0
    if p >= 90:
        id = 0
    elif 70 <= p < 90:
        id = 1
    elif 40 <= p < 70:
        id = 2
    elif 15 <= p < 40:
        id = 3
    else:
        id = 4
    return id


msg = ""
icon = bat_icons[perctoidx(int(percentage[:-1]))]

if state == "fully-charged":
    msg = "FULL"
elif int(percentage[:-1]) <= 10 and state != "charging":
    #       warning icon
    icon = "\u26a0" + " " + icon
    msg = percentage
else:
    msg = percentage

if state == "charging":
    #       cabel icon
    icon = "\U0001f50c" + " " + icon
    msg = " " + percentage

print(msg, icon, sep=" ")

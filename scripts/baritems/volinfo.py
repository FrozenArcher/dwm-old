#!/usr/bin/python

# amixer sget Master | awk '/Left:/ { printf "%s %s\n",$5,$6 }' | ~/dwm/scripts/baritems/volinfo.py

arg = input().split(" ")
vol = arg[0].removeprefix("[").removesuffix("]")
pow = arg[1].removeprefix("[").removesuffix("]")


# volume to icon index
def voltoidx(v: int, p: str) -> int:
    if p == "off":
        return 3
    else:
        if 0 <= v <= 20:
            return 2
        if 20 < v <= 60:
            return 1
        if v >= 60:   # may >= 100
            return 0
    return 0


# speaker   3 wave       1 wave         0 wave         stroke
icons = ["\U0001f50a", "\U0001f509", "\U0001f508", "\U0001f507"]
icon = icons[voltoidx(int(vol[:-1]), pow)]
msg = vol

if pow == "on":
    pass
elif pow == "off":
    msg = "muted"
else:
    icon = "VOL:Unknown state"
    msg = pow

print(icon, msg, sep=" ")

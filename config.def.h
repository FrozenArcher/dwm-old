/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 6, .gappx = 6 };
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */
static const char *fonts[]          = {
	"LXGW WenKai Mono:size=14",
	"FiraCode Nerd Font:size=14",
	"Twemoji:size=9",
	"Font Awesome 6 Free:size=12",
};
static const char col_blue1[]       = "#777799";
static const char col_blue2[]       = "#567890";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               	fg         bg        border   */
	[SchemeNorm] 	 = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  	 = { col_gray4, col_cyan,  col_cyan  },
	// Statusbar right {text,background,not used but cannot be empty}
	[SchemeStatus]   = { col_gray3, col_gray1, "#000000"  },
	// Tagbar left selected {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { col_gray4, col_blue2,  "#000000"  },
	// Tagbar left unselected {text,background,not used but cannot be empty}
	[SchemeTagsNorm] = { col_gray3, col_gray1, "#000000"  },
	// infobar middle  selected {text,background,not used but cannot be empty}
	[SchemeInfoSel]  = { col_gray4, col_blue1,  "#000000"  },
	// infobar middle  unselected {text,background,not used but cannot be empty}
	[SchemeInfoNorm] = { col_gray3, col_gray1, "#000000"  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance		    title       tags mask   isfloating   monitor */
	{ "firefox",            NULL,       	    NULL,       0,          0,           -1 },
	{ "Clash for Windows",  NULL,			    NULL,       0,          1,           -1 },
	{ "Blueberry.py", 	    "blueberry.py",		NULL,       0,          1,           -1 },
};

/* layout(s) */
static const float mfact        = 0.618; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol       arrange function */
	{ "TILE",       tile },    /* first entry is default */
	{ "FLOAT",      NULL },    /* no layout function means floating behavior */
	{ "MONOCLE",    monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
#define screenshotcmd "xfce4-screenshooter -r"
#define appmenucmd "$DWM_DIR/scripts/rofi-appmenu.sh"
#define VOLCTL(cmd) SHCMD("$DWM_DIR/scripts/bar_actions/volctl.sh "cmd)
#define BLCTL(cmd) SHCMD("$DWM_DIR/scripts/bar_actions/blctl.sh "cmd)
static const char *termcmd[]  = { "kitty", NULL };

#include <X11/XF86keysym.h>

static const Key keys[] = {
    	/*   Key                           function        argument */
    	/* Volume keys */
	{ 0, XF86XK_AudioLowerVolume,      spawn,          VOLCTL("down") },
	{ 0, XF86XK_AudioMute,             spawn,          VOLCTL("mute") },
	{ 0, XF86XK_AudioRaiseVolume,      spawn,          VOLCTL("up") },
	/* Brightness keys */
	{ 0, XF86XK_MonBrightnessUp,       spawn,          BLCTL("up") },
	{ 0, XF86XK_MonBrightnessDown,     spawn,          BLCTL("down") },
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          SHCMD(appmenucmd) },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD(screenshotcmd) },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_r,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          SHCMD("$DWM_DIR/scripts/powermenu.sh") },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -2 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +2 } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

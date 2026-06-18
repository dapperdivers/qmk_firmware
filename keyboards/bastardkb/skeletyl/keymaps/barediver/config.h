// Copyright 2024 Derek Mackley
// Miryoku-derived layout for the Skeletyl (Colemak-DH, flipped layers,
// inverted-T nav, custom thumb cluster). Tuning matches upstream Miryoku.

#pragma once

// Home-row mods / mod-tap tuning
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0

// Modern home-row-mod tuning.
// CHORDAL_HOLD: a tap-hold key only holds when the next key is on the opposite
//   hand (kills same-hand alpha-roll misfires). Same-hand modifier/layer chords
//   we rely on for Hyprland (Super+Num, Super+Shift+num) are re-allowed via
//   get_chordal_hold() in keymap.c.
// PERMISSIVE_HOLD: deliberate holds register through a nested press+release, so
//   the re-allowed same-hand chords resolve as holds while fast rolls stay taps.
//   (Intentionally NOT HOLD_ON_OTHER_KEY_PRESS, which would hold "a" mid-"are".)
// FLOW_TAP_TERM: while typing fast, settle tap-holds pressed within this window
//   of the previous key as taps.
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
#define FLOW_TAP_TERM 150

// Auto Shift (non-alpha keys only)
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Mouse key tuning
#ifdef MOUSEKEY_DELAY
#    undef MOUSEKEY_DELAY
#endif
#define MOUSEKEY_DELAY 0
#ifdef MOUSEKEY_INTERVAL
#    undef MOUSEKEY_INTERVAL
#endif
#define MOUSEKEY_INTERVAL 16
#ifdef MOUSEKEY_WHEEL_DELAY
#    undef MOUSEKEY_WHEEL_DELAY
#endif
#define MOUSEKEY_WHEEL_DELAY 0
#ifdef MOUSEKEY_MAX_SPEED
#    undef MOUSEKEY_MAX_SPEED
#endif
#define MOUSEKEY_MAX_SPEED 6
#ifdef MOUSEKEY_TIME_TO_MAX
#    undef MOUSEKEY_TIME_TO_MAX
#endif
#define MOUSEKEY_TIME_TO_MAX 64

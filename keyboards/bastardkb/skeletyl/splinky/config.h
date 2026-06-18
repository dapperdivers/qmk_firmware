// Copyright 2024 Derek Mackley
// Skeletyl with the 0xB2 "Splinky" RP2040 controller (https://github.com/plut0nium/0xB2).
// Pin mapping mirrors bastardkb's splinky_3 board (v3); for a Splinky v2, change
// the col-1 pin in keyboard.json from GP21 to GP15.

#pragma once

// This unit is wired with the LEFT half as the USB master.
#define MASTER_LEFT

// RP2040 UF2 bootloader: double-tap the reset button to enter BOOTSEL.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

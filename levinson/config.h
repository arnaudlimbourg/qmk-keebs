#pragma once

// how long before a tap becomes a hold
#undef TAPPING_TERM
#define TAPPING_TERM 100

// makes tap and hold keys work better for fast typers who don't want
// tapping term set above 500
#define PERMISSIVE_HOLD

// tap anyway, even after TAPPING_TERM, if there was no other key
// interruption between press and release
#define RETRO_TAPPING

// how many taps before triggering the toggle
#undef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2

// Use serial comms for split keyboard
// DO NOT enable USE_IDC - board will not respond.
#define USE_SERIAL
//#define USE_I2C

#ifdef RGBLIGHT_ENABLE

   // Enable animations. +5500 bytes
   #define RGBLIGHT_ANIMATIONS

   // Map my custom number of LED's
   #undef RGBLED_NUM
   #define RGBLED_NUM 16
   #define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8 } // When changed, BE SURE to flash EEPROM on both halves and clear it.

   // DO NOT USE RGBLED_SPLIT - the slave board will stop responding.

   // Turn off RGB when computer sleeps
   #define RGBLIGHT_SLEEP

   // custom colors
   #define RGB_CLEAR 0x00, 0x00, 0x00

   // MOD indicators
   #define SHFT_LED1 7
   #define GUI_LED1 8

#endif

#ifdef AUDIO_ENABLE
   #define QMK_SPEAKER C6
   #define C6_AUDIO
   #define NO_MUSIC_MODE // Save 2000 bytes
#endif

// Save 200 bytes on unused keycodes
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Enable HID_listen commands.
#define NO_DEBUG
#undef NO_PRINT
#define USER_PRINT

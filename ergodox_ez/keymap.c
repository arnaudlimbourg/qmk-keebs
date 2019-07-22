// Arnaud's French AZERTY version of the default_osx file
#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_french_osx.h"

enum ergodox_layers {
    _BASE, // default layer
    _SYMB, // symbols
    _MDIA, // media keys
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
*/
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_BASE] = LAYOUT_ergodox(  // layer 0 : default
    FR_MINS,           FR_AMP,      FR_EACU,       FR_QUOT, FR_APOS, FR_LPRN, LCTL(LSFT(KC_TAB)),
    KC_TAB,            FR_A,        FR_Z,          KC_E,    KC_R,    KC_T,    MEH_T(KC_DELT),
    LSFT(KC_LGUI),     FR_Q,        KC_S,          KC_D,    KC_F,    KC_G,
    KC_LSFT,           CTL_T(FR_W), KC_X,          KC_C,    KC_V,    KC_B,    GUI_T(KC_ESCAPE),
    LT(_SYMB,FR_UGRV), FR_LESS,     LSFT(KC_LALT), KC_LEFT, KC_RGHT, KC_LALT, KC_LCTRL,
                                                                            KC_HOME,
                                                                            KC_SPC, KC_BSPC, KC_END,

    LCTL(KC_TAB),     FR_SECT, FR_EGRV,     FR_EXLM,            FR_CCED, FR_AGRV,          FR_RPRN,
    KC_HYPR,          KC_Y,    KC_U,        KC_I,               KC_O,    KC_P,             KC_BSLASH,
                      KC_H,    KC_J,        KC_K,               KC_L,    FR_M,             RSFT(KC_RGUI),
    GUI_T(KC_ESCAPE), KC_N,    FR_COMM,     LT(_MDIA, FR_SCLN), FR_COLN, RCTL_T(FR_EQL),   KC_RSFT,
    KC_UP,            KC_DOWN, KC_LBRC,     KC_RBRC,            TT(_SYMB),
    LGUI(KC_SPACE),  KC_RALT,
    KC_PGUP,
    KC_PGDN, KC_TAB, KC_ENT
),

/* Keymap 1: Symbol Layer */
// SYMBOLS
[_SYMB] = LAYOUT_ergodox(
    KC_TRNS,   KC_F1,    KC_F2,           KC_F3,          KC_F4,          KC_F5,    KC_TRNS,
    KC_TRNS,   FR_BSLS,  KC_KP_ASTERISK,  FR_DLR,         FR_LCBR,        FR_RCBR,  TT(_MDIA),
    KC_TRNS,   FR_EQL,   FR_PIPE,         KC_KP_SLASH,    FR_LPRN,        FR_RPRN,
    KC_TRNS,   FR_TILD,  FR_AT,           FR_HASH,        FR_LBRC,        FR_RBRC,  KC_TRNS,
    KC_TRNS,   KC_TRNS,  KC_TRNS,         KC_TRNS,        KC_TRNS,
    RGB_MOD,  RGB_SLD,
    KC_TRNS,  RGB_HUD, RGB_HUI, KC_TRNS,

    KC_TRNS,  KC_F6,          KC_F7,     KC_F8,   KC_F9,     KC_F10,      KC_F11,
    KC_TRNS,  KC_KP_SLASH,    FR_7,      FR_8,    FR_9,      FR_ASTR,     KC_F12,
              FR_MINS,        FR_4,      FR_5,    FR_6,      FR_PLUS,     FR_EQL,
    KC_TRNS,  FR_0,           FR_1,      FR_2,    FR_3,      KC_KP_SLASH, KC_TAB,
                              KC_TRNS,   KC_TRNS, KC_KP_DOT, KC_EQL,      TO(_BASE),
    RGB_TOG,  RGB_SLD, RGB_MOD, RGB_SLD, RGB_VAD, RGB_VAI
),

/* Keymap 2: Media and mouse keys
 */
// MEDIA AND MOUSE
[_MDIA] = LAYOUT_ergodox(
       TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,

       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};

// only runs when when the layer is changed, good for updating LED's and clearing sticky state
uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
    case 0:
      break;
    case 1:
      clear_mods();
      ergodox_right_led_1_on();
      break;
    case 2:
      clear_mods();
      ergodox_right_led_2_on();
      break;
    case 3:
      clear_mods();
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

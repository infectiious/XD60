#include "xd60.h"
#include "action_layer.h"
#include "backlight.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer
* .------.------.------.------.------.------.------.------.------.------.------.------.------.------.
* | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |  =   | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [   |   ]  |   \  |
* '--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'
*    | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |Enter |
*    '--.------.------.------.------.------.------.------.------.------.------.------.------.---'
*       | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
*       '---.------.------.------.--------------------.------.------.------.------.--'------'
*           | Ctrl | GUI  | Alt  |        Space       | Alt  | GUI  |  Fn  | Ctrl |
*           '------'------'------'--------------------'------'------'------'------'
*/

  // 0: Base Layer
  KEYMAP(
      KC_ESC,   KC_1,     KC_2,     KC_3,      KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,      KC_0,     KC_MINS,   KC_EQL,  KC_BSPC,  KC_NO,    \
      KC_TAB,   KC_Q,     KC_W,     KC_E,      KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,     KC_LBRC,   KC_RBRC,           KC_BSLS,   \
      KC_CAPS,  KC_A,     KC_S,     KC_D,      KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,  KC_QUOT,   KC_NO,             KC_ENT,    \
      KC_LSFT,  KC_NO,    KC_Z,     KC_X,      KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,   KC_DOT,   KC_SLSH,   KC_NO,   KC_RSFT,  KC_NO,      \
      KC_LCTL,  KC_LGUI,  KC_LALT,			           KC_SPC, 			            KC_RALT,  KC_RGUI,   KC_NO,   F(0),     KC_RCTL),

/* Function Layer
* .------.------.------.------.------.------.------.------.------.------.------.------.------.------.
* |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12  | Del |
* |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
* | Step |BLTog |  Up  |BLMod |BLHui |BLHud |BLSatU|BLSatD|BLVaU |BLVaD |  PScr | SLck |Pause|      |
* '--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'
*    |      | Left | Down |Right |      |      |      | Left | Down |  Up  | Right|      |Enter |
*    '--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'--.---'
*       | Shift| VolU | VolD |      |      |      |      |      |  «   |   »  |      | PgUP |
*       '---.------.--'---.--'---.--'------'------'---.--'---.--'---.--'---.--'---.--'------'
*           | Ctrl | GUI  | Alt  |     Pause/Play     | Home | End  |  Fn  | PgDn |
*           '------'------'------'--------------------'------'------'------'------'
*/

  // 1: Function Layer
  KEYMAP(
      KC_GRV,   KC_F1,    KC_F2,    KC_F3,     KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_NO,    \
      BL_STEP,  RGB_TOG,  KC_UP,    RGB_MOD,   RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,   KC_PSCR,  KC_SLCK,  KC_PAUS,            KC_NO,    \
      KC_NO,    KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_NO,    KC_NO,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  KC_NO,    KC_NO,    KC_NO,              KC_ENT,    \
      KC_LSFT,  KC_NO,    KC_VOLU,  KC_VOLD,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_MPRV,   KC_MNXT,  KC_NO,    KC_NO,    KC_PGUP,  KC_NO,      \
      KC_LCTL,  KC_LGUI,  KC_LALT,                                 KC_MPLY,                                 KC_HOME,  KC_END,   KC_NO,    F(0),     KC_PGDN),

};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
	register_code(KC_RSFT);
	backlight_step(); 
	}
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};


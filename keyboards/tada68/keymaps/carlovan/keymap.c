#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _RQW 2
#define _LQW 3

enum custom_keycodes {
  EMAIL = SAFE_RANGE
};

void disable_layer(const int l) {
    layer_state &= ~(1<<l);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            // Email macro
            case EMAIL:
                SEND_STRING("giulio.carlassare@gmail.com");
                break;

            // Left shift has just been pressed. Kill all left alphas.
            case KC_LSFT:
                layer_state |= 1<<_LQW;
                break;

            // Right shift has just been pressed. Kill all right alphas.
            case KC_RSFT:
                layer_state |= 1<<_RQW;
                break;

            // Punitive layers can't be cancelled by a no-op key. This prevents
            // user from hitting key again to get the letter.
            case KC_NO:
                break;

            // Undo any punitive layers once any other key has been pressed.
            // This allows user to enter a sequence of shifted keys without
            // having to alternate between left and right shift. For example,
            // when typing "UPS". Too short to warrant CAPS LOCK use, but would
            // require using both shift keys if we didn't remove the blockade
            // on the "wrong" side of the board.
            default:
                disable_layer(_LQW);
                disable_layer(_RQW);
        }

    } else {

        switch (keycode) {
            case KC_NO:
                break;

            // Make sure punitive layers are released if user pressed a
            // shift key, but changed their mind and decided to not shift
            // anything at all
            default:
                disable_layer(_LQW);
                disable_layer(_RQW);

        }
	}
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |Hme |
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_ansi(
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_HOME,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_END, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                        KC_RALT,MO(_FL),KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |PrScr|PgUp|
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|  |EMAIL|  |   |   |   |   |   |        |PgDn|
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|   |VU-|VU+|MUT|   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_ansi(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS ,  \
  _______,_______, KC_UP,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, KC_PSCREEN,KC_PGUP, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,EMAIL,_______,_______,_______,_______,_______,_______,        _______,KC_PGDN, \
  _______,_______,_______,BL_DEC, BL_TOGG,BL_INC, _______,KC_VOLD,KC_VOLU,KC_MUTE,_______,KC_BTN1, KC_MS_U, KC_BTN2, \
  _______,_______,_______,                 _______,               _______,_______,_______,KC_MS_L,KC_MS_D, KC_MS_R),
 
[_RQW] = LAYOUT_ansi(
  _______,    _______,   _______,   _______,   _______,   _______,   _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, _______,KC_NO, \
  _______,  _______,   _______,   _______,   _______,   _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,KC_NO,_______, \
  _______, _______,   _______,   _______,   _______,   _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,KC_NO,         _______,_______,  \
  _______,         _______,   _______,   _______,   _______,   _______,   KC_NO,   KC_NO,   KC_NO,KC_NO, KC_NO,   _______,_______,_______, \
  _______, _______,_______,                _______,                        _______,_______,_______, _______,_______,_______),

[_LQW] = LAYOUT_ansi(
  _______,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,   _______,   _______,   _______,   _______, _______, _______,_______, \
  _______,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,   _______,   _______,   _______,   _______,   _______, _______,_______,_______, \
  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,   _______,   _______,   _______,   _______,_______,         _______,_______,  \
  _______,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,   _______,   _______,   _______,_______, _______,   _______,_______,_______, \
  _______, _______,_______,                _______,                        _______,_______,_______, _______,_______,_______),
};


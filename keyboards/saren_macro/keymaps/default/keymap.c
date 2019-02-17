#include "saren_macro.h"

#define BASE 0
#define BASE2 1
#define ARROWS 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = KEYMAP(
		KC_F2, KC_F4, KC_F5, 
		LT(ARROWS, KC_F6), KC_F7, LT(BASE2, KC_F8)),

	[BASE2] = KEYMAP(
		KC_F9, KC_F11, KC_F12, 
		KC_F14, KC_F17, KC_NO),

	[ARROWS] = KEYMAP(
		KC_LEFT, KC_UP, KC_RIGHT, 
		KC_NO, KC_DOWN, KC_ENT),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

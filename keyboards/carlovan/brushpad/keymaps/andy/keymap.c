/* Copyright 2019 Carlovan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum custom_keycodes {
	ENC_CLK = SAFE_RANGE, // Encoder click
};

bool changing_layer = false;

#define _BASE 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
	ENC_CLK, LCMD(KC_D), LCMD(KC_Q), LCMD(KC_S), KC_SLEP, \
	KC_W, LCMD(KC_A), LCMD(KC_MINUS), SCMD(KC_EQUAL), SCMD(KC_Z), \
	LCMD(KC_X), LCMD(KC_C), LCMD(KC_V), LCMD(KC_G), LCMD(KC_Z) \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) {
		if (clockwise) {
			tap_code(KC__VOLUP);
		} else {
			tap_code(KC__VOLDOWN);
		}
	}
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

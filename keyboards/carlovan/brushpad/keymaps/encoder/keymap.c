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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    KC_NLCK, KC_P7, KC_P8, KC_P9, KC_NO, \
    KC_NO, KC_P6, KC_P5, KC_P4, KC_NO, \
    KC_P0, KC_P1, KC_P2, KC_P3, KC_NO \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) {
		if (clockwise) {
			register_code(KC_LCTRL);
			tap_code(KC_Y);
			unregister_code(KC_LCTRL);
		} else {
			register_code(KC_LCTRL);
			tap_code(KC_Z);
			unregister_code(KC_LCTRL);
		}
	}
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

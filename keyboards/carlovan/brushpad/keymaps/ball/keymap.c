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
uint8_t cur_layer = 0;

#define _BASE 0
#define _FL 1
#define _LAYERS 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
	ENC_CLK, KC_F13, KC_F14, KC_F15, KC_F16, \
	KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, \
	KC_F22, KC_F23, KC_F24, LCTL(KC_F13), LCTL(KC_F14) \
  ),
  [_FL] = LAYOUT(
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
	KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, \
	KC_TRANSPARENT, KC_TRANSPARENT, \
	KC_F22, KC_F5, KC_F7, KC_F6, KC_F9 \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) {
		if (clockwise) {
			cur_layer++;
			cur_layer %= _LAYERS;
		} else {
			cur_layer--;
			if (cur_layer > _LAYERS)
				cur_layer = _LAYERS - 1;
		}

		layer_clear();
		layer_on(cur_layer);
	}
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

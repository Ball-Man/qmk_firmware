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
	ENC_CLK = SAFE_RANGE,
};

bool changing_layer = false;

#define _ARROWS 0
#define _NUMPAD 1

#define _LAST _NUMPAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ARROWS] = LAYOUT(
	ENC_CLK, KC_NO, KC_UP, KC_NO, KC_NO, \
	KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, \
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO \
  ),
  [_NUMPAD] = LAYOUT(
	KC_TRNS, KC_P7, KC_P8, KC_P9, KC_NO, \
	KC_NLCK, KC_P6, KC_P5, KC_P4, KC_NO, \
	KC_P0, KC_P1, KC_P2, KC_P3, KC_NO \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (keycode == ENC_CLK && record->event.pressed == false) {
		changing_layer = !changing_layer;

		if(changing_layer) {
			rgblight_enable_noeeprom();
			rgblight_mode_noeeprom(RGBLIGHT_MODE_ALTERNATING);
		} else {
			rgblight_disable_noeeprom();
		}
	}
	return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) {
		if(changing_layer) {
			if(layer_state == 0) {
				layer_move(0);
			}
			if(clockwise) {
				if(layer_state_is(0)) {
					layer_move(_LAST);
				} else {
					layer_state_set(layer_state >> 1);
				}
			} else {
				if(layer_state_is(_LAST)) {
					layer_move(0);
				} else {
					layer_state_set(layer_state << 1);
				}
			}
		}
	}
}

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
	case _ARROWS:
		rgblight_sethsv_noeeprom(HSV_RED);
		break;
	case _NUMPAD:
		rgblight_sethsv_noeeprom(HSV_GREEN);
		break;
	}
	return state;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

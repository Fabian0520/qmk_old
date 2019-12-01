/* Copyright 2019 Stanrc85
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
#include "rgb_color_sets.h"

enum layers {
  _BASE,
  _MOV,
  _RGB,
  _LAYER,
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  MOV,
  RGB_SET,
  LAYER,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_7    , KC_8    , KC_9    , \
		KC_4    , KC_5    , KC_6    , \
		KC_1    , KC_2    , KC_3    , \
		LT(_LAYER,KC_0)   , KC_DOT    , KC_COMM    \
	),
 
	[_MOV] = LAYOUT(
		KC_PGUP , KC_UP   , KC_HOME , \
		KC_LEFT , KC_DOWN , KC_RGHT , \
		KC_PGDN , KC_NO   , KC_END  , \
		KC_TRNS , KC_TRNS , KC_ENT    \
	),
 
	[_RGB] = LAYOUT(
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS , KC_TRNS  , \
		KC_TRNS , RGB_TOG , KC_TRNS    \
	),
  
	[_LAYER] = LAYOUT(
		KC_NO   , KC_NO   , KC_NO   , \
		KC_NO   , KC_NO   , KC_NO   , \
		BASE    , MOV     , KC_NO   , \
		KC_TRNS , RGB_SET , KC_NO      \
	)
 };

void keyboard_post_init_user(void) {
  // Call the post init code.
  #ifdef UNDERGLOW_ENABLE
      set_single_persistent_default_layer(_BASE);
      rgblight_enable(); // enables Rgb, without saving settings
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv(HSV_TEAL);
  #endif
  //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+4);
} 

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
// ------------------- Layer Code --------------------------------
    case BASE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE);
        #ifdef UNDERGLOW_ENABLE
             rgblight_sethsv(HSV_TEAL);
        #endif
      }
      return false;
      break;
    case RGB_SET:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_RGB);
        #ifdef UNDERGLOW_ENABLE
            test(); //aus rgb_color_sets.h
        #endif
        //rgblight_sethsv(255,255*0.75,255*0.89);
      }
      return false;
      break;
    case MOV:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MOV);
        #ifdef UNDERGLOW_ENABLE
            rgblight_sethsv(HSV_GOLD);
        #endif
      }
      return false;
      break;
    case LAYER:
      if (record->event.pressed) {
        layer_on(_LAYER);
        //update_tri_layer(_MOV, _NUM, _ADJUST);
      } else {
        layer_off(_LAYER);
        //update_tri_layer(_MOV, _NUM, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}

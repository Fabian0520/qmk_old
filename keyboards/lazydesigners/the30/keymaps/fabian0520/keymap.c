#include "fabian0520.h"
/* Copyright 2019 Erovia
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

/* Press for Enter, hold for FN layer */
#define FN_ENT LT(_FN, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 *  ,-------------------------------------------------.
 *  | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  |
 *  |-------------------------------------------------|
 *  | A  | S  | D  | F  | G  | H  | J  | K  | L  |ENT |
 *  |-------------------------------------------------|
 *  | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |
 *  `-------------------------------------------------'
 */
    [_COLEMAK] = LAYOUT_ortho_3x10(
        TD(TD_Q_ESC),  KC_W   ,   KC_F  ,   KC_P   ,   KC_G   ,   KC_J   ,   KC_L   ,   KC_U   ,   KC_Y  , KC_BSPC ,
        MT(MOD_LSFT, KC_A)   ,  KC_R   ,   KC_S  ,   KC_T   ,   KC_D   ,   KC_H   ,   KC_N   ,   KC_E   ,   KC_I  ,  MT(MOD_RSFT, KC_O)   ,
        KC_Z   ,  KC_X   ,   KC_C  ,   KC_V   ,   KC_B   ,   KC_K   ,   KC_M   ,  KC_COMM ,  KC_DOT , TD(TD_SPC_ENT)
    ),
/*
 *  ,-------------------------------------------------.
 *  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  |
 *  |-------------------------------------------------|
 *  |    |    |    |    |    |    |    |    |    |    |
 *  |-------------------------------------------------|
 *  |RST |ERST|    |    |SPC |    |    |    |    |    |
 *  `-------------------------------------------------'
 */
    /*
    [_FN] = LAYOUT_ortho_3x10(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RESET,   EEP_RST, _______, _______, KC_SPC,  _______, _______, _______, _______, _______
    ),
*/
};

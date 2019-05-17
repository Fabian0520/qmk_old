/* Copyright 2018 REPLACE_WITH_YOUR_NAME
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
#include "fabi_keypad.h"
//#include "is31fl3733.h"

void matrix_init_kb(void) {
  setPinOutput(A13);
  writePinHigh(A13);
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	led_set_user(usb_led);
}

// const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    /*{0, L_1,    K_1,    J_1}, //MX1
    {0, I_1,    H_1,    G_1}, //MX2
    {0, F_1,    E_1,    D_1}, //MX3
    {0, C_1,    B_1,    A_1}, //MX4
    {0, L_2,    K_2,    J_2}, //MX5
    {0, I_2,    H_2,    G_2}, //MX6
    {0, F_2,    E_2,    D_2}, //MX7
    {0, C_2,    B_2,    A_2}, //MX8
    {0, L_3,    K_3,    J_3}, //MX9
    {0, I_3,    H_3,    G_3}, //MX30
    {0, F_3,    E_3,    D_3}, //MX33
    {0, C_3,    B_3,    A_3}, //MX32
    {0, L_4,    K_4,    J_4}, //MX43
    {0, I_4,    H_4,    G_4}, //MX44
    {0, F_4,    E_4,    D_4}, //MX45
    {0, C_4,    B_4,    A_4}, //MX46
    {0, L_5,    K_5,    J_5}, //MX57
    {0, I_5,    H_5,    G_5}, //MX58
    {0, F_5,    E_5,    D_5},  //MX59
};*/

/*const rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
//
//  MX1,  MX2,  MX3,  MX4, 
//  MX5,  MX6,  MX7,  MX8,
//  MX9, MX10, MX11, MX12,
// MX13, MX14, MX15, MX16,
// MX17, MX18, MX19,  ---,*/
/* {row | col << 4}
 *    |           {x=0..224, y=0..64}
 *    |              |            modifier
 *    |              |         | */
    /*{{0|(0<<4)},    {61.0*0, 21.33*0}, 0}, //MX1
    {{0|(1<<4)},    {61.0*0, 21.33*1}, 0}, //MX2
    {{0|(2<<4)},    {61.0*0, 21.33*2}, 0}, //MX3
    {{0|(3<<4)},    {61.0*0, 21.33*3}, 0}, //MX4
    {{1|(0<<4)},    {61.0*1, 21.33*0}, 0}, //MX5
    {{1|(1<<4)},    {61.0*1, 21.33*1}, 0}, //MX6
    {{1|(2<<4)},    {61.0*1, 21.33*2}, 0}, //MX7
    {{1|(3<<4)},    {61.0*1, 21.33*3}, 0}, //MX8
    {{2|(0<<4)},    {61.0*2, 21.33*0}, 0}, //MX9
    {{2|(1<<4)},    {61.0*2, 21.33*1}, 0}, //MX10
    {{2|(2<<4)},    {61.0*2, 21.33*2}, 0}, //MX11
    {{2|(3<<4)},    {61.0*2, 21.33*3}, 0}, //MX12
    {{3|(0<<4)},    {61.0*3, 21.33*0}, 0}, //MX13
    {{3|(1<<4)},    {61.0*3, 21.33*1}, 0}, //MX14
    {{3|(2<<4)},    {61.0*3, 21.33*2}, 0}, //MX15
    {{3|(3<<4)},    {61.0*3.5, 21.33*2.5}, 0}, //MX16
    {{4|(0<<4)},    {61.0*4, 21.33*0}, 0}, //MX17
    {{4|(1<<4)},    {61.0*4, 21.33*1}, 0}, //MX18
    {{4|(2<<4)},    {61.0*4, 21.33*2}, 0}  //MX19
};*/

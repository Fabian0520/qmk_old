#include "shoto.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_SPC, KC_J, KC_L, KC_U, KC_Y, KC_COLN, KC_NO,
		KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_D, KC_SPC, KC_H, KC_N, KC_E, KC_I, KC_NO  , KC_NO,
		KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO  , KC_SPC, KC_K, KC_M, KC_COMM, KC_DOT, KC_SPC, KC_NO,
		KC_NO, KC_LGUI, KC_LALT, KC_NO, KC_SPC, KC_NO, KC_LGUI, KC_NO)
};
/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}
*/

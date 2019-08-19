#include "satan.h"
#include "quantum.h"
#include "action_layer.h"
//#include "fabian0520.h"


// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
//#define _AL 1

#define _______ KC_TRNS
#define SCRE_UP LGUI(LSFT(LCTL(KC_Q)))
#define SCRE_DN LGUI(LSFT(LCTL(KC_A)))

enum satan_layers {
    _QWERTY,
    _COLEMAK,
    _FUNC1,
    _FUNC2, //Gleicher Layer wie FUNC1. Brauche ich nur um mit beiden Tasten in den ADJUST-Layer zu kommen.
    _ADJUST,
};

enum satan_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    TEST,
    FUNC1,
    FUNC2
};
/*
enum {
    TD_A_CL = 0
};


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_A_CL] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_CAPS)
};
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _QWERTY: (QWERTY Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
       * |-----------------------------------------------------------|
       * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
       * |-----------------------------------------------------------|
       * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
       * |-----------------------------------------------------------|
       * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
       * |-----------------------------------------------------------|
       * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN  |Ctrl |
       * `-----------------------------------------------------------'
       */
    [_QWERTY] = LAYOUT_60_ansi(
      F(0),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
      KC_TAB , KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
      FUNC2  , KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
      KC_LSPO,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSPC, \
      KC_LCTL, KC_LGUI,KC_LALT,      KC_SPC,                                KC_RALT,KC_RGUI, FUNC1 ,KC_RCTL),
    /*
       * ,-----------------------------------------------------------.
       * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
       * |-----------------------------------------------------------|
       * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
       * |-----------------------------------------------------------|
       * |      |   |   |   |   |   |   |   |   |   |   |   |        |
       * |-----------------------------------------------------------|
       * |        |   |   |   |   |   |   |   |   |   |   |          |
       * |-----------------------------------------------------------|
       * |    |    |    |                        |    |    |    |    |
       * `-----------------------------------------------------------'
       */
    [_COLEMAK] = LAYOUT_60_ansi(
       F(0) , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_MINS, KC_EQL, KC_BSPC , \
      KC_TAB, KC_Q  , KC_W  , KC_F  , KC_P  , KC_G  , KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN, KC_LBRC,KC_RBRC ,KC_BSLS , \
      FUNC2 , KC_A  , KC_R  , KC_S  , KC_T  , KC_D  , KC_H  , KC_N  , KC_E  , KC_I  , KC_O  , KC_QUOT,          KC_ENT , \
      KC_LSPO, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  , KC_K  , KC_M  , KC_COMM , KC_DOT , KC_SLSH ,        KC_RSPC , \
      KC_LCTL, KC_LGUI,KC_LALT ,      KC_SPC,                                KC_RALT,KC_RGUI, FUNC1 ,KC_RCTL),

      /* Keymap _FL: Function Layer
       * ,-----------------------------------------------------------.
       * |RST| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |
       * |-----------------------------------------------------------|
       * |     |PUP| UP|PDW|PO1|   | m | m | m |   |VO+|   |   |     |
       * |-----------------------------------------------------------|
       * |      |LFT|DWN|RGT|END|   | m | m | m |   |VO-|   |        |
       * |-----------------------------------------------------------|
       * |        |REV|STP|PLY|FF |   |   |   |   |   |MTE|          |
       * |-----------------------------------------------------------|
       * |    |    |    |                        |    |    |    |    |
       * `-----------------------------------------------------------'
       */
    [_FUNC2] = LAYOUT_60_ansi(
      RESET  , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,KC_DEL , \
      _______,KC_PGUP, KC_UP ,KC_PGDN,KC_HOME,_______,_______, KC_7  , KC_8  , KC_9  ,KC_PMNS,_______,_______,KC_INS , \
      _______,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,_______,_______, KC_4  , KC_5  , KC_6  ,KC_PPLS,_______,        _______, \
      _______,KC_WBAK,KC_WFWD,_______,_______,_______, KC_0  , KC_1  , KC_2  , KC_3  ,_______,_______, \

          _______,_______,_______,                 _______,                       _______,_______,_______, _______),

      /* Keymap _FL: Function Layer
       * ,-----------------------------------------------------------.
       * |RST| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |
       * |-----------------------------------------------------------|
       * |     |PUP| UP|PDW|PO1|   | m | m | m |   |VO+|   |   |     |
       * |-----------------------------------------------------------|
       * |      |LFT|DWN|RGT|END|   | m | m | m |   |VO-|   |        |
       * |-----------------------------------------------------------|
       * |        |REV|STP|PLY|FF |   |   |   |   |   |MTE|          |
       * |-----------------------------------------------------------|
       * |    |    |    |                        |    |    |    |    |
       * `-----------------------------------------------------------'
       */
    [_FUNC1] = LAYOUT_60_ansi(
      RESET  , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,KC_DEL , \
      _______,_______, KC_7  , KC_8  , KC_9  ,_______,_______,KC_BTN1,KC_MS_U,KC_BTN2,KC_WH_U,_______,_______,KC_INS , \
      _______,_______, KC_4  , KC_5  , KC_6  ,_______,_______,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,_______,        _______, \
      _______, KC_0  , KC_1  , KC_2  , KC_3  ,_______,_______,KC_MSTP,KC_MPRV,KC_MNXT,KC_MPLY,_______, \
      _______,_______,_______,                 _______,                       _______,_______,_______, _______),
      /* Keymap _ADJUST: ADJUST Layer
       * ,-----------------------------------------------------------.
       * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
       * |-----------------------------------------------------------|
       * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
       * |-----------------------------------------------------------|
       * |      |   |   |   |   |   |   |   |   |   |   |   |        |
       * |-----------------------------------------------------------|
       * |        |   |   |   |   |   |   |   |   |   |   |          |
       * |-----------------------------------------------------------|
       * |    |    |    |                        |    |    |    |    |
       * `-----------------------------------------------------------'
       */
    [_ADJUST] = LAYOUT_60_ansi(
      KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,KC_MUTE,KC_VOLD,KC_VOLU, KC_NO , \
      KC_NO , QWERTY,COLEMAK, KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,SCRE_DN,SCRE_UP, KC_NO , \
      FUNC2 , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,BL_STEP,         KC_NO , \
      KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,BL_BRTG,BL_DEC ,BL_INC ,BL_TOGG, KC_NO , \
      KC_NO , KC_NO , KC_NO ,                         KC_NO ,                 KC_NO , KC_NO , FUNC1 , KC_NO ),
    };

    enum function_id {
        SHIFT_ESC,
    };

    const uint16_t PROGMEM fn_actions[] = {
      [0]  = ACTION_FUNCTION(SHIFT_ESC),
    };

    void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
      static uint8_t shift_esc_shift_mask;
      switch (id) {
        case SHIFT_ESC:
          shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
          if (record->event.pressed) {
            if (shift_esc_shift_mask) {
              add_key(KC_GRV);
              send_keyboard_report();
            } else {
              add_key(KC_ESC);
              send_keyboard_report();
            }
          } else {
            if (shift_esc_shift_mask) {
              del_key(KC_GRV);
              send_keyboard_report();
            } else {
              del_key(KC_ESC);
              send_keyboard_report();
            }
          }
          break;
      }
    };

    uint32_t layer_state_set_user(uint32_t state) {
      return update_tri_layer_state(state, _FUNC1, _FUNC2, _ADJUST);
    }

    bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
      switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
            //default_layer_set(1UL<<_QWERTY);
            //persistent_default_layer_set(1UL<<_QWERTY);
            //layer_on(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
            //default_layer_set(1UL<<_TEST);
            //persistent_default_layer_set(1UL<<_QWERTY);
            //layer_on(_TEST);
          }
          return false;
          break;
        case FUNC1:
          if (record->event.pressed) {
            layer_on(_FUNC1);
            update_tri_layer(_FUNC1, _FUNC2, _ADJUST);
          } else {
            layer_off(_FUNC1);
            update_tri_layer(_FUNC1, _FUNC2, _ADJUST);
          }
          return false;
          break;
        case FUNC2:
          if (record->event.pressed) {
            layer_on(_FUNC2);
            update_tri_layer(_FUNC1, _FUNC2, _ADJUST);
          } else {
            layer_off(_FUNC2);
            update_tri_layer(_FUNC1, _FUNC2, _ADJUST);
          }
          return false;
          break;
      }
      return true;
    }

    /*
       * ,-----------------------------------------------------------.
       * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
       * |-----------------------------------------------------------|
       * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
       * |-----------------------------------------------------------|
       * |      |   |   |   |   |   |   |   |   |   |   |   |        |
       * |-----------------------------------------------------------|
       * |        |   |   |   |   |   |   |   |   |   |   |          |
       * |-----------------------------------------------------------|
       * |    |    |    |                        |    |    |    |    |
       * `-----------------------------------------------------------'
       */
/*[_ADJUST] = LAYOUT_60_ansi(
 _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
 _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
 _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______, \
 _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
 _______,_______,_______,                        _______,                _______,_______,_______,_______),
 */

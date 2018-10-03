#include "levinson.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "quantum.h"
extern keymap_config_t keymap_config;

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define i3_NAVIGATION_ENABLE
#define CUSTOM_SHIFT_ENABLE
#define UNDERGLOW_ENABLE
#define ESC_CAPS_ENABLE

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  ADJUST,
  TMP,
  SYM,
  NUM,
  MOV,
  i3_S_1,
  i3_S_2,
  i3_S_3,
  i3_S_4,
  i3_S_5,
  i3_S_6,
  i3_S_7,
  i3_S_8,
  i3_S_9,
  MY_COMM,
  MY_DOT,
  SHIFT,
};


enum planck_layers {
    _COLEMAK,
    _QWERTY,
    _NUM,
    _SYM, //Gleicher Layer wie FUNC1. Brauche ich nur um mit beiden Tasten in den ADJUST-Layer zu kommen.
    _MOV,
    _ADJUST,
    _TMP,
};


// Fillers to make layering more clear
#define OSM_ALT      OSM(MOD_LALT)
#define OSM_GUI      OSM(MOD_LGUI)
#define OSM_CTL      OSM(MOD_LCTL)
#define TD_BS        TD(TD_BS_OC)
#define TD_BR        TD(TD_BR_OC)
#define TD_BC        TD(TD_BC_OC)
#define TD_BA        TD(TD_BA_OC)
#define TD_SFT_CAP   TD(TD_SFT_CAPS)
#define SCRE_UP      LGUI(LSFT(LCTL(KC_Q)))
#define SCRE_DN      LGUI(LSFT(LCTL(KC_A)))
#define __________   KC_TRNS
#define XXXXXXXXXX   KC_NO

void TD_BS_OC_f(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_LBRC);
    } else {
        register_code (KC_LBRC);
        register_code (KC_RBRC);
        register_code (KC_LEFT);
    }
}

void TD_BS_OC_r (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_LBRC);
    } else {
        unregister_code (KC_LBRC);
        unregister_code (KC_RBRC);
        unregister_code (KC_LEFT);
    }
}
void TD_BR_OC_f(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_LSFT);
        register_code (KC_9);
    } else {
        register_code (KC_LSFT);
        register_code (KC_9);
        register_code (KC_0);
        unregister_code (KC_LSFT);
        register_code (KC_LEFT);
    }
}

void TD_BR_OC_r (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_LSFT);
        unregister_code (KC_9);
    } else {
        unregister_code (KC_9);
        unregister_code (KC_0);
        unregister_code (KC_LEFT);
    }
}
void TD_BC_OC_f(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_LSFT);
        register_code (KC_LBRC);
    } else {
        register_code (KC_LSFT);
        register_code (KC_LBRC);
        register_code (KC_RBRC);
        unregister_code (KC_LSFT);
        register_code (KC_LEFT);
    }
}

void TD_BC_OC_r (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_LSFT);
        unregister_code (KC_LBRC);
    } else {
        unregister_code (KC_LBRC);
        unregister_code (KC_RBRC);
        unregister_code (KC_LEFT);
    }
}
void TD_BA_OC_f(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_LSFT);
        register_code (KC_COMM);
    } else {
        register_code (KC_LSFT);
        register_code (KC_COMM);
        register_code (KC_DOT);
        unregister_code (KC_LSFT);
        register_code (KC_LEFT);
    }
}

void TD_BA_OC_r (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_LSFT);
        unregister_code (KC_COMM);
    } else {
        unregister_code (KC_COMM);
        unregister_code (KC_DOT);
        unregister_code (KC_LEFT);
    }
}
//Tap Dance Declarations
enum {
  TD_SFT_CAPS = 0,
  TD_BS_OC = 1,
  TD_BR_OC = 2,
  TD_BC_OC = 3,
  TD_BA_OC = 4,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for one shot SPACE, twice for Caps Lock
  [TD_SFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TD_BS_OC]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL , TD_BS_OC_f , TD_BS_OC_r),
  [TD_BR_OC]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL , TD_BR_OC_f , TD_BR_OC_r),
  [TD_BC_OC]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL , TD_BC_OC_f , TD_BC_OC_r),
  [TD_BA_OC]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL , TD_BA_OC_f , TD_BA_OC_r),
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //  was fuer die Umlate ueberlegen .....
    
/* Colemak
 * ,-----------------------------------------. ,-----------------------------------------.
 * | ESC  |  Q   |  W   |  F   |  P   |  G   | |  J   |  L   |  U   |  Y   |  ;   | BSPC |
 * |-------------+------+------+------+------| |------+------+------+------+------+------|
 * | TAB  |  A   |  R   |  S   |  T   |  D   | |  H   |  N   |  E   |  I   |  O   | ENTER|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | LSFT |  Z   |  X   |  C   |  V   |  B   | |  K   |  M   |  ,/! |  ./? |  '   |SFT/CP| 
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | LCTL | LGUI | LALT | _SYM | _NUM | SPACE| | SPACE| _MOV | _TMP | RALT | RGUI | RCTL |
 * `-----------------------------------------' `-----------------------------------------'
 */

[_COLEMAK] = LAYOUT_ortho_4x12( \
   KC_ESC ,  KC_Q   ,  KC_W   ,   KC_F   ,   KC_P   ,   KC_G   ,   KC_J   ,   KC_L   ,   KC_U   ,   KC_Y   , KC_SCLN  , KC_BSPC ,\
   KC_TAB ,  KC_A   ,  KC_R   ,   KC_S   ,   KC_T   ,   KC_D   ,   KC_H   ,   KC_N   ,   KC_E   ,   KC_I   ,  KC_O    , KC_ENT  ,\
   KC_LSFT,  KC_Z   ,  KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,   KC_K   ,   KC_M   ,  MY_COMM ,  MY_DOT  , KC_QUOT  , TD_SFT_CAP ,\
  OSM_CTL , OSM_GUI , OSM_ALT  ,  SYM    ,   NUM    ,  KC_SPC  ,  KC_SPC  ,   MOV    ,  TMP     , KC_RALT  ,  KC_RGUI , KC_RCTL   \
 ), 

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * | ESC  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   | BSPC |
 * |-------------+------+------+------+------| |------+------+------+------+------+------|
 * | TAB  |  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |  L   |  ;   | ENTER|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | LSFT |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,/! |  ./? |  '   |SFT/CP| 
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | LCTL | LGUI | LALT | _SYM | _NUM | SPACE| | SPACE| _MOV | _TMP | RALT | RGUI | RCTL |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
   KC_ESC ,  KC_Q   ,  KC_W   ,   KC_E   ,   KC_R   ,   KC_T   ,   KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   , KC_P     , KC_BSPC ,\
   KC_TAB ,  KC_A   ,  KC_S   ,   KC_D   ,   KC_F   ,   KC_G   ,   KC_H   ,   KC_J   ,   KC_K   ,   KC_L   , KC_SCLN  , KC_ENT  ,\
   KC_LSFT,  KC_Z   ,  KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,   KC_N   ,   KC_M   ,  MY_COMM ,  MY_DOT  , KC_QUOT  , TD_SFT_CAP ,\
  OSM_CTL , OSM_GUI , OSM_ALT ,   SYM    , NUM      ,  KC_SPC  ,  KC_SPC  ,   MOV    ,  TMP     , KC_RALT  ,  KC_RGUI , KC_RCTL   \
 ), 

/* TMP
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_TMP] =LAYOUT_ortho_4x12( \
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  ,\
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  ,\
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  ,\
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  \
 ), 

/* NUM
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |  /   |  7   |  8   |  9   |  *   |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  &   |  ^   |  %   |   $  |  _   | |  ,   |  4   |  5   |  6   |  +   |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  ?   |  #   |  @   |   !  |      | |  .   |  1   |  2   |  3   |  -   |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |  0   |  =   |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */

[_NUM] =LAYOUT_ortho_4x12( \
  KC_TRNS ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   , KC_SLASH ,   KC_7   ,   KC_8   ,   KC_9   ,  KC_ASTR , KC_TRNS ,\
  KC_TRNS ,  S(KC_7) ,  S(KC_6) ,  S(KC_5) ,  S(KC_4) ,S(KC_MINS),  KC_COMM ,   KC_4   ,   KC_5   ,   KC_6   ,  KC_PLUS , KC_TRNS , \
  KC_TRNS ,S(KC_SLSH),  S(KC_3) ,  S(KC_2) , S(KC_1)  ,  KC_NO   ,   KC_DOT ,   KC_1   ,   KC_2   ,   KC_3   , KC_MINUS , KC_TRNS , \
  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,   KC_0   , KC_EQUAL , KC_TRNS  ,  KC_TRNS ,  KC_TRNS  \
 ), 

/* SYM
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      | F12  | F11  | F10  |  F9  |      | |  +   |   [  |   ]  |  <   |  >   |      |
 * |-------------+------+------+------+------| |------+------+------+------+------|------|
 * |      |  F8  |  F7  |  F6  |  F5  |      | |  -   |   (  |   )  |  |   |  \   |      |
 * |-------------+------+------+------+------| |------+------+------+------+------|------|
 * |      |  F4  |  F3  |  F2  |  F1  |      | |  =   |   {  |   }  |  ?   |  `   |      |
 * |-------------+------+------+------+------| |------+------+------+------+------|------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_SYM] =LAYOUT_ortho_4x12( \
 KC_TRNS ,  KC_F12   , KC_F11   , KC_F10   , KC_F9    ,  KC_NO   , KC_PLUS  ,   TD_BS    , KC_RBRC  ,  TD_BA   ,  KC_GT   ,  KC_DEL  , \
 KC_TRNS ,  KC_F8    , KC_F7    , KC_F6    , KC_F5    ,  KC_NO   , KC_MINUS ,   TD_BR    , KC_RPRN  ,  TD_BC   , KC_RCBR  , KC_TRNS , \
 KC_TRNS ,  KC_F4    , KC_F3    , KC_F2    , KC_F1    , KC_NO    , KC_EQUAL ,  KC_PIPE   ,  KC_BSLS ,  KC_QUES ,  KC_GRAVE, KC_TRNS , \
 KC_TRNS ,  KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,  KC_TRNS , KC_TRNS  , KC_TRNS    , KC_TRNS  ,  KC_TRNS ,  KC_TRNS  \
 ), 

/* MOV
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_MOV] =LAYOUT_ortho_4x12( \
  KC_TRNS ,  KC_PGUP ,  KC_HOME ,  KC_UP   ,  KC_END  ,  KC_NO   ,  KC_NO   ,  i3_S_7  ,  i3_S_8  ,  i3_S_9  ,  KC_NO   , KC_TRNS  ,\
  KC_TRNS ,  KC_PGDN ,  KC_LEFT ,  KC_DOWN ,  KC_RGHT ,  KC_NO   ,  KC_NO   ,  i3_S_4  ,  i3_S_5  ,  i3_S_6  ,  KC_NO   , KC_TRNS  ,\
  KC_TRNS ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  i3_S_1  ,  i3_S_2  ,  i3_S_3  ,  KC_NO   , KC_TRNS  ,\
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS \
 ), 

/* ADJUST
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] =LAYOUT_ortho_4x12( \
  SCRE_UP ,  QWERTY  ,  COLEMAK ,   KC_NO  ,   KC_NO  ,   KC_NO  ,  RGB_TOG ,  RGB_HUI ,  RGB_SAI ,  RGB_VAI ,   KC_NO  ,  KC_VOLU ,\
  SCRE_DN ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,  RGB_M_B ,  RGB_HUD ,  RGB_SAD ,  RGB_VAD ,   KC_NO  ,  KC_VOLD ,\
   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,  RGB_M_K ,  RGB_M_P ,  RGB_M_R , RGB_M_SW ,   KC_NO  ,  KC_MUTE ,\
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  \
 ), 
};

bool isMyShift = false; // This is the flag we'll use to keep track of when shift is PHYSICALLY pressed/released
uint16_t my_kc = KC_NO; // Always KC_NO or whichever custom keycode (or its shifted partner) was most recently pressed
bool isCaps = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef i3_NAVIGATION_ENABLE
        static uint8_t shift_esc_shift_mask;
    #endif
/*  
    if (record->event.pressed){
            if (isCaps) {
        if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK) ){
                rgblight_setrgb_at(255,0,0,0);
                isCaps = !isCaps;
            }
            } else {
                rgblight_setrgb_at(0,255,0,0);
                isCaps = !isCaps;
            }
        }
*/
  switch (keycode) {
    #ifdef ESC_CAPS_ENABLE
        case KC_ESC:
            if (record->event.pressed) {
                register_code(KC_ESC);
            if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK) ){
                register_code(KC_CAPS);
                }
            } else {
                unregister_code(KC_ESC);
                unregister_code(KC_CAPS);
            }
            return false;
            break;
    #endif
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
        #ifdef UNDERGLOW_ENABLE
             rgblight_sethsv(180,255,255);
        #endif
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
        #ifdef UNDERGLOW_ENABLE
            rgblight_sethsv(40,255,255);
        #endif
      }
      return false;
      break;
    case NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
      } else {
        layer_off(_NUM);
      }
      return false;
      break;
    case MOV:
      if (record->event.pressed) {
        layer_on(_MOV);
      } else {
        layer_off(_MOV);
      }
      return false;
      break;
     case TMP:
      if (record->event.pressed) {
        layer_on(_TMP);
        update_tri_layer(_TMP, _SYM, _ADJUST);
      } else {
        layer_off(_TMP);
        update_tri_layer(_TMP, _SYM, _ADJUST);
      }
      return false;
      break;
     case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
        update_tri_layer(_TMP, _SYM, _ADJUST);
      } else {
        layer_off(_SYM);
        update_tri_layer(_TMP, _SYM, _ADJUST);
      }
      return false;
      break;
     case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    //------------------------------------------------------
    #ifdef i3_NAVIGATION_ENABLE
        case i3_S_1:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                SEND_STRING(SS_LSFT(SS_LGUI("1")));
                } else {
                SEND_STRING(SS_LGUI("1"));
                }
            }
            return false;
            break;
        case i3_S_2:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                SEND_STRING(SS_LSFT(SS_LGUI("2")));
                } else {
                SEND_STRING(SS_LGUI("2"));
                }
            }
            return false;
            break;
        case i3_S_3:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                SEND_STRING(SS_LSFT(SS_LGUI("3")));
                } else {
                SEND_STRING(SS_LGUI("3"));
                }
            }
            return false;
            break;
        case i3_S_4:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                SEND_STRING(SS_LSFT(SS_LGUI("4")));
                } else {
                SEND_STRING(SS_LGUI("4"));
                }
            }
            return false;
            break;
        case i3_S_5:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                SEND_STRING(SS_LSFT(SS_LGUI("5")));
                } else {
                SEND_STRING(SS_LGUI("5"));
                }
            }
            return false;
            break;
        case i3_S_6:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                SEND_STRING(SS_LSFT(SS_LGUI("6")));
                } else {
                SEND_STRING(SS_LGUI("6"));
                }
            }
            return false;
            break;
        case i3_S_7:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                SEND_STRING(SS_LSFT(SS_LGUI("7")));
                } else {
                SEND_STRING(SS_LGUI("7"));
                }
            }
            return false;
            break;
        case i3_S_8:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                SEND_STRING(SS_LSFT(SS_LGUI("8")));
                } else {
                SEND_STRING(SS_LGUI("8"));
                }
            }
            return false;
            break;
        case i3_S_9:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                SEND_STRING(SS_LSFT(SS_LGUI("9")));
                } else {
                SEND_STRING(SS_LGUI("9"));
                }
            }
            return false;
            break;
            return true;
        #endif
        #ifdef CUSTOM_SHIFT_ENABLE
        /* First, Shift needs to be set up to handle the new keys properly */
        case KC_LSFT: { // Adjust shift behavior to accomodate MY_COMM/SLSH/DOT/QUES
          if (record->event.pressed) {
            isMyShift = true;  // Set flag true when shift is pressed
            unregister_code(my_kc); // Unregister my_kc so e.g. you don't start typing "<" if you were holding ","
            switch (my_kc) {
              case KC_COMM: { // If KC_COMM was registered, we want it to become KC_SCLN instead 
                my_kc = KC_SLSH;
                break;
              }
              case KC_DOT: { // Etc
                register_code(KC_LSFT); // Can misfire as semicolon without this even tho KC_COLN is already S(KC_SCLN)
                my_kc = KC_GRV;
                break;
              }
              default: {
                register_code(KC_LSFT); // Normally, we want shift to just act as normal shift
                break;
              }
            }
          register_code(my_kc); // Re-trigger my_kc after shifting. If it was KC_NO then nothing happens, as we want
          }
          else { 
            isMyShift = false; // Set flag false on release of shift key 
            unregister_code(my_kc); // Revert to lowercase. Again, if a custom key wasn't active, my_kc just stays as KC_NO
            switch (my_kc) {
              case KC_SLSH: {
                my_kc = KC_COMM;
                break;
              }
              case KC_GRV: {
                unregister_code(KC_LSFT);
                my_kc = KC_DOT;
                break;
              }
              default: {
                unregister_code(KC_LSFT); // If no custom key was being held, just unregister shift
                break;
              }
            }
          register_code(my_kc); // And retrigger the correct keycode (or KC_NO)
          }
        return false;
        }
      
        /* NEXT, define the custom keycodes. Comma and slash are copypaste since they're both lowercase/lowercase. */
        case MY_COMM: { // Comma -> Slash
          if (record->event.pressed) {
            if (isMyShift) { // Check to see if shift has been physically pressed 
              unregister_code(KC_LSFT); // Need to change my_kc before registering. Also keeps it one custom key at a time 
              my_kc = KC_SLSH;
            }
            else {
              my_kc = KC_COMM;
            }
            register_code(my_kc);
          }
          else {
            unregister_code(my_kc);
            my_kc = KC_NO; // IMPORTANT: setting my_kc to KC_NO on release keeps everything sane
            if (isMyShift) { // If shift is still down on release, we want to reregister it so the next keypress is correct
              register_code(KC_LSFT);
            }
          }
        return false; 
        }
        
       case MY_DOT: { // Dot -> GRV (This is different because Colon is a shifted keycode S(KC_SCLN) )
          if (record->event.pressed) {
            if (isMyShift) {
              my_kc = KC_GRV; // We don't have to unregister shift, if we did we'd send ";" by mistake
            }
            else {
              my_kc = KC_DOT;
            }
            register_code(my_kc);
          }
          else { 
            unregister_code(my_kc);
            my_kc = KC_NO;
          }
        return false;
        }
        #endif
    }
    return true;
}
/* Blank
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */

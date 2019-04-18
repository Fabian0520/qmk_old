#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "quantum.h"
#include "fabian0520.h"
extern keymap_config_t keymap_config;

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

[_COLEMAK] =LAYOUT_planck_grid( 
   KC_ESC ,  KC_Q   ,  KC_W   ,   KC_F  ,   KC_P   ,   KC_G   ,   KC_J   ,   KC_L   ,   KC_U   ,   KC_Y   , KC_SCLN  , KC_BSPC ,
   LT(_SYM,KC_TAB)  ,  KC_A   ,  KC_R   ,   KC_S   ,   KC_T   ,   KC_D   ,   KC_H   ,   KC_N   ,   KC_E   ,   KC_I   ,  KC_O    , KC_DEL  ,
   KC_LSFT,  KC_Z   ,  KC_X   ,   KC_C  ,   KC_V   ,   KC_B   ,   KC_K   ,   KC_M   ,  MY_COMM ,  MY_DOT  , KC_QUOT  , TD_SFT_CAP ,
   KC_NO  ,OSM_CTL  , OSM_GUI , OSM_ALT ,  NUM_SPC ,  NUM_SPC ,  MOV_ENT ,  MOV_ENT , KC_RALT  ,  KC_RGUI , KC_RCTL  , KC_NO  
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
[_QWERTY] =LAYOUT_planck_grid( 
   KC_ESC ,  KC_Q   ,  KC_W   ,   KC_E   ,   KC_R   ,   KC_T   ,   KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   , KC_P     , KC_BSPC ,
   KC_TAB ,  KC_A   ,  KC_S   ,   KC_D   ,   KC_F   ,   KC_G   ,   KC_H   ,   KC_J   ,   KC_K   ,   KC_L   , KC_SCLN  , KC_ENT  ,
   KC_LSFT,  KC_Z   ,  KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,   KC_N   ,   KC_M   ,  MY_COMM ,  MY_DOT  , KC_QUOT  , TD_SFT_CAP ,
   KC_NO  ,OSM_CTL  , OSM_GUI , OSM_ALT  ,  NUM_SPC ,  NUM_SPC ,  MOV_ENT ,  MOV_ENT , KC_RALT  ,  KC_RGUI , KC_RCTL  , KC_NO  
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
[_TMP] =LAYOUT_planck_grid( 
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  ,
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  ,
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  ,
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  
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

[_NUM] =LAYOUT_planck_grid( 
  KC_TRNS ,  MY_EURO ,  MY_PARA ,  MY_CIRC ,  KC_QUOT ,  KC_NO   , KC_SLASH ,   KC_7   ,   KC_8   ,   KC_9   ,  KC_ASTR , KC_TRNS ,
  KC_TRNS ,  S(KC_7) ,  S(KC_6) ,  S(KC_5) ,  S(KC_4) ,S(KC_MINS),  KC_COMM ,   KC_4   ,   KC_5   ,   KC_6   ,  KC_PLUS , KC_TRNS , 
  KC_TRNS ,S(KC_SLSH),  S(KC_3) ,  S(KC_2) , S(KC_1)  , KC_EQUAL ,   KC_0   ,   KC_1   ,   KC_2   ,   KC_3   , KC_MINUS , KC_TRNS , 
  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_EQUAL , KC_TRNS  ,  KC_TRNS ,  KC_TRNS  
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
[_SYM] =LAYOUT_planck_grid( 
 KC_TRNS ,  KC_F12   , KC_F11   , KC_F10   , KC_F9    ,  KC_NO   , KC_PLUS  ,   TD_BS    , KC_RBRC  ,  TD_BA   ,  KC_GT   ,  KC_DEL  , 
 KC_TRNS ,  KC_F8    , KC_F7    , KC_F6    , KC_F5    ,  KC_NO   , KC_MINUS ,   TD_BR    , KC_RPRN  ,  TD_BC   , KC_RCBR  , KC_TRNS , 
 KC_TRNS ,  KC_F4    , KC_F3    , KC_F2    , KC_F1    , KC_NO    , KC_EQUAL ,  KC_PIPE   ,  KC_BSLS ,  KC_QUES ,  KC_GRAVE, KC_TRNS , 
 KC_TRNS ,  KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,  KC_TRNS ,  KC_TRNS   , KC_TRNS    , KC_TRNS  ,  KC_TRNS ,  KC_TRNS
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
[_MOV] =LAYOUT_planck_grid(
  KC_TRNS ,  KC_PGUP ,  KC_HOME ,  KC_UP   ,  KC_END  ,  KC_NO   ,  KC_NO   ,  i3_S_7  ,  i3_S_8  ,  i3_S_9  ,  KC_NO   , KC_TRNS  ,
  KC_TRNS ,  KC_PGDN ,  KC_LEFT ,  KC_DOWN ,  KC_RGHT ,  KC_NO   ,  KC_NO   ,  i3_S_4  ,  i3_S_5  ,  i3_S_6  ,  KC_NO   , KC_TRNS  ,
  KC_TRNS ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  i3_S_1  ,  i3_S_2  ,  i3_S_3  ,  KC_NO   , KC_TRNS  ,
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS
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
[_ADJUST] =LAYOUT_planck_grid(
  SCRE_UP ,  QWERTY  ,  COLEMAK ,   KC_NO  ,   KC_NO  ,   KC_NO  ,  RGB_TOG ,  RGB_HUI ,  RGB_SAI ,  RGB_VAI ,   KC_NO  ,  KC_VOLU ,
  SCRE_DN ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,  RGB_M_B ,  RGB_HUD ,  RGB_SAD ,  RGB_VAD ,   KC_NO  ,  KC_VOLD ,
   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,  RGB_M_K ,  RGB_M_P ,  RGB_M_R , RGB_M_SW ,   KC_NO  ,  KC_MUTE ,
  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS  
 ), 
};

#include "fabian0520.h"
//#include "action_layer.h"
//#include "eeconfig.h"
//#include "quantum.h"

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] =LAYOUT( 
   KC_ESC ,  KC_Q   ,  KC_W   ,   KC_F  ,   KC_P   ,   KC_G   ,        KC_J   ,   KC_L   ,   KC_U   ,   KC_Y   , KC_SCLN  , KC_BSPC ,
   LT(_SYM,KC_TAB)  ,  KC_A   ,  KC_R   ,   KC_S   ,   KC_T   ,        KC_D   ,   KC_H   ,   KC_N   ,   KC_E   ,   KC_I   ,  KC_O    , KC_DEL  ,
   KC_LSFT,  KC_Z   ,  KC_X   ,   KC_C  ,   KC_V   ,   KC_B   ,        KC_K   ,   KC_M   ,  MY_COMM ,  MY_DOT  , KC_QUOT  , TD_SFT_CAP ,
                                KC_LCTL ,  NUM_SPC ,  KC_LGUI ,       KC_RGUI ,  MOV_ENT ,  KC_RALT  
 ), 

[_QWERTY] =LAYOUT( 
   KC_ESC ,  KC_Q   ,  KC_W   ,   KC_E   ,   KC_R   ,   KC_T   ,   KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   , KC_P     , KC_BSPC ,
   KC_TAB ,  KC_A   ,  KC_S   ,   KC_D   ,   KC_F   ,   KC_G   ,   KC_H   ,   KC_J   ,   KC_K   ,   KC_L   , KC_SCLN  , KC_ENT  ,
   KC_LSFT,  KC_Z   ,  KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,   KC_N   ,   KC_M   ,  MY_COMM ,  MY_DOT  , KC_QUOT  , TD_SFT_CAP ,
                                OSM_ALT  ,  NUM_SPC ,  NUM_SPC ,  MOV_ENT ,  MOV_ENT , KC_RALT  
 ), 

[_NUM] =LAYOUT( 
  KC_TRNS ,  MY_EURO ,  MY_PARA ,  MY_CIRC ,  KC_QUOT ,  KC_NO   , KC_SLASH ,   KC_7   ,   KC_8   ,   KC_9   ,  KC_ASTR , KC_TRNS ,
  KC_TRNS ,  S(KC_7) ,  S(KC_6) ,  S(KC_5) ,  S(KC_4) ,S(KC_MINS),  KC_COMM ,   KC_4   ,   KC_5   ,   KC_6   ,  KC_PLUS , KC_TRNS , 
  KC_TRNS ,S(KC_SLSH),  S(KC_3) ,  S(KC_2) , S(KC_1)  , KC_EQUAL ,   KC_0   ,   KC_1   ,   KC_2   ,   KC_3   , KC_MINUS , KC_TRNS , 
                                  KC_TRNS  ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_DOT
 ), 

[_SYM] =LAYOUT( 
 KC_TRNS ,  KC_F12   , KC_F11   , KC_F10   , KC_F9    ,  KC_NO   , KC_PLUS  ,  KC_LBRC   , KC_RBRC  ,  KC_LT   ,  KC_GT   , KC_TRNS  , 
 KC_TRNS ,  KC_F8    , KC_F7    , KC_F6    , KC_F5    ,  KC_NO   , KC_MINUS ,  KC_LPRN   , KC_RPRN  ,  KC_LCBR , KC_RCBR  , KC_TRNS , 
 KC_TRNS ,  KC_F4    , KC_F3    , KC_F2    , KC_F1    ,  KC_NO   , KC_EQUAL ,  KC_PIPE   ,  KC_BSLS ,  KC_QUES ,  KC_GRAVE, KC_TRNS , 
                                  KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,  KC_TRNS   , KC_TRNS 
 ), 

[_MOV] =LAYOUT(
  KC_TRNS ,  KC_PGUP ,  KC_HOME ,  KC_UP   ,  KC_END  ,  KC_NO   ,  KC_NO   ,  i3_S_7  ,  i3_S_8  ,  i3_S_9  ,  KC_NO   , KC_TRNS  ,
  KC_TRNS ,  KC_PGDN ,  KC_LEFT ,  KC_DOWN ,  KC_RGHT ,  KC_NO   ,  KC_NO   ,  i3_S_4  ,  i3_S_5  ,  i3_S_6  ,  KC_NO   , KC_TRNS  ,
  KC_TRNS ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  KC_NO   ,  i3_S_1  ,  i3_S_2  ,  i3_S_3  ,  KC_NO   , KC_TRNS  ,
                                   KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS
 ), 

[_ADJUST] =LAYOUT(
  SCRE_UP ,  QWERTY  ,  COLEMAK ,  KC_NO   ,   KC_NO  ,   KC_NO  ,  RGB_HUI ,  RGB_SAI ,  RGB_VAI ,  RGB_SPI ,   KC_NO  ,  KC_VOLU ,
  SCRE_DN , RGB_TOG  ,  RGB_MOD ,  KC_NO   ,   KC_NO  ,   KC_NO  ,  RGB_HUD ,  RGB_SAD ,  RGB_VAD ,  RGB_SPD ,   KC_NO  ,  KC_VOLD ,
   KC_NO  , RGB_RMOD ,   KC_NO  ,  KC_NO   ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,  KC_MUTE ,
                                   KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS 
 ) 
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

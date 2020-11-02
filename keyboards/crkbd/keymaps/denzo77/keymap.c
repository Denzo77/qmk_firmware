#include <stdint.h>

#include QMK_KEYBOARD_H

#include "keymap_steno.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif


extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _PLOVER,
  _TEKKEN,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  PLOVER,
  BACKLIT,
  RGBRST,
  EXT_PLV,
  SHIFT,
  TEKKEN,
  EXT_TKN
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

// Double tap toggle lower
#define LOW_TT TT(_LOWER)
#define CPS_GUI LGUI_T(KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       PLOVER,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MPLY,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CPS_GUI,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LALT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT,  LOW_TT,KC_ENTER,   KC_SPACE,   RAISE, KC_RSFT
                                      //`--------------------------'  `--------------------------'
  ),
  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      TEKKEN,    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_TAB, KC_HOME,   KC_UP,  KC_END, KC_PGUP,                      XXXXXXX, KC_PLUS, KC_ASTR, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                      XXXXXXX, KC_MINS,  KC_EQL, KC_NUBS, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_UNDS, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),
  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PIPE, KC_NUHS, KC_DQUO, KC_QUOT, KC_ESC,                       XXXXXXX, KC_BSPC,  KC_DEL, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_LBRC, KC_LCBR, KC_LPRN, XXXXXXX,                      XXXXXXX, KC_RPRN, KC_RCBR, KC_RBRC, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   LOWER, _______,    _______, _______, _______ 
                                      //`--------------------------'  `--------------------------'
  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ 
                                      //`--------------------------'  `--------------------------'
  ),
  [_PLOVER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      EXT_PLV,  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                       STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1,                      STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2,                      STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,   STN_A,  STN_O,       STN_E,   STN_U, XXXXXXX 
                                      //`--------------------------'  `--------------------------'
  ),
  [_TEKKEN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      EXT_TKN,  KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX,    KC_V,                         KC_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--n------+--------+--------|
      KC_CAPS, XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,                      XXXXXXX,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                      XXXXXXX,    KC_J,    KC_K,    KC_L, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  KC_TAB,KC_SPACE,       KC_C,    KC_N, XXXXXXX 
                                      //`--------------------------'  `--------------------------'
  ),
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


const rgblight_segment_t PROGMEM  my_default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,     6, HSV_MAGENTA},  // BACKLIGHT
    {11,    1, HSV_MAGENTA},  // HOME
    {0+27,  6, HSV_MAGENTA},  // BACKLIGHT
    {11+27, 1, HSV_MAGENTA}   // HOME
);
const rgblight_segment_t PROGMEM  my_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11,    1, HSV_ORANGE},     // HOME
    {25,    1, HSV_ORANGE},     // CAPS
    {11+27, 1, HSV_ORANGE}      // HOME
);
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {12,    1, HSV_MAGENTA},     // RIGHT
    {15,    2, HSV_MAGENTA},     // UP/DOWN
    {20,    1, HSV_MAGENTA}     // LEFT
);
// const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     // {0,    6, HSV_BLUE},        // BACKLIGHT
//     // {0+27, 6, HSV_BLUE}         // BACKLIGHT
// );
// const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     // {0,    6, HSV_GREEN},       // BACKLIGHT
//     // {0+27, 6, HSV_GREEN}        // BACKLIGHT
// );
const rgblight_segment_t PROGMEM my_plover_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,    6, HSV_RED},         // BACKLIGHT
    {11,   1, HSV_RED},         // HOME
    {24,   1, HSV_RED},         // PLOVER
    {0+27, 6, HSV_RED},          // BACKLIGHT
    {11+27, 1, HSV_RED}          // HOME
);

const rgblight_segment_t PROGMEM my_tekken_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,    6, RGB_AZURE},         // BACKLIGHT

    {12,   1, RGB_AZURE},       // right
    {15,   1, RGB_AZURE},       // down
    {16,   1, RGB_AZURE},       // up
    {20,   1, RGB_AZURE},       // left

    {24,   1, HSV_BLUE},        // TEKKEN
    
    {0+27,    6,  RGB_AZURE},   // BACKLIGHT
    {6+27,    1, RGB_AZURE},    // R3
    {9+27,    1, RGB_AZURE},    // start
    {13+27,   1, RGB_AZURE},    // L3
    {11+27,   1, HSV_BLUE},     // X
    {12+27,   1, HSV_GREEN},    // A
    {15+27,   1, HSV_RED},      // B
    {16+27,   1, HSV_YELLOW},   // Y
    {19+27,   2, RGB_AZURE},    // R1/R2
    {21+27,   2, RGB_AZURE}     // L1/L2
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_default_layer,
    my_lower_layer,
    // my_raise_layer,
    // my_adjust_layer,
    my_plover_layer,
    my_caps_layer,
    my_tekken_layer
);

void keyboard_post_init_user(void) {
    // isLeftHand = is_keyboard_left();
    uint8_t num_rgb_leds_split[2] = RGBLED_SPLIT;
    if (isLeftHand) {
        rgblight_set_clipping_range(0, num_rgb_leds_split[0]);
    } else {
        rgblight_set_clipping_range(num_rgb_leds_split[0], num_rgb_leds_split[1]);
    }
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1,  layer_state_cmp(state, _LOWER));
    // rgblight_set_layer_state(_RAISE,  layer_state_cmp(state, _RAISE));
    // rgblight_set_layer_state(_ADJUST, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(2, layer_state_cmp(state, _PLOVER));
    rgblight_set_layer_state(4, layer_state_cmp(state, _TEKKEN));
    return state;
}


// FIXME: This one only updates the master.
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(3, led_state.caps_lock);
    return true;
}

void matrix_init_user(void) {
    #ifdef STENO_ENABLE
      // emulate gemini as it subjectively works better.
      steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
    #endif
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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case PLOVER:
      if (!record->event.pressed) {
        layer_on(_PLOVER);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
      }
      return false;
      break;
    case TEKKEN:
      if (!record->event.pressed) {
        layer_on(_TEKKEN);
      }
      return false;
      break;
    case EXT_TKN:
      if (record->event.pressed) {
        layer_off(_TEKKEN);
      }
      return false;
      break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}


// void suspend_power_down_user(void) {
//   matrix_scan();
// }
// void suspend_wakeup_init_user(void) {
//     rgblight_enable_noeeprom();
//     // backlight_enable();
// }

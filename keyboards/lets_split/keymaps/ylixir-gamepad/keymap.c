#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

#include "half_40.h"
extern keymap_config_t keymap_config;

enum layers
  { LEFT
  , RIGHT
  , LOWER
  , RAISE
  };

enum custom_keycodes {
  C_LEFT = SAFE_RANGE,
  C_RIGHT,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Left
 * ,-----------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------+------|
 * | Ctrl |   T  |   Q  |   W  |   E  |   R  |
 * |------+------+------+------+------+------|
 * |Shift |   G  |   A  |   S  |   D  |   F  |
 * |------+------+------+------+------+------|
 * | Esc  |   Z  |   X  |   C  |   V  |Space |
 * |Lower |      |      |      | Raise|      |
 * `-----------------------------------------'
 */

[LEFT] = LAYOUT_RIGHT_HALF( \
  KC_TAB,  KC_1, KC_2, KC_3, KC_4, KC_5, \
  KC_LCTL, KC_T, KC_Q, KC_W, KC_E, KC_R, \
  KC_LSFT, KC_G, KC_A, KC_S, KC_D, KC_F, \
  LT(LOWER, KC_ESC), KC_Z, KC_X, KC_C, LT(RAISE, KC_V), KC_SPC \
),

/* Right
 * ,-----------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  | Tab  |
 * |------+------+------+------+------+------|
 * |   T  |   Q  |   W  |   D  |   F  | Ctrl |
 * |------+------+------+------+------+------|
 * |   G  |   A  |   S  |   E  |   R  |Shift |
 * |------+------+------+------+------+------|
 * |Space |   Z  |   X  |   C  |   V  | Esc  |
 * |      |Raise |      |      |      |Lower |
 * `-----------------------------------------'
 */

[RIGHT] = LAYOUT_RIGHT_HALF( \
  KC_1,   KC_2, KC_3, KC_4, KC_5, KC_TAB,  \
  KC_T,   KC_Q, KC_W, KC_D, KC_R, KC_LCTL, \
  KC_G,   KC_A, KC_S, KC_E, KC_F, KC_LSFT, \
  KC_SPC, LT(RAISE, KC_Z), KC_X, KC_C, KC_V, LT(LOWER, KC_ESC) \
),

/* Raise
 * ,-----------------------------------------.
 * |   M  |  7   |  8   |  9   |   M  |      |
 * |------+------+------+------+------+------|
 * |   0  |  4   |  5   |  6   |   0  |      |
 * |------+------+------+------+------+------|
 * |   B  |  1   |  2   |  3   |   B  |      |
 * |------+------+------+------+------+------|
 * |Enter |      |      |      |      |Enter |
 * |      |      |      |      |      |      |
 * `-----------------------------------------'
 */

[RAISE] = LAYOUT_RIGHT_HALF( \
      KC_M,    KC_7,    KC_8,    KC_9,    KC_M, _______,  \
      KC_0,    KC_4,    KC_5,    KC_6,    KC_0, _______,  \
      KC_B,    KC_1,    KC_2,    KC_3,    KC_B, _______,  \
  KC_ENTER, _______, _______, _______, _______, KC_ENTER \
),

/* Lower
 * ,-----------------------------------------.
 * |      |      |      |      |      |Reset |
 * |------+------+------+------+------+------|
 * |      |      |      |      |      |      |
 * |------+------+------+------+------+------|
 * |      |      |      |      |      |      |
 * |------+------+------+------+------+------|
 * |      |      |      |      |      |      |
 * |      |      |      |      |      |      |
 * `-----------------------------------------'
 */

[LOWER] = LAYOUT_RIGHT_HALF( \
   C_LEFT, _______, _______, _______, _______, C_RIGHT, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______,   RESET, _______, _______, _______ \
),

/* Blank
 * ,-----------------------------------------.
 * |      |      |      |      |      |      |
 * |------+------+------+------+------+------|
 * |      |      |      |      |      |      |
 * |------+------+------+------+------+------|
 * |      |      |      |      |      |      |
 * |------+------+------+------+------+------|
 * |      |      |      |      |      |      |
 * |      |      |      |      |      |      |
 * `-----------------------------------------'

[BLANK] = LAYOUT_RIGHT_HALF( \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, \
),
 */

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_LEFT:
      eeconfig_update_default_layer(1UL<<LEFT);
      default_layer_set(1UL<<LEFT);
      return false;
    case C_RIGHT:
      eeconfig_update_default_layer(1UL<<RIGHT);
      default_layer_set(1UL<<RIGHT);
      return false;
    default:
      return true;
  }
}

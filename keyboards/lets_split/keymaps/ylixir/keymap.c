#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOVE 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

//double usage keys
#define ESCMOVE LT(_MOVE, KC_ESC)
#define ENTMOVE LT(_MOVE, KC_ENT)
#define SPLOWER LT(_LOWER, KC_SPC)
#define SPRAISE LT(_RAISE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Esc   |  Gui |      |      | Alt  |Space |Space | Alt  |      | Menu | Gui  |Enter |
 * |Move  |      |      |      |      |Lower |Raise |      |      |      |      |Move  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,  \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT , \
  ESCMOVE, KC_LGUI, XXXXXXX, XXXXXXX, KC_LALT, SPLOWER, SPRAISE, KC_RALT, XXXXXXX, KC_MENU, KC_RGUI, ENTMOVE   \
),

/* Lower
 * ,-----------------------------------------------------------------------------------------------.
 * |       |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |  Del  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  Esc  |       |       |       |   =   |   -   |       |   <   |   >   |   {   |   }   |   |   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |ISO ~  |ISO  | |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       | Next  | Vol-  | Vol+  | Play  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
    _______,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL ,    \
    KC_ESC ,_______,_______,_______,KC_EQL ,KC_MINS,_______,KC_LT  ,KC_GT  ,KC_LCBR,KC_RCBR,KC_PIPE,   \
    _______,_______,_______,_______,_______,_______,_______,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
    _______,_______,_______,_______,_______,_______,RAISE  ,_______,KC_MNXT,KC_VOLD,KC_VOLU,KC_MPLY    \
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |       |   0   |   7   |   8   |   9   |   `   |  ~    |   +   |   _   |   [   |   ]   |  Ins  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |   4   |   5   |   6   |       | Left  | Down  |   Up  | Right |       |   \   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |   1   |   2   |   3   |       |       |ISO #  |ISO /  |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       | Next  | Vol-  | Vol+  |  Play |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
    _______,KC_0   ,KC_7   ,KC_8   ,KC_9   ,KC_GRV ,KC_TILD,KC_PLUS,KC_UNDS,KC_LBRC,KC_RBRC,KC_INS ,  \
    _______,_______,KC_4   ,KC_5   ,KC_6   ,_______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_RBRC,KC_BSLS, \
    _______,_______,KC_1   ,KC_2   ,KC_3   ,_______,_______,KC_NUHS,KC_NUBS,_______,_______,_______, \
    KC_ESC ,_______,_______,_______,_______,LOWER  ,_______,_______,KC_MNXT,KC_VOLD,KC_VOLU,KC_MPLY  \
),

/* Movement
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Back | MUp  | Fwd  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |MLeft |MDown |MRight|      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      | Btn3 |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Btn1 | Btn2 |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] =  LAYOUT_ortho_4x12( \
  _______, _______, KC_MS_BTN4, KC_MS_UP,   KC_MS_BTN5,  _______,    _______,    _______, _______, _______, _______, _______, \
  _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,    KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, _______, _______,    KC_MS_BTN3, _______,     _______,    _______,    _______, _______, _______, _______, _______, \
  _______, _______, _______,    _______,    _______,     KC_MS_BTN1, KC_MS_BTN2, _______, _______, _______, _______, _______  \
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------------------.
 * |   F1  |   F2  |  F3   |   F4  |  F5   |   F6  |   F7  |   F8  |   F9  |  F10  |  F11  |  F12  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Reset |       |       |Aud on |Audoff |AGnorm |AGswap |Qwerty |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,   \
  RESET  ,_______,_______,AU_ON  ,AU_OFF ,AG_NORM,AG_SWAP,QWERTY ,_______,_______,_______,_______, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  \
  KC_ESC, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_ENT    \
),


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
  }
  return true;
}

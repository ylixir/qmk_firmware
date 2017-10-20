#include "tomato.h"

#define SPC_F1 LT(1,KC_SPC)
#define BS_F2 LT(2,KC_BSPC)
#define ESC_F3 LT(3,KC_ESC)
#define N_F4 LT(4,KC_N)
#define C_F5 LT(5,KC_C)
#define Z_CTL MT(MOD_LCTL, KC_Z)
#define A_CTL MT(MOD_RCTL, KC_A)
#define X_GUI MT(MOD_LGUI, KC_X)
#define V_ALT MT(MOD_LALT, KC_V)
#define B_ALT MT(MOD_RALT, KC_B)
#define M_GUI MT(MOD_RGUI, KC_M)
#define ENT_SFT MT(MOD_RSFT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Level 0: Default Layer
   * ,-------------------------------------------------------------------------------.
   * |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |
   * |-------------------------------------------------------------------------------|
   * | A Ctl |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   | Z Ctl |
   * |-------------------------------------------------------------------------------|
   * |Esc Fn3| X Gui | C Fn5 | V Alt |<- Fn2 |SPC Fn1| B Alt | N Fn4 | M Gui |Ent Sft|
   * '-------------------------------------------------------------------------------'
   */
  KEYMAP
     (KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P
     ,A_CTL  ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,Z_CTL
     ,ESC_F3 ,X_GUI  ,C_F5   ,V_ALT  ,BS_F2  ,SPC_F1 ,B_ALT  ,N_F4   ,M_GUI  ,ENT_SFT
     ),
  /* Level 1: Numbers/Function Layer
   * ,-------------------------------------------------------------------------------.
   * |   ,   |   7   |   8   |   9   |   0   |   ~   |   F7  |   F8  |   F9  |  F12  |
   * |-------------------------------------------------------------------------------|
   * |   +   |   4   |   5   |   6   |   .   |   `   |   F4  |   F5  |   F6  |  F11  |
   * |-------------------------------------------------------------------------------|
   * |   "   |   1   |   2   |   3   |  DEL  |       |   F1  |   F2  |   F3  |  F10  |
   * '-------------------------------------------------------------------------------'
   */
  KEYMAP
     (KC_COMM,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_TILD,KC_F7  ,KC_F8  ,KC_F9  ,KC_F12
     ,KC_PLUS,KC_4   ,KC_5   ,KC_6   ,KC_DOT ,KC_GRV ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F11
     ,KC_DQT ,KC_1   ,KC_2   ,KC_3   ,KC_DEL ,KC_TRNS,KC_F1  ,KC_F2  ,KC_F3  ,KC_F10
    ),
  /* Level 2: Symbols Layer
   * ,-------------------------------------------------------------------------------.
   * |   _   |   &   |   *   |   (   |   )   |   =   |   /   |   [   |   ]   |   \   |
   * |-------------------------------------------------------------------------------|
   * |   -   |   $   |   %   |   ^   |   .   |       |   <   |   {   |   }   |   >   |
   * |-------------------------------------------------------------------------------|
   * |   '   |   !   |   @   |   #   |       |  Tab  |   ?   |   :   |   |   |   ;   |
   * '-------------------------------------------------------------------------------'
   */
  KEYMAP
    ( KC_UNDS,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_EQL ,KC_SLSH,KC_LBRC,KC_RBRC,KC_BSLS
    , KC_MINS,KC_DLR, KC_PERC,KC_CIRC,KC_DOT ,KC_TRNS,KC_LT  ,KC_LCBR,KC_RCBR,KC_GT
    , KC_QUOT,KC_EXLM,KC_AT,  KC_HASH,KC_TRNS,KC_TAB ,KC_QUES,KC_COLN,KC_PIPE,KC_SCLN
    ),
  /* Level 3: Little movement
   * ,-------------------------------------------------------------------------------.
   * |       |       |       |       |       |       |       |       |       |       |
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       |       | Left  | Down  |   Up  | Right |       |
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       |       |       |       |       |       |       |
   * '-------------------------------------------------------------------------------'
   */
  KEYMAP
    ( KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MINS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    , KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_TRNS
    , KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    ),
  /* Level 4: Big movement
   * ,-------------------------------------------------------------------------------.
   * |       |       |       |       |       |       |       |        |       |      |
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       |       | Home  |  PgDn |   PgUp | End   |      |
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       |       |       |
   * '-------------------------------------------------------------------------------'
   */
  KEYMAP
    ( KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_UNDS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    , KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_TRNS
    , KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    ),
  /* Level 5: RGB Layer
   * ,-------------------------------------------------------------------------------.
   * | Calc  |  Web  | Mail  |Explore|       |       |       |       |       |       |
   * |-------------------------------------------------------------------------------|
   * |RGB_TOG|RGB_MOD|RGB_HUI|RGB_HUD|xxxxxxx|xxxxxxx|RGB_SAI|RGB_SAD|RGB_VAI|RGB_VAD|
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       | Flash |       |       |       |       |       |
   * '-------------------------------------------------------------------------------'
   */
  KEYMAP
    ( KC_CALC,KC_WSCH,KC_MAIL,KC_MYCM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    , RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,KC_NO,  KC_NO,  RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD
    , KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,RESET,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

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

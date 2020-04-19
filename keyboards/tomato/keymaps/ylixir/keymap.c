#include "tomato.h"

enum layers {
  DEFAULT,
  RAISE,
  LOWER,
  MOVEMENT,
  BIG_MOVE,
  RGB,
  GAMING,
  GAMING_EXTRA
};

#define SPC_UP LT(RAISE,KC_SPC)
#define BS_LO LT(LOWER,KC_BSPC)
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
#define TO_GAME TO(GAMING)
#define TO_DEF TO(DEFAULT)
#define FOUR_G LT(GAMING_EXTRA, KC_4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Level 0: Default Layer
   * ,-------------------------------------------------------------------------------.
   * |   q   |   w   |   e   |   r   |   t   |   y   |   u   |   i   |   o   |   p   |
   * |-------------------------------------------------------------------------------|
   * | a Ctl |   s   |   d   |   f   |   g   |   h   |   j   |   k   |   l   | z Ctl |
   * |-------------------------------------------------------------------------------|
   * |Esc Fn3| x Gui | c Fn5 | v Alt |<- Fn2 |SPC Fn1| b Alt | n Fn4 | m Gui |Ent Sft|
   * '-------------------------------------------------------------------------------'
   */
  [DEFAULT] = KEYMAP
     (KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P
     ,A_CTL  ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,Z_CTL
     ,ESC_F3 ,X_GUI  ,C_F5   ,V_ALT  ,BS_LO  ,SPC_UP ,B_ALT  ,N_F4   ,M_GUI  ,ENT_SFT
     ),
  /* Level 1: Numbers/Function Layer
   * ,-------------------------------------------------------------------------------.
   * |   0   |   7   |   8   |   9   |   `   |   ~   |   +   |   _   |   [   |   ]   |
   * |-------------------------------------------------------------------------------|
   * |   .   |   4   |   5   |   6   |       | Left  | Down  |   Up  | Right |   :   |
   * |-------------------------------------------------------------------------------|
   * |       |   1   |   2   |   3   |  DEL  |       |   |   |   ,   |   ?   |   '   |
   * '-------------------------------------------------------------------------------'
   */
  [RAISE] = KEYMAP
     (KC_0   ,KC_7   ,KC_8   ,KC_9   ,KC_GRV ,KC_TILD,KC_PLUS,KC_UNDS,KC_LBRC,KC_RBRC
     ,KC_DOT ,KC_4   ,KC_5   ,KC_6   ,KC_TRNS,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_COLN
     ,KC_TRNS,KC_1   ,KC_2   ,KC_3   ,KC_DEL ,KC_TRNS,KC_PIPE,KC_COMM,KC_QUES,KC_QUOT
    ),
  /* Level 2: Symbols Layer
   * ,-------------------------------------------------------------------------------.
   * |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |
   * |-------------------------------------------------------------------------------|
   * |   .   |   %   |   ^   |   =   |   -   |   <   |   >   |   {   |   }   |   ;   |
   * |-------------------------------------------------------------------------------|
   * |       |   !   |   @   |   #   |       |  Tab  |   \   |   ,   |   /   |   "   |
   * '-------------------------------------------------------------------------------'
   */
  [LOWER] = KEYMAP
    ( KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN
    , KC_DOT ,KC_PERC,KC_CIRC,KC_EQL ,KC_MINS,KC_LT  ,KC_GT  ,KC_LCBR,KC_RCBR,KC_SCLN
    , KC_TRNS,KC_EXLM,KC_AT,  KC_HASH,KC_TRNS,KC_TAB ,KC_BSLS,KC_COMM,KC_SLSH,KC_DQT
    ),
  /* Level 3: Little movement
   * ,-------------------------------------------------------------------------------.
   * |       |       |       |       |       |   Y   |   U   |   I   |   O   |   P   |
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       | Game  |   H   |   J   |   K   |   L   |   Z   |
   * |-------------------------------------------------------------------------------|
   * |       |       |       |       |       |       |   B   |   N   |   M   |       |
   * '-------------------------------------------------------------------------------'
   */
  [MOVEMENT] = KEYMAP
    (KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,LSFT(KC_Y),LSFT(KC_U),LSFT(KC_I),LSFT(KC_O),LSFT(KC_P)
    ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,TO_GAME   ,LSFT(KC_H),LSFT(KC_J),LSFT(KC_K),LSFT(KC_L),LSFT(KC_Z)
    ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,LSFT(KC_B),LSFT(KC_N),LSFT(KC_M),KC_TRNS
    ),
  /* Level 4: Big movement
   * ,-------------------------------------------------------------------------------.
   * |  F12  |  F7   |  F8   |  F9   |       |       |       |        |       |      |
   * |-------------------------------------------------------------------------------|
   * |  F11  |  F4   |  F5   |  F6   |       | Home  |  PgDn |   PgUp | End   |      |
   * |-------------------------------------------------------------------------------|
   * |  F10  |  F1   |  F2   |  F3   |       |       |       |        |       |      |
   * '-------------------------------------------------------------------------------'
   */
  [BIG_MOVE] = KEYMAP
    ( KC_F12 ,KC_F7  ,KC_F8  ,KC_F9  ,KC_TRNS,KC_UNDS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    , KC_F11 ,KC_F4  ,KC_F5  ,KC_F6  ,KC_TRNS,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_TRNS
    , KC_F10 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
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
  [RGB] = KEYMAP
    ( KC_CALC,KC_WSCH,KC_MAIL,KC_MYCM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    , RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,KC_NO  ,  KC_NO,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD
    , KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,RESET,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    ),
  /* Gaming Layer
   * ,-------------------------------------------------------------------------------.
   * |   3   |  Tab  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |
   * |-------------------------------------------------------------------------------|
   * |   2   |  Ctl  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |
   * |-------------------------------------------------------------------------------|
   * |   1   | Shift |   Z   |   X   |   C   | Space | 4,G2  |   B   |   N   |   M   |
   * '-------------------------------------------------------------------------------'
   */
  [GAMING] = KEYMAP
     (KC_3   ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I
     ,KC_2   ,KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K
     ,KC_1   ,KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_SPC ,FOUR_G ,KC_B   ,KC_N   ,KC_M
     ),
  /* Gaming extra numbers layer
   * ,-------------------------------------------------------------------------------.
   * |   7   |       |       |       |       |       |       |       |       |  Esc  |
   * |-------------------------------------------------------------------------------|
   * |   6   |       |       |       |       |       |       |       |       |Default|
   * |-------------------------------------------------------------------------------|
   * |   5   |       |       |       |       |       |       |       |       |       |
   * '-------------------------------------------------------------------------------'
   */
  [GAMING_EXTRA] = KEYMAP
    ( KC_7   ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_ESC
    , KC_5   ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,TO_DEF
    , KC_5   ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
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

uint32_t layer_state_set_user(uint32_t state) {
    char brightness = rgblight_get_val();
    rgblight_sethsv(40, 255, brightness);
    switch (biton32(state)) {
    case DEFAULT:
        rgblight_sethsv_at(20, 255, brightness, 19);
        rgblight_sethsv_at(300, 255, brightness, 9);
        rgblight_sethsv_at(20, 255, brightness, 8);
        rgblight_sethsv_at(20, 255, brightness, 7);
        rgblight_sethsv_at(20, 255, brightness, 6);
        rgblight_sethsv_at(0, 255, brightness, 5);
        rgblight_sethsv_at(120, 255, brightness, 4);
        rgblight_sethsv_at(70, 255, brightness, 3);
        rgblight_sethsv_at(70, 255, brightness, 2);
        rgblight_sethsv_at(70, 255, brightness, 1);
        rgblight_sethsv_at(300, 255, brightness, 0);
        rgblight_sethsv_at(70, 255, brightness, 10);
        break;
    case RAISE:
        for(int i=1; i < 10; i++) {
          int c = 8-((i-1)%3);
          int r = (i-1)/3*10;
          rgblight_sethsv_at(120, 28*i, brightness, r+c);
        }
        rgblight_sethsv_at(120, 0, brightness, 29);
        break;
    case GAMING:
        //blue wasd
        rgblight_sethsv_at(240, 255, brightness, 26);
        rgblight_sethsv_at(240, 255, brightness, 17);
        rgblight_sethsv_at(240, 255, brightness, 16);
        rgblight_sethsv_at(240, 255, brightness, 15);

        //shades of green for numbers
        rgblight_sethsv_at(120, 255, brightness, 0);
        rgblight_sethsv_at(120, 255, brightness, 1);
        rgblight_sethsv_at(120, 255, brightness, 2);
        rgblight_sethsv_at(0, 128, brightness, 3);
        rgblight_sethsv_at(120, 170, brightness, 10);
        rgblight_sethsv_at(120, 170, brightness, 11);
        rgblight_sethsv_at(120, 170, brightness, 12);
        rgblight_sethsv_at(120, 85, brightness, 20);
        rgblight_sethsv_at(120, 85, brightness, 21);
        rgblight_sethsv_at(120, 85, brightness, 22);
        rgblight_sethsv_at(120, 255, brightness, 9);
        rgblight_sethsv_at(120, 255, brightness, 19);
        rgblight_sethsv_at(120, 255, brightness, 29);
        break;
    case GAMING_EXTRA:
        //shades of green for numbers
        rgblight_sethsv_at(120, 170, brightness, 9);
        rgblight_sethsv_at(120, 170, brightness, 19);
        rgblight_sethsv_at(120, 170, brightness, 29);

        //red for exits
        rgblight_sethsv_at(0, 255, brightness, 20);
        rgblight_sethsv_at(0, 128, brightness, 10);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom(180, 255, brightness);
        break;
    }
  return state;
}

void matrix_init_user(void) {
  rgblight_init();
  rgblight_enable();
  layer_state_set_user(0);
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

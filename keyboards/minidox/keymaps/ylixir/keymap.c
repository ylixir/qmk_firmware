#include "minidox.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers
  { QWERTY
  , COLEMAK_DH
  , GAME
  , GAME_EXTRA
  , LOWER
  , RAISE
  , ADJUST = 16
  };


enum custom_keycodes {
  KC_QWRT = SAFE_RANGE,
  KC_LOW,
  KC_RISE,
  KC_ADJ,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define A_CTL MT(MOD_LCTL, KC_A)
#define Z_SFT MT(MOD_LSFT, KC_Z)
#define ESC_ALT MT(MOD_LALT, KC_ESC)
#define TAB_GUI MT(MOD_LGUI, KC_TAB)
#define BS_LO LT(LOWER,KC_BSPC)
#define SPC_UP LT(RAISE,KC_SPC)
#define ENT_ALT MT(MOD_RALT, KC_ENT)
#define DEL_GUI MT(MOD_RGUI, KC_DEL)
#define SLS_SFT MT(MOD_RSFT, KC_SLSH)
#define CLN_CTL MT(MOD_RCTL, KC_SCLN)
#define O_CTL MT(MOD_RCTL, KC_O)

#define TO_GAME TO(GAME)
#define GAME_EX MO(GAME_EXTRA)
#define MO_RISE MO(RAISE)
#define MO_ADJ MO(ADJUST)
#define DF_CMAK DF(COLEMAK_DH)
#define DF_QWRT DF(QWERTY)
#define TO_QWRT TO(QWERTY)

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.            ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |            |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|            |------+------+------+------+------|
 * |A/Ctl |   S  |   D  |   F  |   G  |            |   H  |   J  |   K  |   L  | ; Ctl|
 * |------+------+------+------+------|            |------+------+------+------+------|
 * |Z/Shft|   X  |   C  |   V  |   B  |            |   N  |   M  |   ,  |   .  |/ Shft|
 * `----------------------------------'            `----------------------------------'
 *                 ,---------------------.      ,------,---------------.
 *                 |Tab/Gui|Esc/Alt|      |     |      |Ent/Alt|Del/Gui|
 *                 `---------------|BckSpc|     |Space |-------+-------.
 *                                 | Lower|     |Raise |
 *                                 `------'     `------'
 */
[QWERTY] = LAYOUT
  (KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T         ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P
  ,A_CTL   ,KC_S    ,KC_D    ,KC_F    ,KC_G         ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,CLN_CTL
  ,Z_SFT   ,KC_X    ,KC_C    ,KC_V    ,KC_B         ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,SLS_SFT
                    ,TAB_GUI ,ESC_ALT ,BS_LO        ,SPC_UP  ,ENT_ALT ,DEL_GUI
),

/* Colemak Mod-DH
 *
 * ,----------------------------------.            ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |            |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|            |------+------+------+------+------|
 * |A Ctl |   R  |   S  |   T  |   G  |            |   M  |   N  |   E  |   I  | O Ctl|
 * |------+------+------+------+------|            |------+------+------+------+------|
 * |Z Shft|   X  |   C  |   D  |   V  |            |   K  |   H  |   ,  |   .  |/ Shft|
 * `----------------------------------'            `----------------------------------'
 *                 ,---------------------.      ,------,---------------.
 *                 |Tab/Gui|Esc/Alt|      |     |      |Ent/Alt|Del/Gui|
 *                 `---------------|BckSpc|     |Space |-------+-------.
 *                                 | Lower|     |Raise |
 *                                 `------'     `------'
 */
[COLEMAK_DH] = LAYOUT
  (KC_Q    ,KC_W    ,KC_E    ,KC_P    ,KC_B         ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN
  ,A_CTL   ,KC_R    ,KC_S    ,KC_T    ,KC_G         ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,O_CTL
  ,Z_SFT   ,KC_X    ,KC_C    ,KC_D    ,KC_V         ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,SLS_SFT
                    ,TAB_GUI ,ESC_ALT ,BS_LO        ,SPC_UP  ,ENT_ALT ,DEL_GUI
),

/* Game
 *
 * ,----------------------------------.            ,----------------------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |            |      |      |      |      |      |
 * |------+------+------+------+------|            |------+------+------+------+------|
 * |  Ctl |   A  |   S  |   D  |   F  |            |      |      |      |      |      |
 * |------+------+------+------+------|            |------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |            |      |      |      |      |      |
 * `----------------------------------'            `----------------------------------'
 *                 ,---------------------.      ,------,---------------.
 *                 |  Esc  |GameExt|      |     |      |Qwerty |       |
 *                 `---------------| Space|     |Raise |-------+-------.
 *                                 |      |     |      |
 *                                 `------'     `------'
 */
[GAME] = LAYOUT
  (KC_TAB  ,KC_Q   ,KC_W   ,KC_E   ,KC_R         ,_______,_______,_______,_______,_______
  ,KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F         ,_______,_______,_______,_______,_______
  ,KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V         ,_______,_______,_______,_______,_______
                   ,KC_ESC ,GAME_EX,KC_SPC       ,MO_RISE,TO_QWRT,_______
),

/* Game Extra
 *
 * ,----------------------------------.            ,----------------------------------.
 * |   1  |      |      |      |   4  |            |      |      |      |      |      |
 * |------+------+------+------+------|            |------+------+------+------+------|
 * |   2  |      |      |      |   5  |            |      |      |      |      |      |
 * |------+------+------+------+------|            |------+------+------+------+------|
 * |   3  |      |      |      |   6  |            |      |      |      |      |      |
 * `----------------------------------'            `----------------------------------'
 *                 ,---------------------.      ,------,---------------.
 *                 |       |       |      |     |      |       |       |
 *                 `---------------|      |     |      |-------+-------.
 *                                 |      |     |      |
 *                                 `------'     `------'
 */
[GAME_EXTRA] = LAYOUT
  (KC_1    ,_______,_______,_______,KC_4         ,_______ ,_______ ,_______ ,_______ ,_______
  ,KC_2    ,_______,_______,_______,KC_5         ,_______ ,_______ ,_______ ,_______ ,_______
  ,KC_3    ,_______,_______,_______,KC_6         ,_______ ,_______ ,_______ ,_______ ,_______
                   ,_______,_______,_______      ,_______,_______,_______
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |   7  |   8  |   9  |   `  |           |   ~  |   +  |   _  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   0  |   4  |   5  |   6  |      |           | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |   1  |   2  |   3  |      |           |   "  |   '  |      |      |   |  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|Adjust|    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[RAISE] = LAYOUT
  (_______,KC_7   ,KC_8   ,KC_9   ,KC_GRV     ,KC_TILD,KC_PLUS,KC_UNDS,KC_LBRC,KC_RBRC
  ,KC_0   ,KC_4   ,KC_5   ,KC_6   ,KC_MINS    ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______
  ,_______,KC_1   ,KC_2   ,KC_3   ,_______    ,KC_DQT ,KC_QUOT,_______,_______,KC_PIPE
                  ,_______,_______,MO_ADJ     ,_______,_______,_______ 
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |   \  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |Adjust|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[LOWER] = LAYOUT
  (KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,      KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN
  ,_______,_______,_______,KC_EQL ,KC_MINS,      _______,_______,_______,KC_LCBR,KC_RCBR
  ,_______,_______,_______,_______,_______,      KC_DQT ,KC_QUOT,_______,_______,KC_BSLS
                  ,_______,_______,_______,      MO_ADJ ,_______,_______
  ),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|      |      |      | Game |           |      |      |      |  F11 |  F12 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |Colmak|Qwerty|      |           |      |      |      |Taskmg|caltde|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[ADJUST] =  LAYOUT
  (KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,        KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10
  ,KC_CAPS,_______,_______,_______,TO_GAME,        _______,_______,_______,KC_F11 ,KC_F12
  ,RESET  ,_______,DF_CMAK,DF_QWRT,_______,        _______,_______,_______,TSKMGR ,CALTDEL
                  ,_______,_______,_______,        _______,_______,_______
  )
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /*
  switch (keycode) {
    case KC_QWRT:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<QWERTY);
      }
      return false;
      break;
    case KC_LOW:
      if (record->event.pressed) {
        layer_on(LOWER);
        update_tri_layer(LOWER, RAISE, ADJUST);
      } else {
        layer_off(LOWER);
        update_tri_layer(LOWER, RAISE, ADJUST);
      }
      return false;
      break;
    case KC_RISE:
      if (record->event.pressed) {
        layer_on(RAISE);
        update_tri_layer(LOWER, RAISE, ADJUST);
      } else {
        layer_off(RAISE);
        update_tri_layer(LOWER, RAISE, ADJUST);
      }
      return false;
      break;
    case KC_ADJ:
      if (record->event.pressed) {
        layer_on(ADJUST);
      } else {
        layer_off(ADJUST);
      }
      return false;
      break;
  }
  */
  return true;
}

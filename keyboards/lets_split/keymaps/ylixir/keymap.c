#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_bepo.h"

#include "minidox_40.h"
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers
  { QWERTY
  , BEPO
  , BEPO_LO
  , BEPO_UP
  , COLEMAK_DH
  , LOWER
  , RAISE
  , MOVE
  , ADJUST = 16
  };

enum custom_keycodes {
  KC_QWRT = SAFE_RANGE,
  KC_BEPO,
  KC_CMAK,
  KC_LOW,
  KC_RISE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

//double usage keys
#define ESCMOVE LT(MOVE, KC_ESC)
#define ENTMOVE LT(MOVE, KC_ENT)
#define SPLOWER LT(LOWER, KC_SPC)
#define SPRAISE LT(RAISE, KC_SPC)

#define A_CTL MT(MOD_LCTL, KC_A)
#define Z_SFT MT(MOD_LSFT, KC_Z)
#define ESC_ALT MT(MOD_LALT, KC_ESC)
#define TAB_GUI MT(MOD_LGUI, KC_TAB)

#define BS_LO LT(LOWER,KC_BSPC)
#define SPC_UP LT(RAISE,KC_SPC)

#define BP_LO LT(LOWER,KC_BSPC)
#define BP_UP LT(RAISE,KC_SPC)

#define ENT_ALT MT(MOD_RALT, KC_ENT)
#define DEL_GUI MT(MOD_RGUI, KC_DEL)
#define SLS_SFT MT(MOD_RSFT, KC_SLSH)
#define CLN_CTL MT(MOD_RCTL, KC_SCLN)
#define QUT_CTL MT(MOD_RCTL, KC_QUOT)
#define O_CTL MT(MOD_RCTL, KC_O)

#define TO_GAME TO(GAME)
#define NO_GAME TG(GAME)
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
[QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,  \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT , \
  ESCMOVE, KC_LGUI, XXXXXXX, XXXXXXX, KC_LALT, BS_LO, SPC_UP, KC_RALT, XXXXXXX, KC_MENU, KC_RGUI, ENTMOVE   \
),
/* Bépo
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
[BEPO] = LAYOUT_ortho_4x12( \
     BP_W, BP_B, BP_ECUT,    BP_P,    BP_O, BP_EGRV, BP_DCRC,    BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,  \
  KC_LCTL, BP_A,    BP_U,    BP_I,    BP_E, BP_COMM,    BP_C,    BP_T,    BP_S,    BP_R,    BP_N,    BP_M,  \
  KC_LSFT,BP_AGRV,  BP_Y,    BP_X,  BP_DOT,    BP_K, BP_APOS,    BP_Q,    BP_G,    BP_H,    BP_F,    BP_CCED, \
  ESCMOVE, KC_LGUI, BP_PERC, XXXXXXX, KC_LALT, BP_LO, BP_UP, KC_RALT, XXXXXXX, KC_MENU, KC_RGUI, ENTMOVE   \
),
[BEPO_UP] = LAYOUT_ortho_4x12( \
  BP_HASH, BP_B, BP_ECUT,    BP_P,    BP_O, BP_EGRV, BP_DCRC,    BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,  \
  KC_LCTL, BP_1,    BP_2,    BP_3,    BP_4, BP_5,    BP_6,    BP_7,    BP_8,    BP_9,    BP_0,    BP_DEGR,  \
  KC_LSFT,BP_AGRV,  BP_Y,    BP_X,  BP_DOT,    BP_K, BP_APOS,    BP_Q,    BP_G,    BP_H,    BP_F,    BP_CCED, \
  ESCMOVE, KC_LGUI, XXXXXXX, XXXXXXX, KC_LALT, BP_LO, BP_UP, KC_RALT, XXXXXXX, KC_MENU, KC_RGUI, ENTMOVE   \
),
[BEPO_LO] = LAYOUT_ortho_4x12( \
  BP_DLR, BP_B, BP_ECUT,    BP_P,    BP_O, BP_EGRV, BP_DCRC,    BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,  \
  KC_LCTL, BP_DQOT,    BP_LGIL,    BP_RGIL,    BP_LPRN, BP_RPRN,    BP_AT,    BP_PLUS,    BP_MINS,    BP_SLSH,    BP_ASTR,    BP_EQL,  \
  KC_LSFT,BP_AGRV,  BP_Y,    BP_X,  BP_DOT,    BP_K, BP_APOS,    BP_Q,    BP_G,    BP_H,    BP_F,    BP_CCED, \
  ESCMOVE, KC_LGUI, XXXXXXX, XXXXXXX, KC_LALT, BP_LO, BP_UP, KC_RALT, XXXXXXX, KC_MENU, KC_RGUI, ENTMOVE   \
),

/* Colemak Mod-DH
 *
 * ,----------------------------------.            ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |            |   J  |   L  |   U  |   Y  |   '  |
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
[COLEMAK_DH] = LAYOUT_MINI_DOX
  (KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B         ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_QUOT
  ,A_CTL   ,KC_R    ,KC_S    ,KC_T    ,KC_G         ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,O_CTL
  ,Z_SFT   ,KC_X    ,KC_C    ,KC_D    ,KC_V         ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,SLS_SFT
                    ,TAB_GUI ,ESC_ALT ,BS_LO        ,SPC_UP  ,ENT_ALT ,DEL_GUI
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
/*
[LOWER] = LAYOUT_ortho_4x12( \
    _______,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL ,    \
    KC_ESC ,_______,_______,_______,KC_EQL ,KC_MINS,_______,KC_LT  ,KC_GT  ,KC_LCBR,KC_RCBR,KC_PIPE,   \
    _______,_______,_______,_______,_______,_______,_______,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
    _______,_______,_______,_______,_______,_______,MO_ADJ ,_______,KC_MNXT,KC_VOLD,KC_VOLU,KC_MPLY    \
),
*/
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
/*
[RAISE] = LAYOUT_ortho_4x12( \
    _______,KC_0   ,KC_7   ,KC_8   ,KC_9   ,KC_GRV ,KC_TILD,KC_PLUS,KC_UNDS,KC_LBRC,KC_RBRC,KC_INS ,  \
    _______,_______,KC_4   ,KC_5   ,KC_6   ,_______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_RBRC,KC_BSLS, \
    _______,_______,KC_1   ,KC_2   ,KC_3   ,_______,_______,KC_NUHS,KC_NUBS,_______,_______,_______, \
    KC_ESC ,_______,_______,_______,_______,MO_ADJ ,_______,_______,KC_MNXT,KC_VOLD,KC_VOLU,KC_MPLY  \
),
*/
/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |   7  |   8  |   9  |   `  |           |   ~  |   +  |   _  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   0  |   4  |   5  |   6  |      |           | Left | Down |  Up  | Right|   :  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |   1  |   2  |   3  |      |           |   "  |   '  |      |      |   |  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|Adjust|    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[RAISE] = LAYOUT_MINI_DOX
  (_______,KC_7   ,KC_8   ,KC_9   ,KC_GRV     ,KC_TILD,KC_PLUS,KC_UNDS,KC_LBRC,KC_RBRC
  ,KC_0   ,KC_4   ,KC_5   ,KC_6   ,KC_MINS    ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_COLN
  ,_______,KC_1   ,KC_2   ,KC_3   ,_______    ,_______,_______,_______,_______,KC_PIPE
                  ,_______,_______,MO_ADJ     ,_______,_______,_______ 
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |   <  |   >  |   {  |   }  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |   \  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |Adjust|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[LOWER] = LAYOUT_MINI_DOX
  (KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC      ,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN
  ,_______,_______,_______,KC_EQL ,KC_MINS      ,KC_LT  ,KC_GT  ,KC_LCBR,KC_RCBR,KC_SCLN
  ,_______,_______,_______,_______,_______      ,_______,_______,_______,_______,KC_BSLS
                  ,_______,_______,_______      ,MO_ADJ ,_______,_______
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
[MOVE] =  LAYOUT_ortho_4x12( \
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
 * |       |       |Colmak |Qwerty |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[ADJUST] =  LAYOUT_ortho_4x12( \
  KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,   \
  RESET  ,_______,MU_TOG ,AU_ON  ,AU_OFF ,AG_NORM,AG_SWAP,KC_QWRT ,_______,_______,_______,_______, \
  _______,_______,KC_CMAK,KC_QWRT,KC_BEPO,_______,_______,_______,_______,_______,_______,_______,  \
  KC_ESC, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_ENT    \
),


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_bepo[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_coin[][2]    = SONG(COIN_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /*
    case SPC_UP:
      #ifdef AUDIO_ENABLE
        PLAY_SONG(tone_coin);
      #endif
      return true;
    */
    case KC_QWRT:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<QWERTY);
      }
      return false;
    case KC_BEPO:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_bepo);
        #endif
        persistent_default_layer_set(1UL<<BEPO);
      }
      return false;
    case KC_CMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<COLEMAK_DH);
      }
      return false;
    case KC_LOW:
      if (record->event.pressed) {
        layer_on(LOWER);
        update_tri_layer(LOWER, RAISE, ADJUST);
      } else {
        layer_off(LOWER);
        update_tri_layer(LOWER, RAISE, ADJUST);
      }
      return false;
    case KC_RISE:
      if (record->event.pressed) {
        layer_on(RAISE);
        update_tri_layer(LOWER, RAISE, ADJUST);
      } else {
        layer_off(RAISE);
        update_tri_layer(LOWER, RAISE, ADJUST);
      }
      return false;
  }
  return true;
}

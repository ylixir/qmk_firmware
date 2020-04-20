#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

#include "minidox_40.h"
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers
  { QWERTY
  , COLEMAK_DH
  , LOWER
  , RAISE
  , MOVE
  , ADJUST = 16
  };

enum custom_keycodes {
  KC_QWRT = SAFE_RANGE,
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

#define SFTLBRC MT(MOD_LSFT, KC_LBRC)

#define GRV_GUI MT(MOD_RGUI, KC_GRV)
#define SFTRBRC MT(MOD_RSFT, KC_RBRC)

#define ESC_ALT MT(MOD_LALT, KC_ESC)
#define TAB_GUI MT(MOD_LGUI, KC_TAB)
#define BS_LO LT(LOWER,KC_BSPC)
#define SPC_LO LT(LOWER,KC_SPC)
#define SPC_UP LT(RAISE,KC_SPC)
#define ENT_ALT MT(MOD_RALT, KC_ENT)
#define DEL_GUI MT(MOD_RGUI, KC_DEL)

#define MO_ADJ MO(ADJUST)

#define combo_entry(key,a,b) [key]={a,b,COMBO_END}
#define combo_action(key) [key]=COMBO_ACTION(combo_entries[key])

const uint16_t PROGMEM combo_entries[COMBO_AUTO_COUNT][3] = {
  /* shared */
  combo_entry(SH_1, KC_Q, KC_A),

  /* qwerty */
  combo_entry(QW_2, KC_W, KC_S),
  combo_entry(QW_3, KC_E, KC_D),
  combo_entry(QW_4, KC_R, KC_F),
  combo_entry(QW_5, KC_T, KC_G),
  combo_entry(QW_6, KC_Y, KC_H),
  combo_entry(QW_7, KC_U, KC_J),
  combo_entry(QW_8, KC_I, KC_K),
  combo_entry(QW_9, KC_O, KC_L),
  combo_entry(QW_0, KC_P, KC_SCLN),

  /* colemak */
  combo_entry(CK_2, KC_W, KC_R),
  combo_entry(CK_3, KC_F, KC_S),
  combo_entry(CK_4, KC_P, KC_T),
  combo_entry(CK_5, KC_B, KC_G),
  combo_entry(CK_6, KC_J, KC_M),
  combo_entry(CK_7, KC_L, KC_N),
  combo_entry(CK_8, KC_U, KC_E),
  combo_entry(CK_9, KC_Y, KC_I),
  combo_entry(CK_0, KC_QUOT, KC_O),
  combo_entry(CK_TILDE, KC_TAB, KC_Q),
  combo_entry(CK_DOUBLE_QUOTE, KC_QUOT, KC_GRV),
  combo_entry(CK_LT, KC_P, KC_B),
  combo_entry(CK_GT, KC_J, KC_L),
  combo_entry(CK_LCBR, KC_T, KC_G),
  combo_entry(CK_RCBR, KC_M, KC_N),
  combo_entry(CK_MINUS, KC_D, KC_V),
  combo_entry(CK_PLUS, KC_K, KC_H),
  combo_entry(CK_SCLN, KC_I, KC_DOT),
  combo_entry(CK_UNDS, KC_O, KC_SLSH),
};
combo_t key_combos[COMBO_AUTO_COUNT] = {
  [SH_1] = COMBO(combo_entries[SH_1], KC_1),

  combo_action(QW_2),
  combo_action(QW_3),
  combo_action(QW_4),
  combo_action(QW_5),
  combo_action(QW_6),
  combo_action(QW_7),
  combo_action(QW_8),
  combo_action(QW_9),
  combo_action(QW_0),

  combo_action(CK_2),
  combo_action(CK_3),
  combo_action(CK_4),
  combo_action(CK_5),
  combo_action(CK_6),
  combo_action(CK_7),
  combo_action(CK_8),
  combo_action(CK_9),
  combo_action(CK_0),
  combo_action(CK_TILDE),
  combo_action(CK_DOUBLE_QUOTE),
  combo_action(CK_LT),
  combo_action(CK_GT),
  combo_action(CK_LCBR),
  combo_action(CK_RCBR),
  combo_action(CK_MINUS),
  combo_action(CK_PLUS),
  combo_action(CK_SCLN),
  combo_action(CK_UNDS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+---1--+---2--+---3--+---4--+---5------6--+---7--+---8--+---9--+---0--+------|
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
  ESCMOVE, KC_LGUI, XXXXXXX, XXXXXXX, KC_LALT, SPC_LO,   SPC_UP,  KC_RALT, XXXXXXX, KC_MENU, KC_RGUI, ENTMOVE   \
),
/* Colemak Mod-DH

,------------------------------------------.            ,------------------------------------------. 
|  Tab |~|  Q  |   W  |   F  |   P (<)  B  |            |   J (>)  L  |   U  |   Y  |  '  |"|  `   | 
|-------+---1--+---2--+---3--+---4--+---5--|            |---6--+---7--+---8--+---9--+--0---+-------| 
| Ctl ( |   A  |   R  |   S  |   T ({)  G  |            |   M (})  N  |   E  |   I  |  O   | ) Ctl | 
|-------+------+------+------+------+------|            |------+------+------+--(;)-+-(_)--+-------| 
|Shft [ |   Z  |   X  |   C  |   D (-)  V  |            |   K (+)  H  |   ,  |   .  |   /  | ] Shft| 
|-------+----------------------------------'            `----------------------------------+-------| 
|  Esc  |      |      |,---------------------.       ,------,---------------.|      |      | Enter |
|  Move |-------------'|Tab/Gui|Esc/Alt|      |      |      |Ent/Alt|Del/Gui|`-------------|  Move |
`--------              `---------------|BckSpc|      |Space |-------+-------.              --------'
                                       | Lower|      |Raise |                    
                                       `------'      `------'                    
 */
[COLEMAK_DH] = LAYOUT_ortho_4x12
(KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B       ,KC_J  ,KC_L   ,KC_U   ,KC_Y   ,KC_QUOT,KC_GRV
,KC_LCPO,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G       ,KC_M  ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_RCPC
,SFTLBRC,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V       ,KC_K  ,KC_H   ,KC_COMM,KC_DOT ,KC_SLSH,SFTRBRC
,ESCMOVE,_______,_______,TAB_GUI,ESC_ALT,BS_LO      ,SPC_UP,ENT_ALT,DEL_GUI,_______,_______,ENTMOVE
),

/* Raise
 *
,------------------------------------------.           ,------------------------------------------.
|  Tab  |      |   7  |   8  |   9  |      |           |      |      |   _  |      |      |   `   |
|-------+------+------+------+------+------|           |------+------+------+------+------+-------|
| Ctl ( |   0  |   4  |   5  |   6  |      |           | Left | Down |  Up  | Right|   :  | ) Ctl |
|-------+------+------+------+------+------|           |------+------+------+------+------+-------|
|Shft [ |      |   1  |   2  |   3  |      |           |      |      |      |      |   |  | ] Shft|
|-------+----------------------------------'           `----------------------------------+-------|
|  Esc  |      |      |  ,--------------------.    ,------,-------------.   |      |      | Enter |
|  Move |-------------'  |      |      |      |    |      |      |      |   `-------------+  Move |
`-------'                `-------------|Adjust|    |      |------+------'                 `-------'
                                       |      |    |      |
                                       `------'    `------'
 */
[RAISE] = LAYOUT_ortho_4x12
(_______,_______,KC_7   ,KC_8   ,KC_9   ,_______    ,_______,_______,KC_UNDS,_______,_______,_______
,_______,KC_0   ,KC_4   ,KC_5   ,KC_6   ,_______    ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_COLN,_______
,_______,_______,KC_1   ,KC_2   ,KC_3   ,_______    ,_______,_______,_______,_______,KC_PIPE,_______
,_______,_______,_______,_______,_______,MO_ADJ     ,_______,_______,_______,_______,_______,_______
),

/* Lower
 *
,------------------------------------------.           ,------------------------------------------.
|Gui Tab|   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |      |      | ` Gui |
|-------+------+------+------+------+------|           |------+------+------+------+------+-------|
|       |      |      |      |   =  |   -  |           |      |      |      |      |   ;  |       |
|-------+------+------+------+------+------|           |------+------+------+------+------+-------|
|       |      |      |      |      |      |           |      |      |      |      |   \  |       |
|-------+----------------------------------'           `----------------------------------+-------|
|  Esc  |                ,--------------------.    ,------,-------------.                 | Enter |
|  Move |                |      |      |      |    |      |      |      |                 |  Move |
`--------                `-------------|      |    |Adjust|------+------.                 --------'
                                       |      |    |      |
                                       `------'    `------'
 */
[LOWER] = LAYOUT_ortho_4x12
  (_______,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC      ,KC_CIRC,KC_AMPR,KC_ASTR,_______,_______,_______
  ,_______,_______,_______,_______,KC_EQL ,KC_MINS      ,_______,_______,_______,_______,KC_SCLN,_______
  ,_______,_______,_______,_______,_______,_______      ,_______,_______,_______,_______,KC_BSLS,_______
  ,_______,_______,_______,_______,_______,_______      ,MO_ADJ ,_______,_______,_______,_______,_______
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
  _______, KC_MS_U, KC_MS_BTN4, KC_MS_UP,   KC_MS_BTN5,  _______,    _______,    _______, _______, _______, _______, _______, \
  _______, KC_MS_D, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,    KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
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
  RESET  ,_______,_______,AU_ON  ,AU_OFF ,AG_NORM,AG_SWAP,KC_QWRT ,_______,_______,_______,MU_TOG, \
  _______,_______,KC_CMAK,KC_QWRT,_______,_______,_______,_______,_______,_______,_______,MU_MOD,  \
  KC_ESC, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_ENT    \
),


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(GAME_ON);
float tone_colemak[][2]    = SONG(GAME_OFF);
float tone_coin[][2]    = SONG(COIN_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

#define combo_case(layer,code) case layer##_##code: tap_code16(KC_##code); break
void process_colemak_combos(uint8_t combo_index) {
  switch (combo_index) {
    combo_case(CK,2);
    combo_case(CK,3);
    combo_case(CK,4);
    combo_case(CK,5);
    combo_case(CK,6);
    combo_case(CK,7);
    combo_case(CK,8);
    combo_case(CK,9);
    combo_case(CK,0);
    combo_case(CK,TILDE);
    combo_case(CK,DOUBLE_QUOTE);
    combo_case(CK,LT);
    combo_case(CK,GT);
    combo_case(CK,LCBR);
    combo_case(CK,RCBR);
    combo_case(CK,MINUS);
    combo_case(CK,PLUS);
    combo_case(CK,SCLN);
    combo_case(CK,UNDS);
}
}
void process_qwerty_combos(uint8_t combo_index) {
  switch (combo_index) {
    combo_case(QW,2);
    combo_case(QW,3);
    combo_case(QW,4);
    combo_case(QW,5);
    combo_case(QW,6);
    combo_case(QW,7);
    combo_case(QW,8);
    combo_case(QW,9);
    combo_case(QW,0);
  }
}


void process_combo_event(uint8_t combo_index, bool pressed) {
  if (!pressed) return;

  if (default_layer_state & 1UL << COLEMAK_DH) process_colemak_combos(combo_index);
  else process_qwerty_combos(combo_index);
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

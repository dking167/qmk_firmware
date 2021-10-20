#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number {
  _QWERTY = 0,
  _COLEMAKDH,
  _DVORAK,
  _LOWER,
  _RAISE,
  _NUMPAD,
  _ADJUST,
  _MOUSE,
};

#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAKDH)
#define DVORAK DF(_DVORAK)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUMPAD TG(_NUMPAD)
#define ADJUST MO(_ADJUST)
#define MOUSE TG(_MOUSE)
#define COPY LCTL(KC_C)
#define CDEL LCTL_T(KC_DEL)
#define SBSP LSFT_T(KC_BSPC)

char wpm_str[10];

enum td_keycodes {
TD_CPY //TAP TO COPY & HOLD TO PASTE
};

qk_tap_dance_action_t tap_dance_actions[] = {
  //[TD_CPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altlp_finished, altlp_reset)
  [TD_CPY] = ACTION_TAP_DANCE_DOUBLE(RCTL(KC_C), RCTL(KC_V)), 
};

/*
typedef enum {
  //TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD
} td_state_t;

static td_state_t td_state;

td_state_t cur_dance(qk_tap_dance_state_t *state);

void altlp_finished(qk_tap_dance_state_t *state, void *user_data);
void altlp_reset(qk_tap_dance_state_t *state, void *user_data);
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, TD(TD_CPY),       MOUSE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, NUMPAD, \
                        KC_LALT, CDEL, LOWER,     SBSP,        KC_SPC,   RAISE, KC_ENT, KC_RGUI \
),
/* COLEMAKDH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_COLEMAKDH] = LAYOUT( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS, \
  KC_TRNS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                     KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_TRNS, \
  KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_TRNS,  KC_TRNS,  KC_K,    KC_H,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
),
/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_DVORAK] = LAYOUT( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_TRNS, \
  KC_TRNS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_TRNS, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, KC_TRNS,  KC_TRNS,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_TRNS, \
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
  KC_TRNS, KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,                     KC_NO,   KC_LPRN,   KC_RPRN,   KC_PIPE,  KC_NO,  KC_TRNS, \
  KC_TRNS, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,                     KC_NO,   KC_LCBR,   KC_RCBR,   KC_BSLS,  KC_NO,  KC_NO, \
  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, _______, _______,   KC_NO,   KC_LBRC,   KC_RBRC,   KC_NO,    KC_NO,  KC_TRNS, \
                             _______, _______, _______, _______, _______, RAISE, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |   -  |   =  |   [  |   ]  |   \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | VOL+ | PLAY | NEXT | P-UP |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | VOL- | STOP | PREV | P-DN |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                     KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______, _______, _______, _______, _______,                     KC_NO,   KC_VOLU, KC_MPLY, KC_MNXT, KC_PGUP, KC_NO, \
  _______, _______, _______, _______, _______, _______,  _______, _______,  KC_NO,   KC_VOLD, KC_MSTP, KC_MPRV, KC_PGDN, KC_TRNS, \
                             _______, _______, LOWER,  _______, _______,  _______, _______, _______ \
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      | NMLK |   /  |   *  |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | HOME |  F9  | F10  |  F11 |  F12 | PRSC |                    |      |   7  |   8  |   9  |  +   | BKSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | END  |  F5  |  F6  |  F7  |  F8  | SCLK |-------.    ,-------|      |   4  |   5  |   6  |  ,   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  PSE |-------|    |-------|      |   1  |   2  |   3  |  =   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |   0  | DEC  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NUMPAD] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     KC_NO,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, \
  KC_HOME, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,                     KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_BSPC, \
  KC_END,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_SLCK,                     KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PCMM, KC_NO, \
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PAUS,  _______, _______,  KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_TRNS, \
                             _______, _______, _______,  _______, _______,  _______, KC_P0,   KC_PDOT \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | RESET|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |DF(0) |DF(1) |DF(2) |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, QWERTY,  COLEMAK, DVORAK,  XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  ),
  /* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |DF(0) |DF(1) |DF(2) |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_MOUSE] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,   KC_NO, \
  KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_CAPS,                   KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, \
  KC_NO,   KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_INS,                     KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  KC_BTN1, KC_BTN2, KC_BTN3 \
  )
};
/*
td_state_t cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1){
    if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
    else return TD_SINGLE_HOLD;
  }
  else return TD_UNKNOWN;
}

void altlp_finished(qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state){
    case TD_SINGLE_TAP:
      register_mods(KC_LCTL);
      register_code(KC_C);
      break;
    case TD_SINGLE_HOLD:
      register_mods(KC_LCTL);
      register_code(KC_V);
      break;
    case TD_UNKNOWN:
      break;
    default: //Not in examples, move this if it breaks
      break;
  }
}

void altlp_reset(qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state){
    case TD_SINGLE_TAP:
      unregister_mods(KC_LCTL);
      unregister_code(KC_C);
      break;
    case TD_SINGLE_HOLD:
      unregister_mods(KC_LCTL);
      unregister_code(KC_V);
      break;
    default: //Not in examples, move this if it breaks
      break;
  }
}*/



layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
  //return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
    if (is_keyboard_master()) {
        switch (get_highest_layer(layer_state)) {
            case _RAISE:
                oled_write_P(PSTR("Raise\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("Lower\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            case _NUMPAD:
                oled_write_P(PSTR("Numpad\n"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("Mouse\n"), false);
                break;
            default:
                switch (biton32(default_layer_state)) {
                    case _QWERTY:
                        oled_write_P(PSTR("OWERTY\n"), false);
                        break;
                    case _COLEMAKDH:
                        oled_write_P(PSTR("Colemak DH\n"), false);
                        break;
                    case _DVORAK:
                        oled_write_P(PSTR("Dvorak\n"), false);
                        break;
                    default:
                        oled_write_ln_P(PSTR("Undefined\n"), false);
                        break;
                }
        }
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

        sprintf(wpm_str, "\nWPM: %03d", get_current_wpm()); //add /n after WPM: if you rotate.
        oled_write(wpm_str, false);

    } else {
        if (get_current_wpm() >= 15) {
            sprintf(wpm_str, "\nWPM: %03d", get_current_wpm());
            oled_write(wpm_str, false);
        } else {
            oled_write(read_logo(), false);
        }
    }
}
#endif // OLED_DRIVER_ENABLE
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}*/

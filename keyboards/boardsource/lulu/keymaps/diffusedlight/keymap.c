// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum layers {
    _ALPHA,
    _NUM,
    _SYMBOL,
    _NAV,
    _VIM,
    _MEDIA,
    _FUN,
    _GAME
};

// Layout control for swapping between game and base layers
#define SW_GAME DF(_GAME)
#define SW_BASE DF(_ALPHA)

// Aliases for home row mods.

//    Left Side
#define HOME_I LGUI_T(KC_I)
#define HOME_E LALT_T(KC_E)
#define HOME_A LCTL_T(KC_A)
#define HOME_H LSFT_T(KC_H)

//    Right Side 
// mirroring left side mods so both hands implement same functionality
// no AltGr bull 
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME_R LALT_T(KC_R)
#define HOME_N LGUI_T(KC_N)

// Layer swapping TODO: FINISH IMPLEMENTATION
#define T_MEDIA LT(_MEDIA, KC_ESC)
#define T_NAV   LT(_NAV, KC_SPC)
#define T_VIM   LT(_VIM, KC_TAB)
#define T_SYM   LT(_SYMBOL, KC_ENT)
#define T_NUM   LT(_NUM, KC_BSPC)
#define T_FUN   LT(_FUN, QK_REP)

// Oneshot Shift
#define OS_LSFT OSM(MOD_LSFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*  Alpha Layout - Mirrored Gallium v2
 * , U O F J - V C D L B
 * I E A H Y - G S T R N 
 * . ; ' P K - Z W M Q X
 *
 * Thumbs:
 * OS_SFT ESC SPACE TAB - ENTER BKSPC REPEAT OS_SFT
 * 
 * HOME ROW MODS: 
 * G A C S X - S C A G
 *
 * ENCODER KEYS?
 * _ - \
 */

// TODO: Update the layout to above
 [_ALPHA] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SW_GAME,
  XXXXXXX, KC_COMM,    KC_U,    KC_O,    KC_F,    KC_J,                     KC_V,    KC_C,    KC_D,    KC_L,    KC_B, XXXXXXX,
  XXXXXXX,  HOME_I,  HOME_E,  HOME_A,  HOME_H,    KC_Y,                     KC_G,  HOME_S,  HOME_T,  HOME_R,  HOME_N, XXXXXXX,
  XXXXXXX,  KC_DOT, KC_SCLN, KC_QUOT,    KC_P,    KC_K,KC_MINUS, KC_BSLS,   KC_Z,    KC_W,    KC_M,    KC_Q,    KC_X, XXXXXXX,
                             OS_LSFT, T_MEDIA,   T_NAV,   T_VIM,   T_SYM,  T_NUM,   T_FUN, OS_LSFT
),

/*
 * Num Layout - HR Mods Right Side
 * _ # 7 8 9 / - _ _ _ _ _
 * _ & 4 5 6 = - _ S C A G
 * _ * 1 2 3 \ - _ * _ _ _
 *   _ ` 0 -
 */

[_NUM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_HASH,    KC_7,    KC_8,    KC_9, KC_SLSH,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_AMPR,    KC_4,    KC_5,    KC_6,  KC_EQL,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_HYPR,
  XXXXXXX, KC_ASTR,    KC_1,    KC_2,    KC_3, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX,  KC_GRV,    KC_0, KC_MINS, XXXXXXX, _______, XXXXXXX, XXXXXXX
),
/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ^  |   <  |  {   |  }   |  >   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   $  |   !  |  (   |  )   |  +   |-------.    ,-------|      | SHIFT| CTRL | ALT  | SUPER|HYPER |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   %  |   @  |  [   |  ]   |  |   |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |   *  |   =  | /   _   /       \ SYM  \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */


[_SYMBOL] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_CIRC,   KC_LT,  KC_LCBR, KC_RCBR,   KC_GT,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_DLR, KC_EXLM,  KC_LPRN, KC_RPRN, KC_PLUS,                    XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_HYPR,
  XXXXXXX, KC_PERC,   KC_AT,  KC_LBRC, KC_RBRC, KC_PIPE, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              XXXXXXX, KC_ASTR,  KC_EQL, KC_UNDS, _______,  XXXXXXX, XXXXXXX, XXXXXXX
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | DEL  |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | HYPER| SUPER|  ALT | CTRL | SHIFT|      |-------.    ,-------| LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------|       |    |  CL*  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| HOME | INS  |      | END  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      | NAV  | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_NAV] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                    KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CW_TOGG,  KC_HOME,  KC_INS, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
  ),
/* VIM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  DEL |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | HYPER| SUPER|  ALT | CTRL | SHIFT|      |-------.    ,-------|  H   |   J  |   K  |  L   |      |      |
 * |------+------+------+------+------+------|       |    |  CL*  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| HOME |  INS |      |  END |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /  VIM  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_VIM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_H,    KC_J,    KC_K,    KC_L, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CW_TOGG, KC_HOME,  KC_INS, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
/* MEDIA TODO: SHIFT INNER ROW ON LEFT SIDE TO OUTER COLUMN MOVE EVERYTHING ONE LEFT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | RGB.T| RGB.F| V.UP | V.DWN| RGB.F|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | HYPER| SUPER|  ALT | CTRL | SHIFT|      |-------.    ,-------| P.SCN| S.BWD| START| STOP | S.FWD|      |
 * |------+------+------+------+------+------|       |    | V.MUTE|------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | MEDIA|      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_MEDIA] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_TOG, RGB_MOD, KC_VOLU, KC_VOLD, RGB_RMOD, XXXXXXX,
  KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_PSCR, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
/* FUN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | F12  |  F7  |  F8  |  F9  |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | F11  |  F4  |  F5  |  F6  |      |-------.    ,-------|      | SHIFT| CTRL | ALT  | SUPER|HYPER |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | F10  |  F1  |  F2  |  F3  |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | MENU |  SPC | /  TAB  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      | FUN  |
 *                   `----------------------------'           '------''--------------------'
 */


  [_FUN] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F12, KC_F7, KC_F8, KC_F9, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F11, KC_F4, KC_F5, KC_F6, XXXXXXX,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_HYPR,
  XXXXXXX, KC_F10, KC_F1, KC_F2, KC_F3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, KC_APP, KC_SPC, KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),
/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |  5   |                    |   6  |   7  |   8  |   9  |   0  | GTB  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   E  |   R  |  T   |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CTRL |   A  |   S  |   D  |   F  |  G   |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |SHIFT |   Z  |   X  |   C  |   V  |  B   |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | SHIFT|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | ALT  |  SPC | /  TAB  /       \ ENTER\  | BKSPC| SUPER|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */


  [_GAME] = LAYOUT(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                    KC_6,    KC_7,     KC_8,    KC_9,    KC_0, SW_BASE,
  KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T,                    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,KC_MINUS,
  KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                   KC_H,    KC_J,     KC_K,    KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX, XXXXXXX, KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_GRV,
                _______, KC_LALT,  KC_SPC,KC_TAB,  KC_ENT,   KC_BSPC, KC_LGUI,  _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  
  // macros here

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

// Combos - Stolen from urobs ZMK Config
enum combos {
  // Left Hand Horizontal
  WE_ESC,
  ER_ENT,  
  SD_TAB,
  DF_REP,
};

// Left Hand Horizontal
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
  [WE_ESC] = COMBO(we_combo, KC_ESC),
  [ER_ENT] = COMBO(er_combo, KC_ENT),
  [SD_TAB] = COMBO(sd_combo, KC_TAB),
  [DF_REP] = COMBO(df_combo, QK_REP),
}; 
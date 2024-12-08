// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum layers {
    _ALPHA,
    _NUM,
    _SYM,
    _NAV,
    _MEDIA,
    _FUN,
    _GAME
};

// Layout control for swapping between game and base layers
#define SW_GAME DF(_GAME)
#define SW_BASE DF(_ALPHA)

// Aliases for home row mods.

//    Left Side
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

//    Right Side 
// mirroring left side mods so both hands implement same functionality
// no AltGr bull, we use RSFT toggle to enable BOTH_SHIFTS_TURN_ON_CAPS_WORD
#define HOME_J    RSFT_T(KC_J)
#define HOME_K    LCTL_T(KC_K)
#define HOME_L    LALT_T(KC_L)
#define HOME_SCLN LGUI_T(KC_SCLN)

#define T_MEDIA LT(_MEDIA, KC_ESC)
#define T_NAV   LT(_NAV, KC_SPC)
#define T_SYM   LT(_SYM, KC_ENT)
#define T_NUM   LT(_NUM, KC_BSPC)
#define T_FUN   LT(_FUN, QK_REP)

// Oneshot Shift
#define OS_LSFT OSM(MOD_LSFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*  Alpha Layout - QWERTY
 *  TODO: Do we need the REP on the right thumb cluster
 *
 * XXX XXX XXX XXX XXX XXX     -     XXX XXX XXX XXX XXX GME
 * XXX  Q   W   E   R   T      -       Y   U   I   O   P XXX
 * REP  A   S   D   F   G      -       H   J   K   L   ; REP
 * XXX  Z   X   C   V   B  HYP - HYP   N   M   ,   .   / XXX
 *             OSS ESC SPC TAB - ENT  BKS REP OSS
 *
 * HOME ROW MODS: 
 * GACS - SCAG
 * OSS = One Shot Shift
 */

 [_ALPHA] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SW_GAME,
  XXXXXXX,  KC_Q,    KC_W,    KC_E,      KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  QK_REP,   HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                     KC_H,  HOME_J,  HOME_K,  HOME_L, HOME_SCLN,QK_REP,
  XXXXXXX,  KC_Z,    KC_X,    KC_C,      KC_V,    KC_B, KC_HYPR, KC_HYPR,   KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
                             OS_LSFT, T_MEDIA,   T_NAV,  KC_TAB,  T_SYM,  T_NUM,   T_FUN, OS_LSFT
),

/*  Symbol Layout - Miryoku Based 
 *
 * XXX XXX XXX XXX XXX XXX      -     XXX XXX XXX XXX XXX XXX
 * XXX  {   &   *   (   }       -     XXX XXX XXX XXX XXX XXX
 * XXX  ~   $   %   ^   +       -     XXX SFT CTL ALT GUI XXX
 * XXX  |   !   @   #   "  XXX  - HYP XXX XXX XXX XXX XXX XXX
 *             XXX  (   )   _   - ___ XXX XXX XXX	     
 * 
 */

 [_SYM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LCBR,  KC_AMPR,KC_ASTR, KC_LPRN, KC_RCBR,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_TILD,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                  XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  XXXXXXX, KC_PIPE, KC_EXLM,   KC_AT, KC_HASH, KC_DQT, XXXXXXX, KC_HYPR,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, _______,XXXXXXX, XXXXXXX, XXXXXXX
),


/*
 * Num Layout - HR Mods Right Side
 *
 * XXX XXX XXX XXX XXX XXX      -     XXX XXX XXX XXX XXX XXX
 * XXX  [   7   8   9   ]       -     XXX XXX XXX XXX XXX XXX
 * XXX  `   4   5   6   =       -     XXX SFT CTL ALT GUI XXX
 * XXX  \   1   2   3   '  XXX  - HYP XXX XXX XXX XXX XXX XXX
 *             XXX  .   0   -   - XXX ___ XXX XXX
 * 
 */

[_NUM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_GRV,    KC_4,    KC_5,    KC_6,  KC_EQL,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  XXXXXXX, KC_BSLS,    KC_1,    KC_2,    KC_3, KC_QUOT, XXXXXXX, KC_HYPR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX,  KC_DOT,    KC_0, KC_MINS, XXXXXXX, _______, XXXXXXX, XXXXXXX
),

/* NAV
 *
 * XXX XXX XXX XXX XXX XXX      -     XXX XXX XXX XXX XXX XXX
 * XXX XXX XXX XXX XXX XXX      -     DEL XXX XXX XXX XXX XXX
 * XXX XXX GUI ALT CTL SFT      -     CW  LFT DWN  UP RIT XXX
 * XXX XXX XXX XXX XXX XXX XXX  - XXX XXX HOM INS XXX END XXX
 *             XXX XXX ___ XXX  - XXX XXX XXX XXX
 * 
 * CW = Caps Word 
 */

  [_NAV] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                    KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX, 
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HYPR, XXXXXXX,  XXXXXXX, KC_HOME,  KC_INS, XXXXXXX,  KC_END, XXXXXXX,
                             XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
  ),

/* MEDIA
 *
 * XXX XXX XXX XXX XXX XXX      -     XXX XXX XXX XXX XXX XXX
 * XXX XXX XXX XXX XXX XXX      -     XXX VUP VDN XXX XXX XXX
 * XXX GUI ALT CTL SFT XXX      -     PSC PRV PLY STP NXT XXX
 * XXX XXX XXX XXX XXX XXX HYP  - MUT XXX XXX XXX XXX XXX XXX
 *             XXX ___ XXX XXX  - XXX XXX XXX XXX
 * 
 * PSC = Print Screen
 */

  [_MEDIA] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_VOLU, KC_VOLD, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_PSCR, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HYPR, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

/* FUN
 *
 * XXX XXX XXX XXX XXX XXX       -     XXX XXX XXX XXX XXX XXX
 * XXX F12  F7  F8  F9 XXX       -     XXX XXX XXX XXX XXX XXX
 * XXX F11  F4  F5  F6 XXX       -     XXX SFT CTL ALT GUI XXX
 * XXX F10  F1  F2  F3 XXX XXX   - XXX XXX XXX XXX XXX XXX XXX
 *             XXX APP SPC TAB   - ___ XXX XXX XXX
 * 
 */


  [_FUN] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_HYPR,
  XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             XXXXXXX,  KC_APP,  KC_SPC,  KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, _______
  ), 

/* GAME
 *
 * ESC  1   2   3   4   5        -      6   7   8   9   0  SWB
 * GRV  Q   W   E   R   T       -       Y   U   I   O   P   - 
 * CTL  A   S   D   F   G       -       H   J   K   L   ;   '
 * SFT  Z   X   C   V   B  XXX   - XXX  N   M   ,   .   /   ` 
 *             ALT ALT SPC TAB   - ENT BSP GUI XXX
 * 
 */


  [_GAME] = LAYOUT(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                    KC_6,    KC_7,     KC_8,    KC_9,    KC_0, SW_BASE,
  KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T,                    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,KC_MINUS,
  KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                   KC_H,    KC_J,     KC_K,    KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, XXXXXXX, XXXXXXX, KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_GRV,
                KC_LALT, KC_LALT,  KC_SPC,KC_TAB,  KC_ENT,   KC_BSPC, KC_LGUI,  XXXXXXX
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

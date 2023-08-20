/* Copyright 2020 tominabox1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TG_QWERTY TG(_QWERTY)

/* Hold as control and tap as escape */
#define MY_LCTL MT(MOD_LCTL, KC_BSPC)
/* Hold as shift and tap as backspace */
#define MY_LSFT MT(MOD_LSFT, KC_ESC)

/* The following are not in use, the delay introduced as mod tap keys disrupt
 * the flow of typing */

/* Hold as shift and tap as enter */
#define MY_ENT  MT(MOD_LSFT, KC_ENT)

#define MY_LOWER_LEFT LT(LOWER, KC_LEFT)

#define MY_BSPC KC_BSPC
/* MT(MOD_LSFT, ) */
/* Hold as super and tap as space */
/* #define MY_SPC  MT(MOD_LGUI, KC_SPC) */
#define MY_SPC  KC_SPC

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * |-------+---+---+---+---+---+---+---+---+---+---+------|
 * | TAB   | Q | W | F | P | G | J | L | U | Y | ; | BKSP |
 * |-------+---+---+---+---+---+---+---+---+---+---+------|
 * | Ctrl  | A | R | S | T | D | H | N | E | I | O | ENT  |
 * |-------+---+---+---+---+---+---+---+---+---+---+------|
 * | Shift | Z | X | C | V | B | K | M | , | . | / | '    |
 * |-------+---+---+---+---+---+---+---+---+---+---+------|
 * | Tog   |CAP|GUI|Alt| Space |   |   |   |   |   |      |
 * |-------+---+---+---+-------+---+---+---+---+---+------|
 */
[_COLEMAK] = LAYOUT_planck_mit(
    KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, MY_BSPC,
    MY_LCTL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    MY_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    TG_QWERTY, KC_LCAP, _______, KC_LGUI, KC_LALT,       MY_SPC,   RAISE, MY_LOWER_LEFT, KC_DOWN, KC_UP,KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
    _______,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, _______, _______,       _______, _______,   _______,  _______, _______, _______
),

/*
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______,    KC_MUTE,    KC_VOLD, KC_VOLU, KC_MPLY
),

/*
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, KC_PGDN, KC_BSLS, // removed page up for dot
    _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-------p----------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/* bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case MY_ENT: */
/*             /\* Do not select the hold action when another key is pressed. *\/ */
/*             return false; */
/*         default: */
/*             /\* Immediately select the hold action when another key is pressed. *\/ */
/*             return true; */
/*     } */
/* } */

/* send tapping key even outside tapping term */
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_LOWER_LEFT:
        case MY_BSPC:
        case MY_LSFT:
        case MY_LCTL:
        case MY_ENT:
            /* releasing the key without pressing another will send the original
             * keycode even if it is outside the tapping term */
            return true;
        default:
            /* releasing the key without pressing another will do nothing */
            return false;
    }
}

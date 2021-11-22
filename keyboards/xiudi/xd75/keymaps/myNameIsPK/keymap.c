/* Copyright 2017 Wunder
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

// #define NUM    MO(_NUM)
// #define ADJ    MO(_ADJ)
// #define SYSTEM MO(_SYSTEM)
// #define MPASTE LSFT(KC_INSERT)
#define LT_TAB LT(_FN, KC_TAB)

/* Home row mod left */
#define LGUI_A LGUI_T(KC_A)
#define LALT_S LALT_T(KC_S)
#define LSFT_D LSFT_T(KC_D)
#define LCTL_F LCTL_T(KC_F)
/* Home row mod right */
#define RCTL_J    RCTL_T(KC_J)
#define RSFT_K    RSFT_T(KC_K)
#define RALT_L    RALT_T(KC_L)
#define RGUI_SCLN RGUI_T(KC_SCLN)

enum layer_names {
    _MAIN,
    _FN
    /* _NUM, */
    /* _NAV, */
    /* _ADJ, */
    /* _SYM */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | `      | 1      | 2      | 3      | 4      | 5      | PG UP  | UP     | PG DN  | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | LEFT   | DOWN   | RIGHT  | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | ESC    | GUI A  | ALT S  | SHIFT D| CTRL F | G      | -      | DELETE | =      | H      | CTRL J | SHIFT K| ALT L  | GUI ;  | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | [      | \      | ]      | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | TAB    | NUM_BSP| ESC    | HOME   | INSERT | END    | ENTER  | SYM_SPC| LEFT   | DOWN   | UP     | RIGHT  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_MAIN] = LAYOUT_ortho_5x15( /* MAIN QWERTY */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PGUP, KC_UP,    KC_PGDN, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LEFT, KC_DOWN,  KC_RGHT, KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_QUOT,
        KC_ESC,  LGUI_A,  LALT_S,  LSFT_D,  LCTL_F,  KC_G,    KC_MINS, KC_DEL,   KC_EQL,  KC_H,   RCTL_J,  RSFT_K,  RALT_L,  RGUI_SCLN,KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_BSLS,  KC_RBRC, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, LT_TAB,  KC_BSPC, KC_ESC,  KC_HOME, KC_INSERT,KC_END , KC_ENT, KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
    ),

    /* FUNCTION
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
        _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______
    )
};

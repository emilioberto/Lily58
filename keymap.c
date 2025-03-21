/* Copyright 2021 HellSingCoder
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
 #include "features/achordion.h"
 
 // Definisci i key override per le combinazioni con Ctrl
 const key_override_t ctrl_q_override = ko_make_basic(MOD_MASK_CTRL, KC_Q, C(KC_Z)); // Ctrl+Q -> Ctrl+Z (undo)
 const key_override_t ctrl_j_override = ko_make_basic(MOD_MASK_CTRL, KC_J, C(KC_X)); // Ctrl+J -> Ctrl+X (cut)
 const key_override_t ctrl_v_override = ko_make_basic(MOD_MASK_CTRL, KC_V, C(KC_C)); // Ctrl+V -> Ctrl+C (copy)
 const key_override_t ctrl_d_override = ko_make_basic(MOD_MASK_CTRL, KC_D, C(KC_V)); // Ctrl+D -> Ctrl+V (paste)
 const key_override_t ctrl_c_override = ko_make_basic(MOD_MASK_CTRL, KC_C, C(KC_A)); // Ctrl+C -> Ctrl+A (select all)
 const key_override_t ctrl_t_override = ko_make_basic(MOD_MASK_CTRL, KC_T, C(KC_F)); // Ctrl+T -> Ctrl+F (find)
 const key_override_t ctrl_b_override = ko_make_basic(MOD_MASK_CTRL, KC_B, C(KC_T)); // Ctrl+B -> Ctrl+T (new tab)
 
 // Array dei key override
 static const key_override_t *key_overrides[] = {
     &ctrl_q_override,
     &ctrl_j_override,
     &ctrl_v_override,
     &ctrl_d_override,
     &ctrl_c_override,
     &ctrl_t_override,
     &ctrl_b_override,
     NULL // Termina l'array
 };
 
 enum sofle_layers {
     /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
     _CANARY,
     _LOWER,
     _RAISE,
     _ADJUST,
 };
 
 // clang-format off
 enum custom_keycodes {
     KC_CANARY = SAFE_RANGE,
     KC_LOWER,
     KC_RAISE,
     KC_ADJUST,
     KC_PRVWD,
     KC_NXTWD,
     KC_LSTRT,
     KC_LEND,
     KC_DLINE,
     KC_BSPC_DEL,
     KC_LAYER,
     TEMPLATE_STR,  // Per ${}
     ARROW_FUNC,     // Per =>
     IF_STMT,
     TODO,
     COMMENT
 };
 
  const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
     /* CANARY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   W  |   L  |   Y  |   P  |   B  |                    |   Z  |   F  |   O  |   U  |   '  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|   C  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   A  |  ;   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LCTRL |   Q  |   J  |   V  |   D  |   K  |-------|    |-------|   X  |   H  |   /  |   ,  |   .  |  =   |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |  GUI | ALTGR|MO(1) | /Space  /       \Enter \  |LT(2) |  DEL | RGUI|
     *                   |      |      |      |/       /         \      \ |BackSP|      |      |
     *                   `----------------------------'           '------''--------------------'
     */
 
     [_CANARY] = LAYOUT(
     KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
     KC_TAB,   KC_W,   KC_L,    KC_Y,    KC_P,    KC_B,                     KC_Z,    KC_F,    KC_O,    KC_U,    KC_QUOT, KC_MINS,
     KC_LSFT,  KC_C,   KC_R,    KC_S,    KC_T,    KC_G,                     KC_M,    KC_N,    KC_E,    KC_I,    KC_A,    KC_SCLN,
     KC_LCTL,  KC_Q,   KC_J,    KC_V,    KC_D,    KC_K,  KC_LBRC,  KC_RBRC, KC_X,    KC_H,    KC_SLSH, KC_COMM, KC_DOT,  KC_EQL,
                         KC_LGUI, KC_ALGR, MO(_LOWER), KC_SPC,   KC_ENT, LT(2,KC_BSPC),    KC_DEL,  KC_RGUI
     ),
 
     /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   ~  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  IF  |   =  |   :  |   ;  |   -  |   +  |-------.    ,-------|   |  |   {  |   }  |   [  |   ]  |   '  |
     * |------+------+------+------+------+------|TPL_STR|    |   =>  |------+------+------+------+------+------|
     * | TODO |   /  |   \  |   .  |   ,  |   _  |-------|    |-------|   /  |   <  |   >  |   _  |   ?  |   "  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \ MO(3)\ |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
     [_LOWER] = LAYOUT(
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
         KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
         IF_STMT, KC_EQL,  KC_COLN, KC_SCLN, KC_MINS, KC_PLUS,                   KC_PIPE, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_QUOT,
         TODO   , KC_SLSH, KC_BSLS, KC_DOT,  KC_COMM, KC_UNDS, TEMPLATE_STR,  ARROW_FUNC, KC_SLSH, KC_LT,   KC_GT,   KC_UNDS, KC_QUES, KC_DQUO,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, MO(3),   KC_TRNS,   KC_TRNS
     ),
 
     /* RAISE (Vim-style frecce sulla home row, tasti F sopra i numeri, multimedia ottimizzato)
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift| PLAY | STOP | PREV | NEXT |VOL_UP|-------.    ,-------| HOME | LEFT | DOWN |  UP  | RIGHT|      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LCTRL | UNDO | REDO | COPY |PASTE |VOL_DN|-------|    |-------| END  | PGUP | PGDN |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      | MO(3)|      | /       /       \      \ |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
     [_RAISE] = LAYOUT(
         KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
         KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
         KC_LSFT, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_VOLU,                   KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
         KC_LCTL, KC_UNDO, KC_AGIN, KC_COPY, KC_PASTE,KC_VOLD, KC_TRNS, KC_TRNS, KC_END, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
                                 KC_TRNS, MO(3),   KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS
     ),
 
     /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  No  |  No  |  No  |  No  |  No  |  No  |                    |  No  |  No  |  No  |  No  |  No  |  No  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  No  |  No  |  No  |  No  |  No  |  No  |                    |  No  | Play | Stop |  No  |  No  |  No  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  No  |  No  |  No  |  No  |  No  |  No  |-------.    ,-------|  No  | Prev | Vol- | Vol+ | Next |  No  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |  No  |  No  |  No  |  No  |  No  |  No  |-------|    |-------|  No  |  No  |  No  |  No  |  No  |  No  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \      \ |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
     [_ADJUST] = LAYOUT(
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO, KC_MPLY, KC_MSTP, KC_NO, KC_NO, KC_NO,
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
     )
 
 
     // /* QWERTY
     // * ,-----------------------------------------.                    ,-----------------------------------------.
     // * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     // * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     // * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
     // * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     // * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     // * |------+------+------+------+------+------| Btn1  |    |MyComp |------+------+------+------+------+------|
     // * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     // * `-----------------------------------------/       /     \      \-----------------------------------------'
     // *                   |  GUI | LAlt | Space| /MO(1) /       \Enter \  |LT(2) | DEL  | RGUI |
     // *                   |      |      |      |/       /         \      \ |BackSP|      |      |
     // *                   `----------------------------'           '------''--------------------'
     // */
     // [_QWERTY] = LAYOUT(
     //     KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                     KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
     //     KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
     //     KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                     KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
     //     KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BTN1, KC_MYCM,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
     //                           KC_LGUI, KC_LALT, KC_SPC, MO(1),   KC_ENT, LT(2,KC_BSPC), KC_DEL, KC_RGUI
     // ),
 };
 
 // clang-format on
 
 void matrix_scan_user(void) {
   achordion_task();
 }
 
 #ifdef OLED_ENABLE
 
 
 static void render_logo(void) {
     static const char PROGMEM rise_logo[] = {
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x00, 0x30, 0x78, 0xf8, 0x3c, 0x18, 0x18, 0x18,
         0x18, 0x18, 0x18, 0x38, 0x38, 0x70, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0xf0, 0xfc, 0x1f, 0x07, 0x60, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfc, 0x7c, 0x3c, 0xfe,
         0x3e, 0xff, 0x7f, 0xfe, 0xfe, 0xfc, 0xf8, 0x00, 0x01, 0x03, 0x07, 0x3e, 0xfc, 0xf0, 0x00, 0x00,
         0x00, 0x00, 0x3f, 0xff, 0xe0, 0x80, 0x00, 0x01, 0x03, 0x07, 0x1f, 0x3f, 0x7f, 0x78, 0xf1, 0x73,
         0x9f, 0x3b, 0xb7, 0xfe, 0x0f, 0x07, 0x01, 0x00, 0x80, 0xc0, 0xe0, 0x78, 0x3f, 0x07, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0x1c, 0x18, 0x18, 0x38, 0x30, 0x30, 0x30, 0x31, 0x30,
         0x31, 0x30, 0x31, 0x1d, 0x1c, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
     };
 
     oled_write_raw_P(rise_logo, sizeof(rise_logo));
 }
 
 /* 32 * 14 os logos */
 static const char PROGMEM windows_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
 
 static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
 
 /* Smart Backspace Delete */
 
 bool            shift_held = false;
 static uint16_t held_shift = 0;
 
 /* KEYBOARD PET START */
 
 /* settings */
 #    define MIN_WALK_SPEED      10
 #    define MIN_RUN_SPEED       40
 
 /* advanced settings */
 #    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
 #    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024
 
 /* timers */
 uint32_t anim_timer = 0;
 
 /* current frame */
 uint8_t current_frame = 0;
 
 /* status variables */
 int   current_wpm = 0;
 led_t led_usb_state;
 
 bool isSneaking = false;
 bool isJumping  = false;
 bool showedJump = true;
 
 /* logic */
 // static void render_luna(int LUNA_X, int LUNA_Y) {
 //     /* Sit */
 //     static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
 //                                                    {
 //                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 //                                                    },
 
 //                                                    /* 'sit2', 32x22px */
 //                                                    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
 
 //     /* Walk */
 //     static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
 //                                                     {
 //                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 //                                                     },
 
 //                                                     /* 'walk2', 32x22px */
 //                                                     {
 //                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 //                                                     }};
 
 //     /* Run */
 //     static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
 //                                                    {
 //                                                        0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
 //                                                    },
 
 //                                                    /* 'run2', 32x22px */
 //                                                    {
 //                                                        0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 //                                                    }};
 
 //     /* Bark */
 //     static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
 //                                                     {
 //                                                         0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 //                                                     },
 
 //                                                     /* 'bark2', 32x22px */
 //                                                     {
 //                                                         0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 //                                                     }};
 
 //     /* Sneak */
 //     static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
 //                                                      {
 //                                                          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
 //                                                      },
 
 //                                                      /* 'sneak2', 32x22px */
 //                                                      {
 //                                                          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
 //                                                      }};
 
 //     /* animation */
 //     void animate_luna(void) {
 //         /* jump */
 //         if (isJumping || !showedJump) {
 //             /* clear */
 //             oled_set_cursor(LUNA_X, LUNA_Y + 2);
 //             oled_write("     ", false);
 
 //             oled_set_cursor(LUNA_X, LUNA_Y - 1);
 
 //             showedJump = true;
 //         } else {
 //             /* clear */
 //             oled_set_cursor(LUNA_X, LUNA_Y - 1);
 //             oled_write("     ", false);
 
 //             oled_set_cursor(LUNA_X, LUNA_Y);
 //         }
 
 //         /* switch frame */
 //         current_frame = (current_frame + 1) % 2;
 
 //         /* current status */
 //         if (led_usb_state.caps_lock) {
 //             oled_write_raw_P(bark[current_frame], ANIM_SIZE);
 
 //         } else if (isSneaking) {
 //             oled_write_raw_P(sneak[current_frame], ANIM_SIZE);
 
 //         } else if (current_wpm <= MIN_WALK_SPEED) {
 //             oled_write_raw_P(sit[current_frame], ANIM_SIZE);
 
 //         } else if (current_wpm <= MIN_RUN_SPEED) {
 //             oled_write_raw_P(walk[current_frame], ANIM_SIZE);
 
 //         } else {
 //             oled_write_raw_P(run[current_frame], ANIM_SIZE);
 //         }
 //     }
 
 // #    if OLED_TIMEOUT > 0
 //     /* the animation prevents the normal timeout from occuring */
 //     if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
 //         oled_off();
 //         return;
 //     } else {
 //         oled_on();
 //     }
 // #    endif
 
 //     /* animation timer */
 //     if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
 //         anim_timer = timer_read32();
 //         animate_luna();
 //     }
 // }
 
 /* KEYBOARD PET END */
 
 static void print_logo_narrow(void) {
     render_logo();
 
     /* wpm counter */
     uint8_t n = get_current_wpm();
     char    wpm_str[4];
     oled_set_cursor(0, 14);
     wpm_str[3] = '\0';
     wpm_str[2] = '0' + n % 10;
     wpm_str[1] = '0' + (n /= 10) % 10;
     wpm_str[0] = '0' + n / 10;
     oled_write(wpm_str, false);
 
     oled_set_cursor(0, 15);
     oled_write(" wpm", false);
 }
 
 static void print_status_narrow(void) {
     /* Print current mode */
     oled_set_cursor(0, 0);
     if (keymap_config.swap_lctl_lgui) {
         oled_write_raw_P(mac_logo, sizeof(mac_logo));
     } else {
         oled_write_raw_P(windows_logo, sizeof(windows_logo));
     }
 
     oled_set_cursor(0, 3);
 
     switch (get_highest_layer(default_layer_state)) {
         case _CANARY:
             oled_write("CANRY", false);
             break;
         default:
             oled_write("UNDEF", false);
     }
 
     oled_set_cursor(0, 5);
 
     /* Print current layer */
     oled_write("LAYER", false);
 
     oled_set_cursor(0, 6);
 
     switch (get_highest_layer(layer_state)) {
         case _CANARY:
             oled_write("Base ", false);
             break;
         case _RAISE:
             oled_write("Raise", false);
             break;
         case _LOWER:
             oled_write("Lower", false);
             break;
         case _ADJUST:
             oled_write("Adj  ", false);
             break;
         default:
             oled_write("Undef", false);
     }
 
     /* caps lock */
     oled_set_cursor(0, 8);
     oled_write("CPSLK", led_usb_state.caps_lock);
 
     /* KEYBOARD PET RENDER START */
 
     // render_luna(0, 13);
 
     /* KEYBOARD PET RENDER END */
 }
 
 oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }
 
 bool oled_task_user(void) {
     /* KEYBOARD PET VARIABLES START */
 
     current_wpm   = get_current_wpm();
     led_usb_state = host_keyboard_led_state();
 
     /* KEYBOARD PET VARIABLES END */
 
     if (is_keyboard_master()) {
         print_status_narrow();
     } else {
         print_logo_narrow();
     }
     return false;
 }
 
 #endif
 
 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     if (!process_achordion(keycode, record)) {
         return false;
     }
 
     switch (keycode) {
         case KC_CANARY:
             if (record->event.pressed) {
                 set_single_persistent_default_layer(_CANARY);
             }
             return false;
         case KC_LOWER:
             if (record->event.pressed) {
                 layer_on(_LOWER);
                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
             } else {
                 layer_off(_LOWER);
                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
             }
             return false;
         case KC_RAISE:
             if (record->event.pressed) {
                 layer_on(_RAISE);
                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
             } else {
                 layer_off(_RAISE);
                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
             }
             return false;
         case KC_ADJUST:
             if (record->event.pressed) {
                 layer_on(_ADJUST);
             } else {
                 layer_off(_ADJUST);
             }
             return false;
         case KC_PRVWD:
             if (record->event.pressed) {
                 if (keymap_config.swap_lctl_lgui) {
                     register_mods(mod_config(MOD_LALT));
                     register_code(KC_LEFT);
                 } else {
                     register_mods(mod_config(MOD_LCTL));
                     register_code(KC_LEFT);
                 }
             } else {
                 if (keymap_config.swap_lctl_lgui) {
                     unregister_mods(mod_config(MOD_LALT));
                     unregister_code(KC_LEFT);
                 } else {
                     unregister_mods(mod_config(MOD_LCTL));
                     unregister_code(KC_LEFT);
                 }
             }
             break;
         case KC_NXTWD:
             if (record->event.pressed) {
                 if (keymap_config.swap_lctl_lgui) {
                     register_mods(mod_config(MOD_LALT));
                     register_code(KC_RIGHT);
                 } else {
                     register_mods(mod_config(MOD_LCTL));
                     register_code(KC_RIGHT);
                 }
             } else {
                 if (keymap_config.swap_lctl_lgui) {
                     unregister_mods(mod_config(MOD_LALT));
                     unregister_code(KC_RIGHT);
                 } else {
                     unregister_mods(mod_config(MOD_LCTL));
                     unregister_code(KC_RIGHT);
                 }
             }
             break;
         case KC_LSTRT:
             if (record->event.pressed) {
                 if (keymap_config.swap_lctl_lgui) {
                     /* CMD-arrow on Mac, but we have CTL and GUI swapped */
                     register_mods(mod_config(MOD_LCTL));
                     register_code(KC_LEFT);
                 } else {
                     register_code(KC_HOME);
                 }
             } else {
                 if (keymap_config.swap_lctl_lgui) {
                     unregister_mods(mod_config(MOD_LCTL));
                     unregister_code(KC_LEFT);
                 } else {
                     unregister_code(KC_HOME);
                 }
             }
             break;
         case KC_LEND:
             if (record->event.pressed) {
                 if (keymap_config.swap_lctl_lgui) {
                     /* CMD-arrow on Mac, but we have CTL and GUI swapped */
                     register_mods(mod_config(MOD_LCTL));
                     register_code(KC_RIGHT);
                 } else {
                     register_code(KC_END);
                 }
             } else {
                 if (keymap_config.swap_lctl_lgui) {
                     unregister_mods(mod_config(MOD_LCTL));
                     unregister_code(KC_RIGHT);
                 } else {
                     unregister_code(KC_END);
                 }
             }
             break;
         case KC_DLINE:
             if (record->event.pressed) {
                 register_mods(mod_config(MOD_LCTL));
                 register_code(KC_BSPC);
             } else {
                 unregister_mods(mod_config(MOD_LCTL));
                 unregister_code(KC_BSPC);
             }
             break;
         case KC_COPY:
             if (record->event.pressed) {
                 register_mods(mod_config(MOD_LCTL));
                 register_code(KC_C);
             } else {
                 unregister_mods(mod_config(MOD_LCTL));
                 unregister_code(KC_C);
             }
             return false;
         case KC_PASTE:
             if (record->event.pressed) {
                 register_mods(mod_config(MOD_LCTL));
                 register_code(KC_V);
             } else {
                 unregister_mods(mod_config(MOD_LCTL));
                 unregister_code(KC_V);
             }
             return false;
         case KC_CUT:
             if (record->event.pressed) {
                 register_mods(mod_config(MOD_LCTL));
                 register_code(KC_X);
             } else {
                 unregister_mods(mod_config(MOD_LCTL));
                 unregister_code(KC_X);
             }
             return false;
             break;
         case KC_UNDO:
             if (record->event.pressed) {
                 register_mods(mod_config(MOD_LCTL));
                 register_code(KC_Z);
             } else {
                 unregister_mods(mod_config(MOD_LCTL));
                 unregister_code(KC_Z);
             }
             return false;
 
             /* Smart Backspace Delete */
 
         case KC_RSFT:
         case KC_LSFT:
             shift_held = record->event.pressed;
             held_shift = keycode;
             break;
         case KC_BSPC_DEL:
             if (record->event.pressed) {
                 if (shift_held) {
                     unregister_code(held_shift);
                     register_code(KC_DEL);
                 } else {
                     register_code(KC_BSPC);
                 }
             } else {
                 unregister_code(KC_DEL);
                 unregister_code(KC_BSPC);
                 if (shift_held) {
                     register_code(held_shift);
                 }
             }
             return false;
 
             /* LAYER */
 
         case KC_LAYER:
             if (record->event.pressed) {
                 if (shift_held) {
                     if (record->event.pressed) {
                         set_single_persistent_default_layer(_CANARY);
                     }
                 } else {
                     layer_on(_LOWER);
                     update_tri_layer(_LOWER, _RAISE, _ADJUST);
                 }
             } else {
                 layer_off(_LOWER);
                 update_tri_layer(_LOWER, _RAISE, _ADJUST);
             }
             return false;
 
             /* KEYBOARD PET STATUS START */
 
         case KC_LCTL:
         case KC_RCTL:
             if (record->event.pressed) {
                 isSneaking = true;
             } else {
                 isSneaking = false;
             }
             break;
         case KC_SPC:
             if (record->event.pressed) {
                 isJumping  = true;
                 showedJump = false;
             } else {
                 isJumping = false;
             }
             break;
 
             /* KEYBOARD PET STATUS END */
 
         case TEMPLATE_STR:
             if (record->event.pressed)
             {
                 SEND_STRING("`${}`");
                 tap_code(KC_LEFT);  // Sposta il cursore a sinistra
                 tap_code(KC_LEFT);  // Sposta il cursore tra le graffe
             }
             break;
         case ARROW_FUNC:
             if (record->event.pressed)
             {
                 SEND_STRING("=>");
             }
             break;
         case IF_STMT:
             if (record->event.pressed)
             {
                 SEND_STRING("if () { }");
                 for (int i = 0; i < 5; i++) {
                     tap_code(KC_LEFT);  // Cursore tra parentesi
                 }
             }
             break;
         case TODO:
             if (record->event.pressed)
             {
             SEND_STRING("// TODO: ");
             }
             break;
         case COMMENT:
             if (record->event.pressed) {
                 SEND_STRING("// ");
             }
             break;
     }
     return true;
 }
 
 #ifdef ENCODER_ENABLE
 
 bool encoder_update_user(uint8_t index, bool clockwise) {
     if (index == 0) {
         if (clockwise) {
             if (shift_held) {
                 tap_code(KC_MNXT);
             } else {
                 tap_code(KC_RIGHT);
             }
         } else {
             if (shift_held) {
                 tap_code(KC_MPRV);
             } else {
                 tap_code(KC_LEFT);
             }
         }
     } else if (index == 1) {
         if (clockwise) {
             if (shift_held) {
                 tap_code(KC_VOLU);
             } else {
                 tap_code(KC_DOWN);
             }
         } else {
             if (shift_held) {
                 tap_code(KC_VOLD);
             } else {
                 tap_code(KC_UP);
             }
         }
     }
     return true;
 }
 
 #endif
 
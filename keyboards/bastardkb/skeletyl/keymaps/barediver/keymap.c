// Copyright 2024 Derek Mackley
//
// Miryoku-derived keymap for the Bastard Keyboards Skeletyl.
// Resolved from manna-harbour/miryoku with the following options, then frozen
// into a static keymap so the thumb cluster could be customised:
//
//   MIRYOKU_ALPHAS    = COLEMAKDH   (M on home row, K on bottom row)
//   MIRYOKU_LAYERS    = FLIP
//   MIRYOKU_NAV       = INVERTEDT
//   MIRYOKU_CLIPBOARD = WIN         (Ctrl-based cut/copy/paste, suits Linux)
//
// Custom thumb cluster (base layer):
//   Left : Esc->Num   Tab->Sym   Spc->Nav
//   Right: Ent->Mouse Bspc->Fun  Del->Media
//
// Because Nav and Fun are reached from the opposite hand vs stock-flip, those
// two layers use the *non-flip* arrangement so the home-row mods (GACS) stay
// under the hand that holds the layer.

#include QMK_KEYBOARD_H

enum miryoku_layers {
    U_BASE,
    U_EXTRA,
    U_TAP,
    U_BUTTON,
    U_NAV,
    U_MOUSE,
    U_MEDIA,
    U_NUM,
    U_SYM,
    U_FUN,
};

// Tap dance: double-tap a layer's "you are here" key to set it as the default
// layer; double-tap the boot key to jump to the bootloader.
enum {
    U_TD_BOOT,
    U_TD_U_BASE,
    U_TD_U_EXTRA,
    U_TD_U_TAP,
    U_TD_U_BUTTON,
    U_TD_U_NAV,
    U_TD_U_MOUSE,
    U_TD_U_MEDIA,
    U_TD_U_NUM,
    U_TD_U_SYM,
    U_TD_U_FUN,
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}

#define U_TD_LAYER(LAYER)                                                   \
    void u_td_fn_##LAYER(tap_dance_state_t *state, void *user_data) {       \
        if (state->count == 2) {                                           \
            default_layer_set((layer_state_t)1 << LAYER);                  \
        }                                                                   \
    }
U_TD_LAYER(U_BASE)
U_TD_LAYER(U_EXTRA)
U_TD_LAYER(U_TAP)
U_TD_LAYER(U_BUTTON)
U_TD_LAYER(U_NAV)
U_TD_LAYER(U_MOUSE)
U_TD_LAYER(U_MEDIA)
U_TD_LAYER(U_NUM)
U_TD_LAYER(U_SYM)
U_TD_LAYER(U_FUN)

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT]      = ACTION_TAP_DANCE_FN(u_td_fn_boot),
    [U_TD_U_BASE]    = ACTION_TAP_DANCE_FN(u_td_fn_U_BASE),
    [U_TD_U_EXTRA]   = ACTION_TAP_DANCE_FN(u_td_fn_U_EXTRA),
    [U_TD_U_TAP]     = ACTION_TAP_DANCE_FN(u_td_fn_U_TAP),
    [U_TD_U_BUTTON]  = ACTION_TAP_DANCE_FN(u_td_fn_U_BUTTON),
    [U_TD_U_NAV]     = ACTION_TAP_DANCE_FN(u_td_fn_U_NAV),
    [U_TD_U_MOUSE]   = ACTION_TAP_DANCE_FN(u_td_fn_U_MOUSE),
    [U_TD_U_MEDIA]   = ACTION_TAP_DANCE_FN(u_td_fn_U_MEDIA),
    [U_TD_U_NUM]     = ACTION_TAP_DANCE_FN(u_td_fn_U_NUM),
    [U_TD_U_SYM]     = ACTION_TAP_DANCE_FN(u_td_fn_U_SYM),
    [U_TD_U_FUN]     = ACTION_TAP_DANCE_FN(u_td_fn_U_FUN),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [U_BASE] = LAYOUT_split_3x5_3(
        KC_Q,              KC_W,         KC_F,         KC_P,             KC_B,              KC_J,              KC_L,              KC_U,            KC_Y,           KC_QUOT,
        LGUI_T(KC_A),      LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),     KC_G,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),    LALT_T(KC_I),   LGUI_T(KC_O),
        LT(U_BUTTON,KC_Z), ALGR_T(KC_X), KC_C,         KC_D,             KC_V,              KC_K,              KC_H,              KC_COMM,         ALGR_T(KC_DOT), LT(U_BUTTON,KC_SLSH),
                                         LT(U_NUM,KC_ESC), LT(U_SYM,KC_TAB), LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_ENT), LT(U_FUN,KC_BSPC), LT(U_MEDIA,KC_DEL)
    ),

    [U_EXTRA] = LAYOUT_split_3x5_3(
        KC_Q,              KC_W,         KC_E,         KC_R,             KC_T,              KC_Y,              KC_U,              KC_I,            KC_O,           KC_P,
        LGUI_T(KC_A),      LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),     KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),    LALT_T(KC_L),   LGUI_T(KC_QUOT),
        LT(U_BUTTON,KC_Z), ALGR_T(KC_X), KC_C,         KC_V,             KC_B,              KC_N,              KC_M,              KC_COMM,         ALGR_T(KC_DOT), LT(U_BUTTON,KC_SLSH),
                                         LT(U_NUM,KC_ESC), LT(U_SYM,KC_TAB), LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_ENT), LT(U_FUN,KC_BSPC), LT(U_MEDIA,KC_DEL)
    ),

    [U_TAP] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_ESC,  KC_TAB,  KC_SPC,      KC_ENT,  KC_BSPC, KC_DEL
    ),

    [U_BUTTON] = LAYOUT_split_3x5_3(
        C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),     C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,       KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),     C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
                          MS_BTN3, MS_BTN1, MS_BTN2,     MS_BTN2, MS_BTN1, MS_BTN3
    ),

    // Nav: non-flip (held by left hand), inverted-T arrows on the right.
    [U_NAV] = LAYOUT_split_3x5_3(
        TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_EXTRA), TD(U_TD_U_BASE), KC_NO,   KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,
        KC_LGUI,       KC_LALT,        KC_LCTL,          KC_LSFT,         KC_NO,   CW_TOGG, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        KC_NO,         KC_ALGR,        TD(U_TD_U_NUM),   TD(U_TD_U_NAV),  KC_NO,   C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
                                       KC_NO,            KC_NO,           KC_NO,   KC_ENT,  KC_BSPC, KC_DEL
    ),

    // Mouse: flip (held by right hand).
    [U_MOUSE] = LAYOUT_split_3x5_3(
        MS_WHLU, MS_WHLL, MS_UP, MS_WHLR, KC_NO,       KC_NO,   TD(U_TD_U_BASE),  TD(U_TD_U_EXTRA), TD(U_TD_U_TAP), TD(U_TD_BOOT),
        MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, KC_NO,       KC_NO,   KC_LSFT,          KC_LCTL,          KC_LALT,        KC_LGUI,
        C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),     KC_NO,   TD(U_TD_U_MOUSE), TD(U_TD_U_SYM),   KC_ALGR,        KC_NO,
                          MS_BTN3, MS_BTN1, MS_BTN2,     KC_NO,   KC_NO,            KC_NO
    ),

    // Media: flip (held by right hand). RGB controls mapped to RGB Matrix.
    [U_MEDIA] = LAYOUT_split_3x5_3(
        RM_HUEU, RM_SATU, KC_VOLU, RM_VALU, RM_TOGG,     KC_NO,   TD(U_TD_U_BASE),  TD(U_TD_U_EXTRA), TD(U_TD_U_TAP), TD(U_TD_BOOT),
        RM_NEXT, KC_MPRV, KC_VOLD, KC_MNXT, KC_NO,       KC_NO,   KC_LSFT,          KC_LCTL,          KC_LALT,        KC_LGUI,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   TD(U_TD_U_MEDIA), TD(U_TD_U_FUN),   KC_ALGR,        KC_NO,
                          KC_MUTE, KC_MPLY, KC_MSTP,     KC_NO,   KC_NO,            KC_NO
    ),

    // Num: flip (held by left hand).
    [U_NUM] = LAYOUT_split_3x5_3(
        TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_EXTRA), TD(U_TD_U_BASE), KC_NO,   KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,
        KC_LGUI,       KC_LALT,        KC_LCTL,          KC_LSFT,         KC_NO,   KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN,
        KC_NO,         KC_ALGR,        TD(U_TD_U_NAV),   TD(U_TD_U_NUM),  KC_NO,   KC_BSLS, KC_1,    KC_2,    KC_3,    KC_GRV,
                                       KC_NO,            KC_NO,           KC_NO,   KC_MINS, KC_0,    KC_DOT
    ),

    // Sym: flip (held by left hand).
    [U_SYM] = LAYOUT_split_3x5_3(
        TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_EXTRA), TD(U_TD_U_BASE), KC_NO,   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,
        KC_LGUI,       KC_LALT,        KC_LCTL,          KC_LSFT,         KC_NO,   KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_COLN,
        KC_NO,         KC_ALGR,        TD(U_TD_U_MOUSE), TD(U_TD_U_SYM),  KC_NO,   KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD,
                                       KC_NO,            KC_NO,           KC_NO,   KC_UNDS, KC_LPRN, KC_RPRN
    ),

    // Fun: non-flip (held by right hand).
    [U_FUN] = LAYOUT_split_3x5_3(
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,            KC_NO,   TD(U_TD_U_BASE),  TD(U_TD_U_EXTRA), TD(U_TD_U_TAP), TD(U_TD_BOOT),
        KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,            KC_NO,   KC_LSFT,          KC_LCTL,          KC_LALT,        KC_LGUI,
        KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,            KC_NO,   TD(U_TD_U_FUN),   TD(U_TD_U_MEDIA), KC_ALGR,        KC_NO,
                       KC_APP, KC_SPC, KC_TAB,           KC_NO,   KC_NO,            KC_NO
    ),
};

// Shift + Caps Word toggle = Caps Lock
const key_override_t capsword_key_override =
    ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t *key_overrides[] = {
    &capsword_key_override,
};

// Chordal Hold normally only lets a tap-hold key be held when the *next* key is
// on the opposite hand. That would break the same-hand modifier chords we use
// constantly on Hyprland (left Super + left Num thumb + right digit, or
// Super+Shift+digit). When the other key is itself a mod-tap or layer-tap we're
// stacking modifiers / entering a layer, which is always intentional, so allow
// the hold and let PERMISSIVE_HOLD/tapping-term timing decide. Everything else
// (e.g. a same-hand alpha) falls back to the default opposite-hands rule, so
// rolls like "are"/"st" still settle as taps.
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                      uint16_t other_keycode, keyrecord_t *other_record) {
    if (IS_QK_MOD_TAP(other_keycode) || IS_QK_LAYER_TAP(other_keycode)) {
        return true;
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
}

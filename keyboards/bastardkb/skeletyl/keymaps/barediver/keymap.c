// Copyright 2024 Derek Mackley
// Colemak-DH keymap for the Bastard Keyboards Skeletyl (split 3x5+3).

#include QMK_KEYBOARD_H

enum layers {
    U_BASE,
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
    [U_TD_U_TAP]     = ACTION_TAP_DANCE_FN(u_td_fn_U_TAP),
    [U_TD_U_BUTTON]  = ACTION_TAP_DANCE_FN(u_td_fn_U_BUTTON),
    [U_TD_U_NAV]     = ACTION_TAP_DANCE_FN(u_td_fn_U_NAV),
    [U_TD_U_MOUSE]   = ACTION_TAP_DANCE_FN(u_td_fn_U_MOUSE),
    [U_TD_U_MEDIA]   = ACTION_TAP_DANCE_FN(u_td_fn_U_MEDIA),
    [U_TD_U_NUM]     = ACTION_TAP_DANCE_FN(u_td_fn_U_NUM),
    [U_TD_U_SYM]     = ACTION_TAP_DANCE_FN(u_td_fn_U_SYM),
    [U_TD_U_FUN]     = ACTION_TAP_DANCE_FN(u_td_fn_U_FUN)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [U_BASE] = LAYOUT_split_3x5_3(
        KC_Q,              KC_W,         KC_F,         KC_P,             KC_B,              KC_J,              KC_L,              KC_U,            KC_Y,           KC_QUOT,
        LGUI_T(KC_A),      LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),     KC_G,              KC_M,              RSFT_T(KC_N),      RCTL_T(KC_E),    RALT_T(KC_I),   RGUI_T(KC_O),
        LT(U_BUTTON,KC_Z), ALGR_T(KC_X), KC_C,         KC_D,             KC_V,              KC_K,              KC_H,              KC_COMM,         ALGR_T(KC_DOT), LT(U_BUTTON,KC_SLSH),
                                         LT(U_NUM,KC_ESC), LT(U_NAV,KC_TAB), LT(U_SYM,KC_SPC),  LT(U_MOUSE,KC_ENT), LT(U_FUN,KC_BSPC), LT(U_MEDIA,KC_DEL)
    ),

    [U_TAP] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_ESC,  KC_TAB,  KC_SPC,      KC_ENT,  KC_BSPC, KC_DEL
    ),

    [U_BUTTON] = LAYOUT_split_3x5_3(
        C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),     C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,       KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
        C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),     C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
                          MS_BTN3, MS_BTN1, MS_BTN2,     MS_BTN2, MS_BTN1, MS_BTN3
    ),

    [U_NAV] = LAYOUT_split_3x5_3(
        TD(U_TD_BOOT), TD(U_TD_U_TAP), KC_NO,            TD(U_TD_U_BASE), KC_NO,   KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,
        KC_LGUI,       KC_LALT,        KC_LCTL,          KC_LSFT,         KC_NO,   CW_TOGG, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        KC_NO,         KC_ALGR,        TD(U_TD_U_NUM),   TD(U_TD_U_NAV),  KC_NO,   C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
                                       KC_NO,            KC_NO,           KC_NO,   KC_ENT,  KC_BSPC, KC_DEL
    ),

    [U_MOUSE] = LAYOUT_split_3x5_3(
        MS_WHLU, MS_WHLL, MS_UP, MS_WHLR, KC_NO,       KC_NO,   TD(U_TD_U_BASE),  KC_NO,            TD(U_TD_U_TAP), TD(U_TD_BOOT),
        MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, KC_NO,       KC_NO,   KC_RSFT,          KC_RCTL,          KC_RALT,        KC_RGUI,
        C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),     KC_NO,   TD(U_TD_U_MOUSE), TD(U_TD_U_SYM),   KC_ALGR,        KC_NO,
                          MS_BTN3, MS_BTN1, MS_BTN2,     KC_NO,   KC_NO,            KC_NO
    ),

    [U_MEDIA] = LAYOUT_split_3x5_3(
        RM_HUEU, RM_SATU, KC_VOLU, RM_VALU, RM_TOGG,     KC_NO,   TD(U_TD_U_BASE),  KC_NO,            TD(U_TD_U_TAP), TD(U_TD_BOOT),
        RM_NEXT, KC_MPRV, KC_VOLD, KC_MNXT, KC_NO,       KC_NO,   KC_RSFT,          KC_RCTL,          KC_RALT,        KC_RGUI,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   TD(U_TD_U_MEDIA), TD(U_TD_U_FUN),   KC_ALGR,        KC_NO,
                          KC_MUTE, KC_MPLY, KC_MSTP,     KC_NO,   KC_NO,            KC_NO
    ),

    [U_NUM] = LAYOUT_split_3x5_3(
        TD(U_TD_BOOT), TD(U_TD_U_TAP), KC_NO,            TD(U_TD_U_BASE), KC_NO,   KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,
        KC_LGUI,       KC_LALT,        KC_LCTL,          KC_LSFT,         KC_NO,   KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN,
        KC_NO,         KC_ALGR,        TD(U_TD_U_NAV),   TD(U_TD_U_NUM),  KC_NO,   KC_BSLS, KC_1,    KC_2,    KC_3,    KC_GRV,
                                       KC_NO,            KC_NO,           KC_NO,   KC_MINS, KC_0,    KC_DOT
    ),

    [U_SYM] = LAYOUT_split_3x5_3(
        TD(U_TD_BOOT), TD(U_TD_U_TAP), KC_NO,            TD(U_TD_U_BASE), KC_NO,   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,
        KC_LGUI,       KC_LALT,        KC_LCTL,          KC_LSFT,         KC_NO,   KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_COLN,
        KC_NO,         KC_ALGR,        TD(U_TD_U_MOUSE), TD(U_TD_U_SYM),  KC_NO,   KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD,
                                       KC_NO,            KC_NO,           KC_NO,   KC_UNDS, KC_LPRN, KC_RPRN
    ),

    [U_FUN] = LAYOUT_split_3x5_3(
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,            KC_NO,   TD(U_TD_U_BASE),  KC_NO,            TD(U_TD_U_TAP), TD(U_TD_BOOT),
        KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,            KC_NO,   KC_RSFT,          KC_RCTL,          KC_RALT,        KC_RGUI,
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

// Chordal Hold only holds a tap-hold key when the next key is on the opposite
// hand, which kills same-hand alpha-roll misfires. The same-hand modifier/layer
// chords we rely on (e.g. Super+Num+digit on Hyprland) are re-allowed by
// returning true whenever the other key is itself a mod-tap or layer-tap.
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                      uint16_t other_keycode, keyrecord_t *other_record) {
    if (IS_QK_MOD_TAP(other_keycode) || IS_QK_LAYER_TAP(other_keycode)) {
        return true;
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
}

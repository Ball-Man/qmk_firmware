#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _UNICODE,
    _ADJUST,
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define UNICODE MO(_UNICODE)

enum unicode_names {
    AACUTE,
    AACUTE_M,
    EACUTE,
    EACUTE_M,
    IACUTE,
    IACUTE_M,
    OACUTE,
    OACUTE_M,
    UACUTE,
    UACUTE_M,
    UDIER,
    UDIER_M,
    NTILDE,
    NTILDE_M,
    POUN,
    COPY,
    ORDF,
    ORDM,
    QUAD,
    CUBE,
    DEGR,
    QUAR,
    HALF,
    NOT,
    LDQU,
    RDQU,
    QUES,
    EXCL,
    ARRL,
    ARRU,
    ARRR,
    ARRD,
    EURO,
    SMIL,
    NEUT,
    SMIH,
    ANGR,
    WORR,
    DIZY,
    TONG,
    DISS,
    SCRE,
};

const uint32_t PROGMEM unicode_map[] = {
    [AACUTE]    = 0xe1, // á
    [AACUTE_M]  = 0xc1, // Á
    [EACUTE]    = 0xe9, // é
    [EACUTE_M]  = 0xc9, // É
    [IACUTE]    = 0xed, // í
    [IACUTE_M]  = 0xcd, // Í
    [OACUTE]    = 0xf3, // ó
    [OACUTE_M]  = 0xd3, // Ó
    [UACUTE]    = 0xfa, // ú
    [UACUTE_M]  = 0xda, // Ú
    [UDIER]     = 0xfc, // ü
    [UDIER_M]   = 0xdc, // Ü
    [NTILDE]    = 0xf1, // ñ
    [NTILDE_M]  = 0xd1, // Ñ
    [POUN]      = 0xa3, // £
    [COPY]      = 0xa9, // ©
    [ORDF]      = 0xaa, // ª
    [ORDM]      = 0xba, // º
    [QUAD]      = 0xb2, // ²
    [CUBE]      = 0xb3, // ³
    [DEGR]      = 0xb0, // °
    [QUAR]      = 0xbc, // ¼
    [HALF]      = 0xbd, // ½
    [NOT]       = 0xac, // ¬
    [LDQU]      = 0xab, // «
    [RDQU]      = 0xbb, // »
    [QUES]      = 0xbf, // ¿
    [EXCL]      = 0xa1, // ¡
    [ARRL]      = 0x2190, // ←
    [ARRU]      = 0x2191, // ↑
    [ARRR]      = 0x2192, // →
    [ARRD]      = 0x2193, // ↓
    [EURO]      = 0x20ac, // €
    [SMIL]      = 0x1f603, // 😃
    [NEUT]      = 0x1f610, // 😐 
    [SMIH]      = 0x1f608, // 😈
    [ANGR]      = 0x1f620, // 😠
    [WORR]      = 0x1f61f, // 😟
    [DIZY]      = 0x1f635, // 😵
    [TONG]      = 0x1f61d, // 😝
    [DISS]      = 0x1f61e, // 😝
    [SCRE]      = 0x1f631, // 😱
};

#define A_UNIC XP(AACUTE, AACUTE_M)
#define E_UNIC XP(EACUTE, EACUTE_M)
#define I_UNIC XP(IACUTE, IACUTE_M)
#define O_UNIC XP(OACUTE, OACUTE_M)
#define U_UNIC XP(UACUTE, UACUTE_M)
#define Y_UNIC XP(UDIER,  UDIER_M )
#define N_UNIC XP(NTILDE, NTILDE_M)
#define ORD_UN XP(ORDF,   ORDM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* qwerty
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |   esc  |    Q   |    W   |    E   |    R   |    T   |    Y   |    U   |    I   |    O   |    P   |  bksp  |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |   tab  |    A   |    S   |    D   |    F   |    G   |    H   |    J   |    K   |    L   |    ;   |   del  |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * | lshift |    Z   |    X   |    C   |    V   |    B   |    N   |    M   |    ,   |    .   |    /   |  enter |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |  lctrl |  lalt  |  lower |  unic  |  lgui  |  space |  space |  raise |  left  |  down  |   up   |  right | 
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 */
[_QWERTY] = LAYOUT_ortho_4x12 ( 
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_DEL,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_LALT, LOWER,   UNICODE, KC_LGUI, KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |   F1   |   F2   |   F3   |   F4   |        |        |    7   |    8   |    9   |    -   |        |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |   F5   |   F6   |   F7   |   F8   |        |        |    4   |    5   |    6   |    +   |        |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |   F9   |   F10  |   F11  |   F12  |        |  nlck  |    1   |    2   |    3   |    /   |  pent  |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |        |        |        |        |        |        |        |    0   |    .   |    *   |    ;   |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 */
[_LOWER] = LAYOUT_ortho_4x12 (
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_NLCK, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_PAST, KC_SCLN
),

/* Raise
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |    1   |    2   |    3   |    4   |    5   |    6   |    7   |    8   |    9   |    0   |        |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |  caps  |        |        |        |        |        |    \   |    -   |    =   |    [   |    ]   |        |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |        |        |        |        |        |    `   |        |        |        |        |        |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 * |        |        |        |        |        |        |        |        |  home  |  pgdn  |  pgup  |   end  |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
 */
[_RAISE] = LAYOUT_ortho_4x12 (
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_CAPS, _______, _______, _______, _______, _______, KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______, KC_GRV,  KC_QUOT, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* 
 * unicode
 */
[_UNICODE] = LAYOUT_ortho_4x12 ( 
    _______, X(EXCL), X(WORR), E_UNIC,  X(EURO), X(TONG), Y_UNIC,  U_UNIC,  I_UNIC,  O_UNIC,  X(POUN), _______,
    _______, A_UNIC,  X(SMIL), X(DISS), X(SCRE), X(DEGR), X(SMIH), X(NOT),  X(QUAR), X(HALF), ORD_UN,  _______,
    _______, X(DIZY), X(ANGR), X(COPY), X(QUAD), X(CUBE), N_UNIC,  X(NEUT), X(LDQU), X(RDQU), X(QUES), _______,
    _______, _______, _______, _______, _______, _______, _______, _______, X(ARRU), X(ARRL), X(ARRD), X(ARRR)
),

/* 
 * Adjust 
 */
[_ADJUST] = LAYOUT_ortho_4x12 (
    _______, RESET,   _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, BL_STEP, BL_BRTG, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),    
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_init_user(void) {
}


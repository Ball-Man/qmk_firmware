# ManuNeo Ergodox Keyboard Layout

Compile this file to a `keymap.c` file using `compile_keymap.py`

    python compile_keymap.py keymaps/german-manuneo/keymap.md

Tested with python 2.7 and python 3.4


# Layout Config

    {
        "layout": "ergodox_ez",
        "keymaps_includes": [
            QMK_KEYBOARD_H,
            "action_layer.h",
            "keymap_common.h",
            "keymap_extras/keymap_german.h",
        ],
        "key_prefixes": ["DE_", "KC_"],
        "macros": {
            // TODO: implement macros
            // "MUC": "",
        },
        // TODO: implement default unicode mode
    }


# Layers


## Layer 0

    .------------------------------------.------------------------------------.
    |MO(5)| 1  | 2  | 3  | 4  | 5  |ACUT | GRV | 6  | 7  | 8  | 9  | 0  |CIRC |
    !-----+----+----+----+----+----------!-----+----+----+----+----+----+-----!
    |MO(4)| X  | P  | F  | W  | G  |HOME |TG(2)| H  | J  | K  | L  | Q  |  Z  |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |MO(1)| U  | I  | A  | E  | O  |-----!-----! S  | N  | R  | T  | D  | SS  |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |MO(3)| UE | OE | AE | C  | V  |END  | TAB | B  | M  |COMM| DOT| UP |  Y  |
    '-----+----+----+----+----+----------'----------+----+----+----+----+-----'
     |    |    |LGUI|LALT|LCTL|                     !RCTL|RALT|LEFT|DOWN|RGHT|
     '------------------------'                     '------------------------'
                            .-----------. .-----------.
                            |INS  |TG(2)| !M(UM)|DELT |
                      .-----+-----+-----! !-----+-----+-----.
                      !     !     | APP | ! PGUP|     !     !
                      !     !     !-----! !-----!     !     !
                      |BSPC |LSFT | ESC | ! PGDN|ENTER|SPACE|
                      '-----------------' '-----------------'


## Layer 1

    .------------------------------------.------------------------------------.
    |     |EXLM|DQOT|PARA|    |    |     |     |    |    |    |    |RING|     |
    !-----+----+----+----+----+----------!-----+----+----+----+----+----+-----!
    |     |ASTR|PIPE|SLSH|LCBR|RCBR|     |     |HASH|LESS|MORE|    |DQOT|     |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     |UNDS|MINS|AMPR|LBRC|RBRC|-----!-----!DLR |LPRN|RPRN|TILD|QUOT| QST |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     |    |PLUS|EQL |    |    |     |     |BSLS|PERC|SCLN|COLN| ???  |     |
    '-----+----+----+----+----+----------'----------+----+----+----+----+-----'
     |    |    |    |    |    |                     !    |    | ???  | ???  | ???  |
     '------------------------'                     '------------------------'
                            .-----------. .-----------.
                            |     |     | !     |     |
                      .-----+-----+-----! !-----+-----+-----.
                      !     !     |     | !     |     !     !
                      !     !     !-----! !-----!     !     !
                      |     |     |     | !     |     |     |
                      '-----------------' '-----------------'


## Layer 2

    .------------------------------------.------------------------------------.
    |     | F1 | F2 | F3 | F4 | F5 | F11 | F12 | F6 | F7 | F8 | F9 |F10 |PEQL |
    !-----+----+----+----+----+----------!-----+----+----+----+----+----+-----!
    |     |    |    |    |    |    |     |     |    | P7 | P8 | P9 |PAST|PSLS |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     |    |    |    |    |    |-----!-----!    | P4 | P5 | P6 |PMNS|PMNS |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     |    |    |    |    |    |     | NLCK|    | P1 | P2 | P3 |PPLS|PPLS |
    '-----+----+----+----+----+----------'----------+----+----+----+----+-----'
     |    |    |    |    |    |                     ! P0 |PCMM|PDOT|PENT|PENT|
     '------------------------'                     '------------------------'
                            .-----------. .-----------.
                            |     |     | !     |     |
                      .-----+-----+-----! !-----+-----+-----.
                      !     !     |     | !     |     !     !
                      !     !     !-----! !-----!     !     !
                      |     |     |     | !     |     |     |
                      '-----------------' '-----------------'



## Layer 3

http://symbolcodes.tlt.psu.edu/bylanguage/mathchart.html

    .------------------------------------.------------------------------------.
    |     | ??  | ??  | ??  | ???  | ???  |  ???  |     | ???  | ???  | ???  | ???  |  ??? |     |
    !-----+----+----+----+----+----------!-----+----+----+----+----+----+-----!
    |     | ??  | ??  | ??  | ??  |  ??? |     |     | ???  |    | ???  |    |    |     |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     |    | ??  | AT |EURO| ???  |-----!-----! ???  | ???  | ???  | ???  |    |     |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     | ???  | ???  | ???  | ??  | ???  |     |     |EXLM|    | ???  | ???  |    |     |
    '-----+----+----+----+----+----------'----------+----+----+----+----+-----'
     |    |    |    |    |    |                     !    |    |    |    |    |
     '------------------------'                     '------------------------'
                            .-----------. .-----------.
                            |     |     | !     |     |
                      .-----+-----+-----! !-----+-----+-----.
                      !     !     |     | !     |     !     !
                      !     !     !-----! !-----!     !     !
                      |     |     |     | !     |     |     |
                      '-----------------' '-----------------'


## Layer 4


    .------------------------------------.------------------------------------.
    |     | ???  | ???  | ???  | ???  | ???  |     |     | ???  | ???  | ???  | ???  | ???  |     |
    !-----+----+----+----+----+----------!-----+----+----+----+----+----+-----!
    |     | ??  | ??  | ??  | ??  | ??  |     |     | ??  | ??  | ??  | ??  |    |  ??  |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     | ??  | ??  | ??  | ??  | ??  |-----!-----! ??  | ??  | ??  | ??  | ??  |  ??  |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     |    | ??  |    |    |    |     |     | ??  | ??  |    |    |    |  ??  |
    '-----+----+----+----+----+----------'----------+----+----+----+----+-----'
     |    |    |    |    |    |                     !    |    |    |    |    |
     '------------------------'                     '------------------------'
                            .-----------. .-----------.
                            |     |     | !     |     |
                      .-----+-----+-----! !-----+-----+-----.
                      !     !     |     | !     |     !     !
                      !     !     !-----! !-----!     !     !
                      |     |     |     | !     |     |     |
                      '-----------------' '-----------------'


## Layer 5

    .------------------------------------.------------------------------------.
    |     |    |    |    |    |    |     |     |    |    |    |    |    |     |
    !-----+----+----+----+----+----------!-----+----+----+----+----+----+-----!
    |     | ??  | ??  | ??  | ??  | ??  |     |     | ??  | ??  | ??  | ??  |    |  ??  |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     | ??  | ??  | ??  | ??  | ??  |-----!-----! ??  | ??  | ??  | ??  | ??  |     |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     |    | ??  |    |    |    |     |     | ??  | ??  |    |    |    |  ??  |
    '-----+----+----+----+----+----------'----------+----+----+----+----+-----'
     |    |    |    |    |    |                     !    |    |    |    |    |
     '------------------------'                     '------------------------'
                            .-----------. .-----------.
                            |     |     | !     |     |
                      .-----+-----+-----! !-----+-----+-----.
                      !     !     |     | !     |     !     !
                      !     !     !-----! !-----!     !     !
                      |     |     |     | !     |     |     |
                      '-----------------' '-----------------'


## Layer 6

    .------------------------------------.------------------------------------.
    |     |    |    |    |    |    |     |     |    |    |    |    |    |     |
    !-----+----+----+----+----+----------!-----+----+----+----+----+----+-----!
    |     |    |    |    |    |    |     |     |    |    |    |    |    |     |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     |    |    |    |    |    |-----!-----!    |    |    |    |    |     |
    !-----+----+----+----x----x----!     !     !----x----x----+----+----+-----!
    |     |    |    |    |    |    |     |     |    |    |    |    |    |     |
    '-----+----+----+----+----+----------'----------+----+----+----+----+-----'
     |    |    |    |    |    |                     !    |    |    |    |    |
     '------------------------'                     '------------------------'
                            .-----------. .-----------.
                            |     |     | !     |     |
                      .-----+-----+-----! !-----+-----+-----.
                      !     !     |     | !     |     !     !
                      !     !     !-----! !-----!     !     !
                      |     |     |     | !     |     |     |
                      '-----------------' '-----------------'


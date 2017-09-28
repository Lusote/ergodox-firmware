
/* ----------------------------------------------------------------------------
* ergoDOX layout : QWERTY (modified from the Kinesis layout)
* -----------------------------------------------------------------------------
* Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
* Released under The MIT License (MIT) (see "license.md")
* Project located at <https://github.com/benblazak/ergodox-firmware>
* -------------------------------------------------------------------------- */
#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"
// FUNCTIONS ------------------------------------------------------------------
void kbfun_layer_pop_all(void) {
  kbfun_layer_pop_1();
  kbfun_layer_pop_2();
  kbfun_layer_pop_3();
  kbfun_layer_pop_4();
  kbfun_layer_pop_5();
  kbfun_layer_pop_6();
  kbfun_layer_pop_7();
  kbfun_layer_pop_8();
  kbfun_layer_pop_9();
  kbfun_layer_pop_10();
}

// DEFINITIONS ----------------------------------------------------------------
#define  kprrel   &kbfun_press_release
#define  mprrel   &kbfun_mediakey_press_release
#define  ktog     &kbfun_toggle
#define  ktrans   &kbfun_transparent
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop     &kbfun_layer_pop_all
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
#define  dbtldr   &kbfun_jump_to_bootloader
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad


// CUSTOM DEFINITIONS ---------------------------------------------------------

#define  altgrprre &kbfun_altgr_press_release
#define  tildepc  &kbfun_tilde_pc_press_release
#define  tildemac  &kbfun_tilde_mac_press_release
#define  dieresispc &kbfun_dieresis_pc_press_release
#define  dieresismac &kbfun_dieresis_mac_press_release
#define  enhepc  &kbfun_altgr_n_pc_press_release
#define  enhemac  &kbfun_altgr_n_mac_press_release
#define  altgui &kbfun_mod_mac_alt_press_release
#define  ctrgui &kbfun_mod_mac_ctr_press_release

#define  vsave     &kbfun_vim_save
#define  vsaveq    &kbfun_vim_save_and_quit
#define  vbuff     &kbfun_vim_buffers

#define  modmac     &kbfun_mod_mac_press_release
#define  modwl      &kbfun_mod_wl_press_release
#define  macrf2ctl  &macro_f2_ctrl_mod

// ----------------------------------------------------------------------------

// LAYOUT ---------------------------------------------------------------------
const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
/*
* Keymap: Default Layer Mac dvorak (Layer 0)
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |   Esc  |   1  |   2  |   3  |   4  |   5  |  `   |           |   ~  |   6  |   7  |   8  |   9  |   0  |   =    |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |   Tab  |   '  |   ,  |   .  |   P  |   Y  |  \   |           |   /  |   F  |   G  |   C  |   R  |   L  |   -    |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |   Tab  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   ]    |
* |--------+------+------+------+------+------|  {   |           |   }  |------+------+------+------+------+--------|
* |    (   |   Z  |   X  |   C  |   V  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |   )    |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   | ~L4  |      | LCtr | LGUI |LShift|                                       | ~L4  | Left | Down |  Up  | Rigth|
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        | Copy |  Cut |       | PgUp | LAlt |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      | Paste|       | PgDn |      |      |
*                                 | BkSp | Del  |------|       |------| Enter| Space|
*                                 |      |      | ~L2  |       | ~L2  |      |      |
*                                 `--------------------'       `--------------------'
*/
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  KEY_Escape, KEY_1_Exclamation,  KEY_2_At, KEY_3_Pound,  KEY_4_Dollar, KEY_5_Percent,  KEY_GraveAccent_Tilde,  
  KEY_Tab, KEY_SingleQuote_DoubleQuote,  KEY_Comma_LessThan, KEY_Period_GreaterThan, KEY_p_P,  KEY_y_Y,  KEY_Backslash_Pipe,  
  KEY_LeftBracket_LeftBrace,  KEY_a_A,  KEY_o_O,  KEY_e_E,  KEY_u_U,  KEY_i_I,  
  KEY_9_LeftParenthesis,  KEY_Semicolon_Colon,  KEY_q_Q,  KEY_j_J,  KEY_k_K,  KEY_x_X,  _bracketL,  
                      4,   0,  KEY_LeftControl, KEY_LeftGUI,  KEY_LeftShift,  
                                                                                    KEY_c_C, KEY_x_X,  
                                                                                    0,  0,  KEY_v_V,  
                                                          KEY_DeleteBackspace,  KEY_DeleteForward,  2,  
  // right hand
              KEY_GraveAccent_Tilde,  KEY_6_Caret,  KEY_7_Ampersand,  KEY_8_Asterisk, KEY_9_LeftParenthesis,  KEY_0_RightParenthesis, KEY_Equal_Plus,  
              KEY_Slash_Question,  KEY_f_F,  KEY_g_G,  KEY_c_C,  KEY_r_R,  KEY_l_L,  KEY_Dash_Underscore, 
                  KEY_d_D,  KEY_h_H,  KEY_t_T,  KEY_n_N,  KEY_s_S,  KEY_RightBracket_RightBrace,  
              _bracketR,  KEY_b_B,  KEY_m_M,  KEY_w_W,  KEY_v_V,  KEY_z_Z,  KEY_0_RightParenthesis, 
                  4, KEY_LeftArrow,  KEY_DownArrow,  KEY_UpArrow,  KEY_RightArrow,  
  KEY_PageUp,  KEY_LeftAlt, 
  KEY_PageDown,  0,  0,  
  2,  KEY_ReturnEnter,  KEY_Spacebar
),
/*
* Keymap: Default Layer Windows and Linux dvorak (Layer 1)
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |   Esc  |   1  |   2  |   3  |   4  |   5  |  `   |           |   ~  |   6  |   7  |   8  |   9  |   0  |   =    |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |   Tab  |   '  |   ,  |   .  |   P  |   Y  |  \   |           |   /  |   F  |   G  |   C  |   R  |   L  |   -    |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |   Tab  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   ]    |
* |--------+------+------+------+------+------|  {   |           |   }  |------+------+------+------+------+--------|
* |    (   |   Z  |   X  |   C  |   V  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |   )    |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   | ~L4  |      | LGUI | LCtr |LShift|                                       | ~L5  | Left | Down |  Up  | Rigth|
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        | Copy |  Cut |       | PgUp | LAlt |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      | Paste|       | PgDn |      |      |
*                                 | BkSp | Del  |------|       |------| Enter| Space|
*                                 |      |      | ~L2  |       | ~L2  |      |      |
*                                 `--------------------'       `--------------------'
*/
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  KEY_Escape, KEY_1_Exclamation,  KEY_2_At, KEY_3_Pound,  KEY_4_Dollar, KEY_5_Percent,  KEY_GraveAccent_Tilde,  
  KEY_Tab, KEY_SingleQuote_DoubleQuote,  KEY_Comma_LessThan, KEY_Period_GreaterThan, KEY_p_P,  KEY_y_Y,  KEY_Backslash_Pipe,  
  KEY_LeftBracket_LeftBrace,  KEY_a_A,  KEY_o_O,  KEY_e_E,  KEY_u_U,  KEY_i_I,  
  KEY_9_LeftParenthesis,  KEY_Semicolon_Colon,  KEY_q_Q,  KEY_j_J,  KEY_k_K,  KEY_x_X,  _bracketL,  
                      4,   0, KEY_LeftGUI,  KEY_LeftControl,  KEY_LeftShift,  
                                                                                    KEY_c_C, KEY_x_X,  
                                                                                    0,  0,  KEY_v_V,  
                                                          KEY_DeleteBackspace,  KEY_DeleteForward,  2,  
  // right hand
              KEY_GraveAccent_Tilde,  KEY_6_Caret,  KEY_7_Ampersand,  KEY_8_Asterisk, KEY_9_LeftParenthesis,  KEY_0_RightParenthesis, KEY_Equal_Plus,  
              KEY_Slash_Question,  KEY_f_F,  KEY_g_G,  KEY_c_C,  KEY_r_R,  KEY_l_L,  KEY_Dash_Underscore, 
                  KEY_d_D,  KEY_h_H,  KEY_t_T,  KEY_n_N,  KEY_s_S,  KEY_RightBracket_RightBrace,  
              _bracketR,  KEY_b_B,  KEY_m_M,  KEY_w_W,  KEY_v_V,  KEY_z_Z,  KEY_0_RightParenthesis, 
                  5, KEY_LeftArrow,  KEY_DownArrow,  KEY_UpArrow,  KEY_RightArrow,  
  KEY_PageUp,  KEY_LeftAlt, 
  KEY_PageDown,  0,  0,  
  2,  KEY_ReturnEnter,  KEY_Spacebar
),
/*
* Keymap: Default Layer F1-F12 and numpad (Layer 2)
* 
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |        |  F6  |  F7  |  F8  |  F9  |  F10 |      |           |      |      |   7  |  8   |  9   |      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |  F11 |  F12 |      |      |      |------|           |------|      |   6  |  5   |  4   |      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |      |      |      |      |      |      |           |      |      |   1  |  2   |  3   |      |        |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |      |      |      |      |      |                                       |   0  |      |      |      |      |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        |F2+Cp |F2+Cut|       |      |      |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      |F2+Pst|       |      |      |      |
*                                 |      |      |------|       |------|      |      |
*                                 |      |      |      |       |      |      |      |
*                                 `--------------------'       `--------------------'
*/
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  0,  KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, 0,  
  0,  KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10,  0,  
  0,  KEY_F11,  KEY_F12,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  4,  0,  0,  0,  0,  
  _C,  _X,  
  0,  0,  _V,  
  0,  0,  0,  
  // right hand
    0, 0,     0,        0,        0,        0, 0,
    0, 0, _7_kp,     _8_kp,   _9_kp,        0, 0,
       0, _4_kp,     _5_kp,   _6_kp,        0, 0,
    0, 0, _1_kp,     _2_kp,   _3_kp,        0, 0,
          _0_kp,         0,       0,        0, 0,
0, 0,
0, 0, 0,
0, 0, 0
),
/*
* Keymap: Default Layer Gamer WIP (Layer 3)
* 
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |        |      |  w   |      |      |      |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |  a   |  s   |  d   |      |      |------|           |------|      |      |      |      |      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   | ~L4  |      | RAlt | LCtr |LShift|                                       |      |      |      |      |      |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        |      |      |       |      |      |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      |      |       |      |      |      |
*                                 | Space|      |------|       |------|      |      |
*                                 |      |      |      |       |      |      |      |
*                                 `--------------------'       `--------------------'
*/
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  _W,  0,  0,  0,  
  0,  0,  _A,  _S,  _D,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  4,  0,  KEY_RightAlt,  KEY_LeftControl,  KEY_LeftShift,  
  0,  0,  
  0,  0,  0,  
  _space,  0,  0,  
  // right hand
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  
  0,  0,  
  0,  0,  0,  
  0,  0,  0 
),
/*
* Keymap: Default Layer Utils, spanish chars and media(Layer 4)
* 
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |        |   ¡  |      |      |      |      |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |        |      |      |  €   |      |      |Ctr+  |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------|LGUI+Y|           |   ¿  |------+------+------+------+------+--------|
* |        |   á  |  ó   |  é   |  ú   |  í   |------|           |------|      |      |      |   ñ  |      | Vol Up |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |   á  |  ö   |  ë   |  ü   |  ï   |      |           |      |      |      |      |      |      | Vol Dn |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |      |      |      |      |      |                                       | Prev | Stop | Pause| Next | Mute |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        |      |      |       |      |      |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      |      |       |      |      |      |
*                                 |      |      |------|       |------|      |      |
*                                 |      |      |      |       |      |      |Teensy|
*                                 `--------------------'       `--------------------'
*/
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  0,  _1,   0,   0,   0,   0,  0,  
  0,   0,   0,  _5,   0,   0, _Y,  
  0,  _A,  _O,  _E,  _U,  _I,  
  0,  _A,  _O,  _E,  _U,  _I,  0,  
  0,  0,  0,  0,  0,  
  0,  0,  
  0,  0,  0,  
  0,  0,  0,  
  // right hand
  0,  0,  1,  2,  3,  0,  0,  
  _slash, 0,  0,  0,  0,  0,  0,  
  0,  0,  0, _N, 0,  MEDIAKEY_AUDIO_VOL_UP, 
  0, 0,  0, 0,  0,  0,  MEDIAKEY_AUDIO_VOL_DOWN,  
  MEDIAKEY_PREV_TRACK,  MEDIAKEY_STOP,  MEDIAKEY_PLAY_PAUSE,  MEDIAKEY_NEXT_TRACK,  MEDIAKEY_AUDIO_MUTE,  
  0,  0,  
  0,  0,  0,  
  0,  0,  0 
),
/*
* Keymap: Default Layer Utils, spanish chars and media Windows and Linux(Layer 5)
* 
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |        |   ¡  |      |      |      |      |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |        |      |      |  €   |      |      |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------|      |           |   ¿  |------+------+------+------+------+--------|
* |        |   á  |  é   |  é   |  ú   |  í   |------|           |------|      |      |      |   ñ  |      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |      |      |      |  ü   |      |      |           |      |      |      |      |      |      |        |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |      |      |      |      |      |                                       |      |      |      |      |      |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        |      |      |       |      |      |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      |      |       |      |      |      |
*                                 |      |      |------|       |------|      |      |
*                                 |      |      |      |       |      |      |      |
*                                 `--------------------'       `--------------------'
*/
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  0,  _1,  0,  0,  0,  0,  0,  
  0,   0,   0,  _5,   0,   0,  0,
  0,  _A,  _O,  _E,  _U,  _I,  
  0,  _A,  _O,  _E,  _U,  _I,  0,  
  0,  0,  0,  0,  0,  
  0,  0,  
  0,  0,  0,  
  0,  0,  0,  
  // right hand
  0,  0,  0,  0,  0,  0,  0,  
  _slash,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  _N,  0,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  
  0,  0,  
  0,  0,  0,  
  0,  0,  0 
),
};
// ----------------------------------------------------------------------------

// PRESS ----------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
            lpush4, NULL, kprrel, kprrel, kprrel, 
                                                            NULL, NULL, 
                                                      NULL, NULL, NULL, 
                                                    kprrel, kprrel, lpush2, 
  // right hand
              sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
              kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,  
                    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
              sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
                    lpush4, kprrel, kprrel, kprrel, kprrel,
  kprrel, kprrel, 
  kprrel, NULL, NULL, 
  lpush2, kprrel, kprrel  
),
// LAYER 1
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
            lpush4, NULL, kprrel, kprrel, kprrel, 
                                                            NULL, NULL, 
                                                      NULL, NULL, NULL, 
                                                    kprrel, kprrel, lpush2, 
  // right hand
              sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
              kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,  
                    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
              sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
                    lpush5, kprrel, kprrel, kprrel, kprrel, 
  kprrel, kprrel, 
  kprrel, NULL, NULL, 
  lpush2, kprrel, kprrel  
),
// LAYER 3
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  NULL, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, 
  NULL, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, 
  NULL, kprrel, kprrel, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  lpush4, NULL, NULL, NULL, NULL, 
  macrf2ctl, macrf2ctl, 
  NULL, NULL, macrf2ctl, 
  NULL, NULL, NULL, 
  // right hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, kprrel, kprrel, kprrel, NULL, NULL, 
        NULL, kprrel, kprrel, kprrel, NULL, NULL, 
  NULL, NULL, kprrel, kprrel, kprrel, NULL, NULL, 
              kprrel, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL
),
// LAYER 4
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, kprrel, NULL, NULL, NULL, 
  NULL, NULL, kprrel, kprrel, kprrel, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  lpush4, NULL, kprrel, kprrel, kprrel, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  kprrel, NULL, NULL, 
  // right hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL  
),
// LAYER 5
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  NULL, altgui, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, altgrprre, NULL, NULL, ctrgui, 
  NULL, tildemac, tildemac, tildemac, tildemac, tildemac,  
  NULL, dieresismac, dieresismac, dieresismac, dieresismac, dieresismac, NULL, 
  NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
  // right hand
  NULL, lpop,  lpush1,  lpush2,  lpush3,  NULL, NULL, 
  altgui, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, enhemac, NULL, mprrel, 
  NULL, NULL, NULL, NULL, NULL, NULL, mprrel, 
  mprrel, mprrel, mprrel, mprrel, mprrel, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, dbtldr  
),
// LAYER 6
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  NULL, altgrprre, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, altgrprre, NULL, NULL, NULL, 
  NULL, tildepc, tildepc, tildepc, tildepc, tildepc, 
  NULL, dieresispc, dieresispc, dieresispc, dieresispc, dieresispc, NULL, 
  NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
  // right hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  altgrprre, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, enhepc, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, dbtldr  
),
};
// ----------------------------------------------------------------------------

// RELEASE --------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
            lpop4, NULL, kprrel, kprrel, kprrel, 
                                                            modmac, modmac, 
                                                      NULL, NULL, modmac,
                                                    kprrel, kprrel, lpop2, 
  // right hand
                sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,  
                      kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
                sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
                       lpop4, kprrel, kprrel, kprrel, kprrel,
  kprrel, kprrel, 
  kprrel, NULL, NULL, 
  lpop2, kprrel, kprrel  
),
// LAYER 1
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
            lpop4, NULL, kprrel, kprrel, kprrel, 
                                                            modwl, modwl, 
                                                      NULL, NULL, modwl,
                                                    kprrel, kprrel, lpop2, 
  // right hand
                sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,  
                      kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
                sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
                       lpop5, kprrel, kprrel, kprrel, kprrel,
  kprrel, kprrel, 
  kprrel, NULL, NULL, 
  lpop2, kprrel, kprrel  
),
// LAYER 3
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  NULL, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, 
  NULL, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, 
  NULL, kprrel, kprrel, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  lpop4,  NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
  // right hand
  NULL, NULL,   NULL,   NULL,   NULL, NULL, NULL, 
  NULL, NULL, kprrel, kprrel, kprrel, NULL, NULL, 
        NULL, kprrel, kprrel, kprrel, NULL, NULL, 
  NULL, NULL, kprrel, kprrel, kprrel, NULL, NULL, 
              kprrel, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL 
),
// LAYER  4
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, kprrel, NULL, NULL, NULL, 
  NULL, NULL, kprrel, kprrel, kprrel, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  lpop4,  NULL, kprrel, kprrel, kprrel, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  kprrel, NULL, NULL, 
  // right hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL  
),
// LAYER 5
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  NULL, altgui, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, altgrprre, NULL, NULL, NULL, 
  NULL, kprrel, kprrel, kprrel, kprrel, kprrel,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
  // right hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  altgui, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, kprrel, NULL, mprrel, 
  NULL, NULL, NULL, NULL, NULL, NULL, mprrel, 
  mprrel, mprrel, mprrel, mprrel, mprrel, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL  
),
// LAYER  6
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand7
  NULL, altgrprre, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, altgrprre, NULL, NULL, NULL, 
  NULL, kprrel, kprrel, kprrel, kprrel, kprrel, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL,  NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
  // right hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  altgrprre, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, kprrel, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL  
),
};
// ----------------------------------------------------------------------------

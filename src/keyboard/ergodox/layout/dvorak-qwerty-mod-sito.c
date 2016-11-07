
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
#define  saeprre  &kbfun_altgr_e_press_release
#define  sanprre  &kbfun_altgr_n_press_release

#define  vsave     &kbfun_vim_save
#define  vsaveq    &kbfun_vim_save_and_quit
#define  vbuff     &kbfun_vim_buffers

#define  modmac     &kbfun_mod_mac_press_release
#define  modwl      &kbfun_mod_wl_press_release

// ----------------------------------------------------------------------------

// LAYOUT ---------------------------------------------------------------------
const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0: Mac dvorak
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  KEY_Escape, KEY_1_Exclamation,  KEY_2_At, KEY_3_Pound,  KEY_4_Dollar, KEY_5_Percent,  0,  
  KEY_Tab, KEY_SingleQuote_DoubleQuote,  KEY_Comma_LessThan, KEY_Period_GreaterThan, KEY_p_P,  KEY_y_Y,  KEY_Backslash_Pipe,  
  KEY_LeftBracket_LeftBrace,  KEY_a_A,  KEY_o_O,  KEY_e_E,  KEY_u_U,  KEY_i_I,  
  KEY_9_LeftParenthesis,  KEY_Semicolon_Colon,  KEY_q_Q,  KEY_j_J,  KEY_k_K,  KEY_x_X,  _bracketL,  
                      5,   0,  KEY_LeftControl, KEY_LeftGUI,  KEY_LeftShift,  
                                                                                    KEY_c_C, KEY_x_X,  
                                                                                    0,  0,  KEY_v_V,  
                                                          KEY_DeleteBackspace,  KEY_DeleteForward,  3,  
  // right hand
              0,  KEY_6_Caret,  KEY_7_Ampersand,  KEY_8_Asterisk, KEY_9_LeftParenthesis,  KEY_0_RightParenthesis, KEY_Equal_Plus,  
              KEY_Slash_Question,  KEY_f_F,  KEY_g_G,  KEY_c_C,  KEY_r_R,  KEY_l_L,  KEY_Dash_Underscore, 
                  KEY_d_D,  KEY_h_H,  KEY_t_T,  KEY_n_N,  KEY_s_S,  KEY_RightBracket_RightBrace,  
              _bracketR,  KEY_b_B,  KEY_m_M,  KEY_w_W,  KEY_v_V,  KEY_z_Z,  KEY_0_RightParenthesis, 
                  0, KEY_LeftArrow,  KEY_DownArrow,  KEY_UpArrow,  KEY_RightArrow,  
  0,  KEY_LeftAlt, 
  0,  0,  0,  
  3,  KEY_ReturnEnter,  KEY_Spacebar  
),
// LAYER 1: Windows and Linux dvorak
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  KEY_Escape, KEY_1_Exclamation,  KEY_2_At, KEY_3_Pound,  KEY_4_Dollar, KEY_5_Percent,  0,  
  KEY_Tab, KEY_SingleQuote_DoubleQuote,  KEY_Comma_LessThan, KEY_Period_GreaterThan, KEY_p_P,  KEY_y_Y,  KEY_Backslash_Pipe,  
  KEY_LeftBracket_LeftBrace,  KEY_a_A,  KEY_o_O,  KEY_e_E,  KEY_u_U,  KEY_i_I,  
  KEY_9_LeftParenthesis,  KEY_Semicolon_Colon,  KEY_q_Q,  KEY_j_J,  KEY_k_K,  KEY_x_X,  _bracketL,  
                      5,   0, KEY_LeftGUI,  KEY_LeftControl,  KEY_LeftShift,  
                                                                                    KEY_c_C, KEY_x_X,  
                                                                                    0,  0,  KEY_v_V,  
                                                          KEY_DeleteBackspace,  KEY_DeleteForward,  3,  
  // right hand
              0,  KEY_6_Caret,  KEY_7_Ampersand,  KEY_8_Asterisk, KEY_9_LeftParenthesis,  KEY_0_RightParenthesis, KEY_Equal_Plus,  
              KEY_Slash_Question,  KEY_f_F,  KEY_g_G,  KEY_c_C,  KEY_r_R,  KEY_l_L,  KEY_Dash_Underscore, 
                  KEY_d_D,  KEY_h_H,  KEY_t_T,  KEY_n_N,  KEY_s_S,  KEY_RightBracket_RightBrace,  
              _bracketR,  KEY_b_B,  KEY_m_M,  KEY_w_W,  KEY_v_V,  KEY_z_Z,  KEY_0_RightParenthesis, 
                  0, KEY_LeftArrow,  KEY_DownArrow,  KEY_UpArrow,  KEY_RightArrow,  
  0,  KEY_LeftAlt, 
  0,  0,  0,  
  3,  KEY_ReturnEnter,  KEY_Spacebar  
),
// LAYER 2: Qwerty
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  KEY_Escape, KEY_1_Exclamation,  KEY_2_At, KEY_3_Pound,  KEY_4_Dollar, KEY_5_Percent,  0,
  KEY_Tab,  KEY_q_Q,  KEY_w_W,  KEY_e_E,  KEY_r_R,  KEY_t_T,  0,  
  0,  KEY_a_A,  KEY_s_S,  KEY_d_D,  KEY_f_F,  KEY_g_G,  
  0,  KEY_z_Z,  KEY_x_X,  KEY_c_C,  KEY_v_V,  KEY_b_B,  0,  
                      5,   0, KEY_LeftGUI,  KEY_LeftControl,  KEY_LeftShift,  
                                                                                    KEY_c_C, KEY_x_X,  
                                                                                    0,  0,  KEY_v_V,  
                                                          KEY_DeleteBackspace,  KEY_DeleteForward,  3,  
  // right hand
              0,  KEY_6_Caret,  KEY_7_Ampersand,  KEY_8_Asterisk, KEY_9_LeftParenthesis,  KEY_0_RightParenthesis, KEY_RightBracket_RightBrace,  
              0,  KEY_y_Y,  KEY_u_U,  KEY_i_I,  KEY_o_O,  KEY_p_P,  KEY_LeftBracket_LeftBrace,  
                  KEY_h_H,  KEY_j_J,  KEY_k_K,  KEY_l_L,  KEY_n_N,  KEY_SingleQuote_DoubleQuote,  
              0,  KEY_n_N,  KEY_m_M,  KEY_Semicolon_Colon,  KEY_Comma_LessThan, KEY_Period_GreaterThan, KEY_Dash_Underscore,    
                  0, KEY_LeftArrow,  KEY_DownArrow,  KEY_UpArrow,  KEY_RightArrow,  
  0,  KEY_RightAlt, 
  0,  0,  0,  
  3,  KEY_ReturnEnter,  KEY_Spacebar 
),
// LAYER 3: F1-F12 and numpad
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  0,  KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, 0,  
  0,  KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10,  0,  
  0,  KEY_F11,  KEY_F12,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  5,  0,  0,  0,  0,  
  0,  0,  
  0,  0,  0,  
  0,  0,  0,  
  // right hand
    0, 0,     0,        0,        0,        0, 0,
    0, 0, _7_kp,     _8_kp,   _9_kp,        0, 0,
       0, _4_kp,     _5_kp,   _6_kp,        0, 0,
    0, 0, _1_kp,     _2_kp,   _3_kp,        0, 0,
              0,         0,       0,        0, 0,
0, 0,
0, 0,     0,
0, 0, _0_kp
),
// LAYER 4: Empty
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  5,  0,  0,  0,  0,  
  0,  0,  
  0,  0,  0,  
  0,  0,  0,  
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
// LAYER 5: Change layer and media
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  
  0,  0,  
  0,  0,  0,  
  0,  0,  0,  
  // right hand
  0,  0,  1,  2,  3,  4,  0,  
  KEY_VolumeUp, 0,  0,  0,  0,  0,  0,  
  0,  0,  0, KEY_n_N, 0,  0, 
  KEY_VolumeDown, 0,  KEY_Stop, 0,  KEY_Pause,  0,  0,  
  0,  0,  0,  0,  0,  
  0,  0,  
  0,  0,  0,  
  0,  0,  0 
),
// LAYER 6: Empty
KB_MATRIX_LAYER(
  // unused
  0,  
  // left hand
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  
  0,  0,  0,  0,  0,  0,  0,  
  5,  0,  0,  0,  0,  
  0,  0,  
  0,  0,  0,  
  0,  0,  0,  
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
};
// ----------------------------------------------------------------------------

// PRESS ----------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, 
  kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
            lpush5, NULL, kprrel, kprrel, kprrel, 
                                                            NULL, NULL, 
                                                      NULL, NULL, NULL, 
                                                    kprrel, kprrel, lpush3, 
  // right hand
              NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
              kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,  
                    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
              sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
                    NULL, kprrel, kprrel, kprrel, kprrel,
  NULL, kprrel, 
  NULL, NULL, NULL, 
  lpush3, kprrel, kprrel  
),
// LAYER 1
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, 
  kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
            lpush5, NULL, kprrel, kprrel, kprrel, 
                                                            NULL, NULL, 
                                                      NULL, NULL, NULL, 
                                                    kprrel, kprrel, lpush3, 
  // right hand
              NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
              kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,  
                    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
              sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
                    NULL, kprrel, kprrel, kprrel, kprrel, 
  NULL, kprrel, 
  NULL, NULL, NULL, 
  lpush3, kprrel, kprrel  
),
// LAYER 2
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, 
  ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans, 
  ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, 
  ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans, 
            lpush5, NULL, kprrel, kprrel, kprrel, 
                                                          NULL, NULL, 
                                                    NULL, NULL, NULL, 
                                                    kprrel, kprrel, lpush3, 
  // right hand
              ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, kprrel, 
              ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
                      kprrel, kprrel, kprrel, kprrel, sanprre, kprrel, 
              ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans, 
                    0, kprrel, kprrel, kprrel, kprrel, 
  NULL, kprrel, 
  NULL, NULL, NULL, 
  lpush3, kprrel, kprrel 
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
  lpush5, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
  // right hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, kprrel, kprrel, kprrel, NULL, NULL, 
        NULL, kprrel, kprrel, kprrel, NULL, NULL, 
  NULL, NULL, kprrel, kprrel, kprrel, NULL, NULL, 
                NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, kprrel  
),
// LAYER 4
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  lpush5, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
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
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  dbtldr, NULL, NULL, 
  // right hand
  NULL, lpop,  lpush1,  lpush2,  lpush3,  lpush4, NULL, 
  kprrel, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, sanprre, NULL, NULL, 
  kprrel, NULL, kprrel, NULL, kprrel, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL  
),
// LAYER 6
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  lpush5, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
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
};
// ----------------------------------------------------------------------------

// RELEASE --------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, 
  kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
            lpop5, NULL, kprrel, kprrel, kprrel, 
                                                            modmac, modmac, 
                                                      NULL, NULL, modmac,
                                                    kprrel, kprrel, lpop3, 
  // right hand
                NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,  
                      kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
                sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
                       NULL, kprrel, kprrel, kprrel, kprrel,
  NULL, kprrel, 
  NULL, NULL, NULL, 
  lpop3, kprrel, kprrel  
),
// LAYER 1
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, NULL, 
  kprrel,  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
  sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
            lpop5, NULL, kprrel, kprrel, kprrel, 
                                                            modwl, modwl, 
                                                      NULL, NULL, modwl,
                                                    kprrel, kprrel, lpop3, 
  // right hand
                NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,  
                      kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
                sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, sshprre, 
                       NULL, kprrel, kprrel, kprrel, kprrel,
  NULL, kprrel, 
  NULL, NULL, NULL, 
  lpop3, kprrel, kprrel  
),
// LAYER 2
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, 
  ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans, 
  ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, 
  ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans, 
            lpop5, NULL, kprrel, kprrel, kprrel, 
                                                            modwl, modwl, 
                                                      NULL, NULL, modwl,
                                                    kprrel, kprrel, lpop3, 
  // right hand
              ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, kprrel, 
              ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
                      kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, 
              ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans, 
                       NULL, kprrel, kprrel, kprrel, kprrel, 
  NULL, kprrel, 
  NULL, NULL, NULL, 
  lpop3, kprrel, kprrel   
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
  lpop5,  NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
  // right hand
  NULL, NULL,   NULL,   NULL,   NULL, NULL, NULL, 
  NULL, NULL, kprrel, kprrel, kprrel, NULL, NULL, 
        NULL, kprrel, kprrel, kprrel, NULL, NULL, 
  NULL, NULL, kprrel, kprrel, kprrel, NULL, NULL, 
                NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, kprrel  
),
// LAYER  4
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  lpop5,  NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
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
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
  // right hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  kprrel, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, kprrel, NULL, NULL, 
  kprrel, NULL, kprrel, NULL, kprrel, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL  
),
// LAYER  6
KB_MATRIX_LAYER(
  // unused
  NULL, 
  // left hand
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, 
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
  lpop5,  NULL, NULL, NULL, NULL, 
  NULL, NULL, 
  NULL, NULL, NULL, 
  NULL, NULL, NULL, 
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
};
// ----------------------------------------------------------------------------

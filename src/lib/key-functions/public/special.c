/* ----------------------------------------------------------------------------
 * key functions : special : code
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <stdbool.h>
#include <stdint.h>
#include "../../../lib-other/pjrc/usb_keyboard/usb_keyboard.h"
#include "../../../lib/usb/usage-page/keyboard.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../keyboard/layout.h"
#include "../../../main.h"
#include "../public.h"
#include "../private.h"
#include <util/delay.h>

// ----------------------------------------------------------------------------

// convenience macros
#define  LAYER         main_arg_layer
#define  LAYER_OFFSET  main_arg_layer_offset
#define  ROW           main_arg_row
#define  COL           main_arg_col
#define  IS_PRESSED    main_arg_is_pressed
#define  WAS_PRESSED   main_arg_was_pressed

/* ----------------------------------------------------------------------------
 * private utility functions
 * ------------------------------------------------------------------------- */
void _write_2_combined_code(uint8_t combined_a, uint8_t combined_b, uint8_t keycode) {
  _kbfun_press_release(true, combined_a);
  _kbfun_press_release(true, combined_b);
  _kbfun_press_release(true, keycode);
  usb_keyboard_send();
  _delay_ms(MAKEFILE_DEBOUNCE_TIME);

  _kbfun_press_release(false, combined_a);
  _kbfun_press_release(false, combined_b);
  _kbfun_press_release(false, keycode);
  usb_keyboard_send();
  _delay_ms(MAKEFILE_DEBOUNCE_TIME);
}

void _write_combined_code(uint8_t combined, uint8_t keycode) {
  _write_2_combined_code(0, combined, keycode);
}

void write_code(uint8_t keycode) {
  _write_combined_code(0, keycode);
}

void write_shifted_code(uint8_t keycode) {
  _write_combined_code(KEY_RightShift, keycode);
}

void write_ctrled_code(uint8_t keycode) {
  _write_combined_code(KEY_LeftControl, keycode);
}

void write_alted_code(uint8_t keycode) {
  _write_combined_code(KEY_RightAlt, keycode);
}

void write_guied_code(uint8_t keycode) {
  _write_combined_code(KEY_LeftGUI, keycode);
}

void write_guied_alted_code(uint8_t keycode) {
  _write_2_combined_code(KEY_LeftGUI, KEY_RightAlt, keycode);
}

void write_guied_ctred_code(uint8_t keycode) {
  _write_2_combined_code(KEY_LeftGUI, KEY_LeftControl, keycode);
}


// ----------------------------------------------------------------------------

/*
 * [name]
 *   AltGr + press|release
 *
 * [description]
 *   Generate a 'AltGr' press or release before the normal keypress or
 *   keyrelease
 */
void kbfun_altgr_press_release(void) {
  _kbfun_press_release(IS_PRESSED, KEY_RightAlt);
  kbfun_press_release();
}
/*
 * [name]
 *   Shift + press|release
 *
 * [description]
 *   Generate a 'shift' press or release before the normal keypress or
 *   keyrelease
 */
void kbfun_shift_press_release(void) {
  _kbfun_press_release(IS_PRESSED, KEY_LeftShift);
  kbfun_press_release();
}

/*
 * [name]
 *   Two keys => capslock
 *
 * [description]
 *   When assigned to two keys (e.g. the physical left and right shift keys)
 *   (in both the press and release matrices), pressing and holding down one of
 *   the keys will make the second key toggle capslock
 *
 * [note]
 *   If either of the shifts are pressed when the second key is pressed, they
 *   wil be released so that capslock will register properly when pressed.
 *   Capslock will then be pressed and released, and the original state of the
 *   shifts will be restored
 */
void kbfun_2_keys_capslock_press_release(void) {
  static uint8_t keys_pressed;
  static bool lshift_pressed;
  static bool rshift_pressed;

  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);

  if (!IS_PRESSED) keys_pressed--;

  // take care of the key that was actually pressed
  _kbfun_press_release(IS_PRESSED, keycode);

  // take care of capslock (only on the press of the 2nd key)
  if (keys_pressed == 1 && IS_PRESSED) {
    // save the state of left and right shift
    lshift_pressed = _kbfun_is_pressed(KEY_LeftShift);
    rshift_pressed = _kbfun_is_pressed(KEY_RightShift);
    // disable both
    _kbfun_press_release(false, KEY_LeftShift);
    _kbfun_press_release(false, KEY_RightShift);

    // press capslock, then release it
    _kbfun_press_release(true, KEY_CapsLock);
    usb_keyboard_send();
    _kbfun_press_release(false, KEY_CapsLock);
    usb_keyboard_send();

    // restore the state of left and right shift
    if (lshift_pressed)
      _kbfun_press_release(true, KEY_LeftShift);
    if (rshift_pressed)
      _kbfun_press_release(true, KEY_RightShift);
  }

  if (IS_PRESSED) keys_pressed++;
}

/* ----------------------------------------------------------------------------
 * numpad functions
 * ------------------------------------------------------------------------- */

static uint8_t numpad_layer_id;

static inline void numpad_toggle_numlock(void) {
  _kbfun_press_release(true, KEY_LockingNumLock);
  usb_keyboard_send();
  _kbfun_press_release(false, KEY_LockingNumLock);
  usb_keyboard_send();
}

/*
 * [name]
 *   Numpad on
 *
 * [description]
 *   Set the numpad to on (put the numpad layer, specified in the keymap, in an
 *   element at the top of the layer stack, and record that element's id) and
 *   toggle numlock (regardless of whether or not numlock is currently on)
 *
 * [note]
 *   Meant to be assigned (along with "numpad off") instead of a normal numlock
 *   key
 */
void kbfun_layer_push_numpad(void) {
  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
  main_layers_pop_id(numpad_layer_id);
  numpad_layer_id = main_layers_push(keycode, eStickyNone);
  numpad_toggle_numlock();
}

/*
 * [name]
 *   Numpad off
 *
 * [description]
 *   Set the numpad to off (pop the layer element created by "numpad on" out of
 *   the stack) and toggle numlock (regardless of whether or not numlock is
 *   currently on)
 *
 * [note]
 *   Meant to be assigned (along with "numpad on") instead of a normal numlock
 *   key
 */
void kbfun_layer_pop_numpad(void) {
  main_layers_pop_id(numpad_layer_id);
  numpad_layer_id = 0;
  numpad_toggle_numlock();
}


/* ----------------------------------------------------------------------------
 * media functions
 * ------------------------------------------------------------------------- */

/*
 * [name]
 *   Media Key Press Release
 *
 * [description]
 *   Generate a keypress for a media key, such as play/pause, next track, or
 *   previous track
 *
 */
void kbfun_mediakey_press_release(void) {
  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
  _kbfun_mediakey_press_release(IS_PRESSED, keycode);
}

/* ----------------------------------------------------------------------------
 * symbol functions
 * ------------------------------------------------------------------------- */

 /*
 * [name]
 *   Special char:
 *   e = tilde
 *   u = dieresis
 *
 * [description]
 *   See: https://forlang.wsu.edu/help-pages/help-pages-keyboards-os-x/
 */
void kbfun_special_mac_press_release(uint8_t mod, uint8_t keycode) {
  
  /* Remember old state of shift before disabling it */
  bool right_shift_was_pressed = _kbfun_is_pressed(KEY_RightShift); 
  bool left_shift_was_pressed = _kbfun_is_pressed(KEY_LeftShift); 
  _kbfun_press_release(false, KEY_RightShift);
  _kbfun_press_release(false, KEY_LeftShift);

  write_alted_code(mod);

  _kbfun_press_release(right_shift_was_pressed, KEY_RightShift);
  _kbfun_press_release(left_shift_was_pressed, KEY_LeftShift);

  write_code(keycode);
}

/*
 * [name]
 *   SingleQuote + press|release
 *
 * [description]
 *   See: https://forlang.wsu.edu/help-pages/microsoft-keyboards-english-us-international/
 *   Generate a SingleQuote (acute accent) press or release before the normal keypress or
 *   keyrelease
 */
void kbfun_tilde_pc_press_release(void) {
  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
  
  write_alted_code(keycode);
}

void kbfun_dieresis_pc_press_release(void) {
  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
  write_shifted_code(KEY_SingleQuote_DoubleQuote);
  write_code(keycode);
}
/*
 * [name]
 *   AltGr + e + press|release
 */
void kbfun_tilde_mac_press_release(void) {
  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
  kbfun_special_mac_press_release(KEY_e_E, keycode);
}

/*
 * [name]
 *   AltGr + u + press|release
 */
void kbfun_dieresis_mac_press_release(void) {
  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
  kbfun_special_mac_press_release(KEY_u_U, keycode);
}

/*
 + * [name]
 + *   AltGr + n
 + *
 + * [description]
 + *   Generate a 'ñ'
 + */
 void kbfun_altgr_n_pc_press_release(void) {
  write_alted_code(KEY_n_N);
 }

 void kbfun_altgr_n_mac_press_release(void) {
  write_alted_code(KEY_n_N);
  write_code(KEY_n_N);
 }

/* ----------------------------------------------------------------------------
 * macro functions
 * ------------------------------------------------------------------------- */

/*
 * [name]
 *   vim save ':w'
 *
 * [description]
 *   Writes the string ':w' 
 */
void kbfun_vim_save(void) {
  /* Remember old state of shift before disabling it */
  bool right_shift_was_pressed = _kbfun_is_pressed(KEY_RightShift); 
  bool left_shift_was_pressed = _kbfun_is_pressed(KEY_LeftShift); 
  _kbfun_press_release(false, KEY_RightShift);
  _kbfun_press_release(false, KEY_LeftShift);

  // ':'
  write_shifted_code(KEY_Semicolon_Colon);
  // 'w'
  write_code(KEY_w_W);
  // 'Enter'
  write_code(KEY_ReturnEnter);

  _kbfun_press_release(right_shift_was_pressed, KEY_RightShift);
  _kbfun_press_release(left_shift_was_pressed, KEY_LeftShift);
}

/*
 * [name]
 *   vim save and quit ':wq'
 *
 * [description]
 *   Writes the string ':w' 
 */
void kbfun_vim_save_and_quit(void) {
  /* Remember old state of shift before disabling it */
  bool right_shift_was_pressed = _kbfun_is_pressed(KEY_RightShift); 
  bool left_shift_was_pressed = _kbfun_is_pressed(KEY_LeftShift); 
  _kbfun_press_release(false, KEY_RightShift);
  _kbfun_press_release(false, KEY_LeftShift);

  // ':'
  write_shifted_code(KEY_Semicolon_Colon);
  // 'wq'
  write_code(KEY_w_W);
  write_code(KEY_q_Q);
  // 'Enter'
  write_code(KEY_ReturnEnter);

  _kbfun_press_release(right_shift_was_pressed, KEY_RightShift);
  _kbfun_press_release(left_shift_was_pressed, KEY_LeftShift);
}

/* ----------------------------------------------------------------------------
 * Copy, Cut and Paste
 * ------------------------------------------------------------------------- */
void kbfun_mod_mac_press_release(void) {
  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
  write_guied_code(keycode);
}

void kbfun_mod_wl_press_release(void) {
  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
  write_ctrled_code(keycode);
}

/* ----------------------------------------------------------------------------
 * Gui + Alt press|release
 * ------------------------------------------------------------------------- */
 void kbfun_mod_mac_alt_press_release(void) {
  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
  write_guied_alted_code(keycode);
 }

/* ----------------------------------------------------------------------------
 * Gui + Ctr press|release
 * ------------------------------------------------------------------------- */
 void kbfun_mod_mac_ctr_press_release(void) {
  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
  write_guied_ctred_code(keycode);
 }

/* ----------------------------------------------------------------------------
 * F2 + Ctrl+C
 * ------------------------------------------------------------------------- */
void macro_f2_ctrl_mod(void) {
  write_code(_F2);
  uint8_t keycode = kb_layout_get(LAYER, ROW, COL);
  write_ctrled_code(keycode);
  write_code(_enter);
}

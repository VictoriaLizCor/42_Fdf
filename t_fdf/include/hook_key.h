/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:41:17 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/27 12:42:00 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_KEY_H
# define HOOK_KEY_H
/*
** Arrow keys
*/

# ifdef __APPLE__
/*
** Special keys
** CL_KEY is the caps lock key
** LSFT_KEY and RLFT_KEY are the left shift and right shift keys
** LCTRL_KEY and RCTRL_KEY are the left control and right control keys
** LOPT_KEY and ROPT_KEY are the left option and right option keys
** LCMD_KEY and RCMD_KEY are the left command and right command keys
** LDEL_KEY and RDEL_KEY are the left delete and right delete keys
** RTN_KEY is the return key
** EJ_KEY is the eject key and doesn't react
** PUP_KEY and PDOWN_KEY are the page up and page down keys
** CLR_KEY is the clear key
*/

#  define ESC_KEY 53
#  define TAB_KEY 48
#  define CL_KEY 272
#  define LSFT_KEY 257
#  define LCTRL_KEY 256
#  define LOPT_KEY 261
#  define LCMD_KEY 259
#  define LDEL_KEY 51
#  define RTN_KEY 36
#  define RSFT_KEY 258
#  define RCTRL_KEY 269
#  define ROPT_KEY 262
#  define RCMD_KEY 260
#  define EJ_KEY
#  define FN_KEY 279
#  define RDEL_KEY 117
#  define HOME_KEY 115
#  define END_KEY 119
#  define PUP_KEY 116
#  define PDOWN_KEY 121
#  define CLR_KEY 71
/*
** Macros for mlx_hook function
*/

#  define MAIN_PAD_I 34
#  define MAIN_PAD_P 35
#  define MAIN_PAD_D 2
#  define MAIN_PAD_U 32
#  define MAIN_PAD_T 17
#  define MAIN_PAD_R 15
#  define MAIN_PAD_F 3
#  define MAIN_PAD_V 9
#  define NUM_PAD_PLUS 69
#  define NUM_PAD_MINUS 78
#  define MAIN_PAD_ESC 53
#  define MAIN_PAD_C 8
#  define MAIN_PAD_0 29
#  define MAIN_PAD_1 18
#  define MAIN_PAD_2 19
#  define MAIN_PAD_3 20
#  define MAIN_PAD_4 21
#  define MAIN_PAD_5 23
#  define MAIN_PAD_6 22
#  define MAIN_PAD_7 26
#  define MAIN_PAD_8 28
#  define MAIN_PAD_9 25
#  define MOUSE_LEFT_KEY 1
#  define MOUSE_RIGHT_KEY 2
#  define MOUSE_THIRD_KEY 3
#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
#  define MOUSE_SCROLL_LEFT 6
#  define MOUSE_SCROLL_RIGHT 7
#  define ARROW_UP 126
#  define ARROW_DOWN 125
#  define ARROW_LEFT 123
#  define ARROW_RIGHT 124
#  define NUM_PAD_0 82
#  define NUM_PAD_1 83
#  define NUM_PAD_2 84
#  define NUM_PAD_3 85
#  define NUM_PAD_4 86
#  define NUM_PAD_5 87
#  define NUM_PAD_6 88
#  define NUM_PAD_7 89
#  define NUM_PAD_8 91
#  define NUM_PAD_9 92
#  define MP_PLUS 24
#  define MP_MINUS 27
#  define MP_LESS 43
#  define MP_MORE 47
# else
#  define ESC_KEY	0xff1b
#  define KEY_W		119
#  define KEY_A		97
#  define KEY_S		115
#  define KEY_D		100
#  define ARROW_UP	65362
#  define ARROW_DOWN	65364
#  define ARROW_LEFT	65361
#  define ARROW_RIGHT	65363
# endif
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:10:57 by adelille          #+#    #+#             */
/*   Updated: 2022/05/27 14:50:05 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYPRESS_H
# define KEYPRESS_H

// # if __linux__
// #  define K_ESC			65307
// #  define K_LEFT			65361
// #  define K_UP			65362
// #  define K_RIGHT		65363
// #  define K_DOWN			65364
// #  define K_W			119
// #  define K_A			97
// #  define K_S			115
// #  define K_D			100
// #  define K_Z			122
// #  define K_Q			113
// #  define M_SCROLL_UP	5
// #  define M_SCROLL_DOWN	4
// #  define K_M			109
// #  define K_N			110

//# elif __unix__
# define ARROW_LEFT		123
# define ARROW_RIGHT	124
# define ARROW_UP		126
# define ARROW_DOWN		125

# define MOUSE_UP		4
# define MOUSE_DOWN		5

# define MAINP_ESC		53
# define MAINP_SPACE	49
# define MAINP_Q		12
# define MAINP_E		14
# define MAINP_R		15
# define MAINP_DOT		47
# define MAINP_1		18
# define MAINP_2		19
# define MAINP_3		20
# define MAINP_4		21

# define NUMP_PLUS		69
# define NUMP_MINUS		78
# define NUMP_1			83
# define NUMP_2			84
# define NUMP_3			85
# define NUMP_4			86
//# endif
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:10:57 by adelille          #+#    #+#             */
/*   Updated: 2022/05/25 17:17:49 by fcil             ###   ########.fr       */
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
#  define K_ESC			53
#  define K_LEFT			123
#  define K_RIGHT		124
#  define K_DOWN			125
#  define K_UP			126
#  define K_W			13
#  define K_A			0
#  define K_S			1
#  define K_D			2
#  define K_Z			6
#  define K_Q			12
#  define M_SCROLL_UP	4
#  define M_SCROLL_DOWN	5
#  define K_M			46
#  define K_N			45
//# endif
#endif

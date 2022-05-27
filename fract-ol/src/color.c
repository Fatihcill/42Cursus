/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:14:43 by fcil              #+#    #+#             */
/*   Updated: 2022/05/27 19:56:59 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//rastlantısal şekilde hesapladığımız renkleri 8 bitlik inte atıyoruz ardından 
//integerımızın değerlerini birleştirerek rengimizi return ediyoruz.
static int	calc_color(t_fractol *frctl, size_t i)
{
	uint8_t	cs;
	uint8_t	rgb[3];

	cs = frctl->color_shift;
	rgb[cs % 3] = (i * 20) % 255;
	rgb[(cs + 1) % 3] = (i * 35) % 255;
	rgb[(cs + 2) % 3] = (i * 50) % 255;
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	get_color(t_fractol *frctl)
{
	return (frctl->color_scheme[frctl->iter]);
}

void	set_color_array(t_fractol *frctl)
{
	size_t	i;

	i = 0;
	while (i <= frctl->max_iter)
	{
		frctl->color_scheme[i] = calc_color(frctl, i);
		i++;
	}
	frctl->color_scheme[frctl->max_iter] = 0x000000;
}

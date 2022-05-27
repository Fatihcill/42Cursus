/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:19:00 by fcil              #+#    #+#             */
/*   Updated: 2022/05/27 16:51:49 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *frctl)
{
	t_complex	z;
	t_complex	tmp;

	z.re = frctl->c.re;
	z.im = frctl->c.im;
	tmp.re = z.re * z.re;
	tmp.im = z.im * z.im;
	frctl->iter = 0;
	while ((tmp.re + tmp.im <= 4) && frctl->iter < frctl->max_iter)
	{
		z.im = 2 * z.re * z.im + frctl->c.im;
		z.re = tmp.re - tmp.im + frctl->c.re;
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		frctl->iter++;
	}
}

void	julia(t_fractol *frctl)
{
	t_complex	z;
	t_complex	tmp;

	z.re = frctl->c.re;
	z.im = frctl->c.im;
	tmp.re = z.re * z.re;
	tmp.im = z.im * z.im;
	frctl->iter = 0;
	while ((tmp.re + tmp.im <= 4) && frctl->iter < frctl->max_iter)
	{
		z.im = 2 * z.re * z.im + frctl->c_julia.im;
		z.re = tmp.re - tmp.im + frctl->c_julia.re;
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		frctl->iter++;
	}
}

// void	burning_ship(t_fractol *frctl)
// {
// 	t_complex	z;
// 	t_complex	tmp;

// 	z.re = frctl->c.re;
// 	z.im = frctl->c.im;
// 	tmp.re = z.re * z.re;
// 	tmp.im = z.im * z.im;
// 	frctl->iter = 0;
// 	while ((tmp.re + tmp.im <= 4) && frctl->iter < frctl->max_iter)
// 	{
// 		z.im = -2 * fabs(z.re * z.im) + frctl->c.im;
// 		z.re = tmp.re - tmp.im + frctl->c.re;
// 		tmp.re = z.re * z.re;
// 		tmp.im = z.im * z.im;
// 		frctl->iter++;
// 	}
// }
void	burning_ship(t_fractol *frctl)
{
	t_complex	z;
	t_complex	tmp;

	z.re = frctl->c.re;
	z.im = frctl->c.im;
	tmp.re = z.re * z.re;
	tmp.im = z.im * z.im * z.im;
	frctl->iter = 0;
	while ((tmp.re + tmp.im <= 8) && frctl->iter < frctl->max_iter)
	{
		z.im = -2 * fabs(z.re * z.im) + frctl->c.im;
		z.re = tmp.re - tmp.im + frctl->c.re;
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		frctl->iter++;
	}
}

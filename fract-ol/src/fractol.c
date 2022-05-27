/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:19:00 by fcil              #+#    #+#             */
/*   Updated: 2022/05/27 19:57:12 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//y0 frctl->c.im
//x0 frctl->c.re
//x  z.re
//y  z.im
//tmp = x*x , y*y
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
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		z.im = 2 * z.re * z.im + frctl->c.im;
		z.re = tmp.re - tmp.im + frctl->c.re;
		frctl->iter++;
	}
}

//zx z.re
//zy z.im
//tmp = zx * zx , zy * zy
//cy frctl->c_julia.im
//cx frctl->c_julia.re
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
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		z.im = 2 * z.re * z.im + frctl->c_julia.im;
		z.re = tmp.re - tmp.im + frctl->c_julia.re;
		frctl->iter++;
	}
}

//tmp xtemp - a
//a  frctl->c.re
//y z.im
//x z.re
void	multibrot_set(t_fractol *frctl)
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
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		z.im = 3 * (z.re * z.re) * z.im - (tmp.im * z.im) + frctl->c.im;
		z.re = (tmp.re * z.re) - 3 * z.re * tmp.im + frctl->c.re;
		frctl->iter++;
	}
}

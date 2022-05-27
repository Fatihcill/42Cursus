/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:17:42 by fcil              #+#    #+#             */
/*   Updated: 2022/05/27 19:55:59 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_actions(int key, t_fractol *frctl)
{
	if (key == MAINP_ESC)
		fractol_free_kill_all(frctl);
	else if (key == MAINP_R)
		set_defaults(frctl);
	else if (key == ARROW_UP || key == ARROW_DOWN)
		move(key, frctl);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT)
		move(key, frctl);
	else if (key == MAINP_Q || key == NUMP_PLUS)
		change_maxiter(key, frctl);
	else if (key == MAINP_E || key == NUMP_MINUS)
		change_maxiter(key, frctl);
	else if (key >= MAINP_1 && key <= MAINP_4)
		fractal_change(key, frctl);
	else if (key >= NUMP_1 && key <= NUMP_4)
		fractal_change(key, frctl);
	else if (key == MAINP_SPACE)
		frctl->is_fixed = !frctl->is_fixed;
	else if (key == MAINP_DOT)
		color_shift(frctl);
	fractol_loop(frctl);
	return (0);
}

//	printf("min : %f - %f \n", frctl->c_min.im, frctl->c_min.re);
//	printf("max : %f - %f \n", frctl->c_max.im, frctl->c_max.re);
void	move(int key, t_fractol *frctl)
{
	t_complex	c_size;

	c_size.re = frctl->c_max.re - frctl->c_min.re;
	c_size.im = frctl->c_max.im - frctl->c_min.im;
	if (key == ARROW_UP)
	{
		frctl->c_min.im += c_size.im * 0.05;
		frctl->c_max.im += c_size.im * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		frctl->c_min.im -= c_size.im * 0.05;
		frctl->c_max.im -= c_size.im * 0.05;
	}
	else if (key == ARROW_LEFT)
	{
		frctl->c_min.re -= c_size.re * 0.05;
		frctl->c_max.re -= c_size.re * 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		frctl->c_min.re += c_size.re * 0.05;
		frctl->c_max.re += c_size.re * 0.05;
	}
}

void	fractal_change(int key, t_fractol *frctl)
{
	if (key == MAINP_1 || key == NUMP_1)
		frctl->fractal_func = mandelbrot;
	else if (key == MAINP_2 || key == NUMP_2)
		frctl->fractal_func = julia;
	else if (key == MAINP_3 || key == NUMP_3)
		frctl->fractal_func = multibrot_set;
	set_defaults(frctl);
}

//renk seçenekleri (6 renk belirleniyor)
void	color_shift(t_fractol *frctl)
{
	frctl->color_shift = (frctl->color_shift + 1) % 3;
	set_color_array(frctl);
}

void	change_maxiter(int key, t_fractol *frctl)
{
	if (key == MAINP_Q || key == NUMP_PLUS)
	{
		if (frctl->max_iter == MAX_ITER)
			return ;
		else if (frctl->max_iter < 50)
			frctl->max_iter += 1;
		else if (frctl->max_iter < MAX_ITER)
		{
			frctl->max_iter = (int)(frctl->max_iter * 1.05);
			if (frctl->max_iter > MAX_ITER)
				frctl->max_iter = MAX_ITER;
		}
	}
	else if (key == MAINP_E || key == NUMP_MINUS)
	{
		if (frctl->max_iter > 50)
			frctl->max_iter = frctl->max_iter * 0.95;
		else if (frctl->max_iter > 1)
			frctl->max_iter -= 1;
	}
	set_color_array(frctl);
}

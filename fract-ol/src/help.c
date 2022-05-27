/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:12:38 by fcil              #+#    #+#             */
/*   Updated: 2022/05/27 19:55:59 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_input(int argc, char *argv[], t_fractol *frctl)
{
	frctl->fractal_func = NULL;
	if (argc == 2 && !ft_strncmp(argv[1], "julia", 6))
	{
		frctl->fractal_func = julia;
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		frctl->fractal_func = mandelbrot;
	else if (argc == 2 && !ft_strncmp(argv[1], "multibrot_set", 9))
		frctl->fractal_func = multibrot_set;
	else
	{
		printf("Unfortunately your input is not valid.\n");
		printf("Please use one of the following parameters: ");
		printf("[mandelbrot, julia, multibrot_set]\n");
		printf("Sample usage: ./fractol mandelbrot\n");
	}
	if (frctl->fractal_func == NULL)
		fractol_free_kill_all(frctl);
}

void	complex_set(t_complex *z, double re, double im)
{
	z->re = re;
	z->im = im;
}

int	fractol_free_kill_all(t_fractol *frctl)
{
	if (frctl->mlx != NULL)
	{
		mlx_destroy_window(frctl->mlx->ptr, frctl->mlx->win);
		mlx_destroy_image(frctl->mlx->ptr, frctl->mlx->img.ptr);
		free(frctl->mlx);
	}
	free(frctl->color_scheme);
	free(frctl);
	exit(EXIT_SUCCESS);
}

void	my_mlx_pixel_put(t_mlximg *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

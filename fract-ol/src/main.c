/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:53:06 by fcil              #+#    #+#             */
/*   Updated: 2022/05/27 16:45:20 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//eğer eşitse tam ortaya almak için 2 ye 2 veriyoruz.
//değilse oranı hesaplayıp yine fractolu ortaya alıyoruz.
//julia fractolü için başlangıç değerlerini veriyoruz.
int	set_defaults(t_fractol *frctl)
{
	frctl->max_iter = 25;
	frctl->is_fixed = true;
	if (SIZE_X == SIZE_Y)
	{
		complex_set(&frctl->c_max, 2, 2);
		complex_set(&frctl->c_min, -2, -2);
	}
	else
	{
		complex_set(&frctl->c_min, -2, -2);
		frctl->c_max.im = 2;
		frctl->c_max.re = (SIZE_X / SIZE_Y
				* (frctl->c_max.im - frctl->c_min.im)
				+ frctl->c_min.re);
	}
	complex_set(&frctl->c_julia, -0.4, 0.6);
	set_color_array(frctl);
	return (0);
}

t_fractol	*frctl_init(int argc, char *argv[])
{
	t_fractol	*frctl;

	frctl = malloc(sizeof(t_fractol));
	if (frctl == NULL)
		return (NULL);
	frctl->color_scheme = malloc((MAX_ITER + 1) * sizeof(int));
	if (frctl->color_scheme == NULL)
		fractol_free_kill_all(frctl);
	frctl->mlx = NULL;
	frctl->color_shift = 0;
	set_defaults(frctl);
	set_input(argc, argv, frctl);
	return (frctl);
}

//zoom a dayalı olarak real ve imaginary sayıları buluyoruz.
//her piksele fractal fonksiyonunu uyguluyoruz.
//oluşturduğumuz img ye pixellerimizi yazıyoruz.
int	fractol_loop(t_fractol *frctl)
{
	size_t	x;
	size_t	y;

	frctl->scale.re = (frctl->c_max.re - frctl->c_min.re) / SIZE_X;
	frctl->scale.im = (frctl->c_max.im - frctl->c_min.im) / SIZE_Y;
	y = 0;
	while (y < SIZE_Y)
	{
		frctl->c.im = frctl->c_max.im - y * frctl->scale.im;
		x = 0;
		while (x < SIZE_X)
		{
			frctl->c.re = frctl->c_min.re + x * frctl->scale.re;
			frctl->fractal_func(frctl);
			my_mlx_pixel_put(&frctl->mlx->img, x, y, get_color(frctl));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frctl->mlx->ptr, frctl->mlx->win,
		frctl->mlx->img.ptr, 0, 0);
	return (0);
}

void	setup_mlx(t_fractol *frctl)
{
	t_mlx	*mlx;

	frctl->mlx = malloc(sizeof(t_mlx));
	if (frctl->mlx == NULL)
		fractol_free_kill_all(frctl);
	mlx = frctl->mlx;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		fractol_free_kill_all(frctl);
	mlx->win = mlx_new_window(mlx->ptr, SIZE_X, SIZE_Y, "fractol");
	if (mlx->win == NULL)
		fractol_free_kill_all(frctl);
	mlx->img.ptr = mlx_new_image(mlx->ptr, SIZE_X, SIZE_Y);
	if (mlx->img.ptr == NULL)
		fractol_free_kill_all(frctl);
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	if (mlx->img.addr == NULL)
		fractol_free_kill_all(frctl);
	mlx_hook(mlx->win, 2, 0, key_actions, frctl);
	mlx_hook(mlx->win, 4, 0, zoom, frctl);
	mlx_hook(mlx->win, 17, 0, fractol_free_kill_all, frctl);
	mlx_hook(mlx->win, 6, 0, julia_mouse_motion, frctl);
}

int	main(int argc, char *argv[])
{
	t_fractol	*frctl;

	frctl = frctl_init(argc, argv);
	if (frctl == NULL)
		return (-1);
	setup_mlx(frctl);
	fractol_loop(frctl);
	mlx_loop(frctl->mlx->ptr);
	return (0);
}

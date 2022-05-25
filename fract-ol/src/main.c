/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:53:06 by fcil              #+#    #+#             */
/*   Updated: 2022/05/25 17:26:27 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	die(char *str)
{
	ft_putstr_fd(str ,2);
	return (1);
}
int	ft_free_exit(t_env *env)
{
	// mlx_destroy_image(env->mlx, env->img->addr);
	// mlx_destroy_window(env->mlx, env->win);
	// mlx_destroy_display(env->mlx);
	// free(env->img);
	// free(env->mlx);
	exit (0);
	return (1);
}

int	ft_keypress(int keycode, t_env *env)
{
	if (keycode == K_ESC)
		ft_free_exit(env);
	else
		printf("Unkown input, keycode = %d\n", keycode);
	return (0);
}

void	ft_init_env(t_env *env)
{
	env->img = malloc(sizeof(t_img));
	if (!env->img)
		exit(1);
	env->mlx = mlx_init();
	env->img->addr = mlx_new_image(env->mlx, env->size_x, env->size_y);
	env->img->buffer = mlx_get_data_addr(env->img->addr, &env->img->bpp,
			&env->img->line_size, &env->img->endian);
	env->win = mlx_new_window(env->mlx, env->size_x, env->size_y, "fract-ol");
	mlx_hook(env->win, 2, 1L << 0, ft_keypress, env);
	//mlx_hook(env->win, 4, 1L << 2, ft_zoom, env);
	// mlx_hook(env->win, 15, 1L << 16, ft_minimize, env);
	// mlx_hook(env->win, 33, 1L << 5, ft_free_exit, env);
}
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
t_complex	ft_init_complex(double real, double imaginary)
{
	t_complex	c;

	c.r = real;
	c.i = imaginary;
	return (c);
}
int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		return (die("error: not enough arguments"));

	env.size_x = SIZE_X;
	env.size_y = SIZE_Y;
	env.ite = MAX_ITERATION;
	env.min = ft_init_complex(MIN_R, MIN_I);
	env.max = ft_init_complex(MAX_R,
	MIN_I + (MAX_R - MIN_R) * env.size_x / env.size_y);
	env.k = ft_init_complex(-0.4, 0.6);

	ft_init_env(&env);
	mlx_loop(env.mlx);

	return (0);
}

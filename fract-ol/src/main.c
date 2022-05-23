/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:53:06 by fcil              #+#    #+#             */
/*   Updated: 2022/05/23 13:15:10 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_no_param(void)
{
	ft_putstr_fd("- No parameter entered", 2);
	return (1);
}

int	main(int argc, char **argv)
{
	// t_env	env;

	// if (argc == 1)
	// 	return (ft_no_param());
	// ft_putstr_fd("asdf", 1);


	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);

	return (0);
}

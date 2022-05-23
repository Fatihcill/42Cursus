/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:12:38 by fcil              #+#    #+#             */
/*   Updated: 2022/05/23 13:13:09 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_arg_fractal(t_env *env, char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	env->type = 0;
	if (!ft_strncmp(av[1], "J", len) || !ft_strncmp(av[1], "Julia", len))
		env->type = T_JULIA;
	else if (!ft_strncmp(av[1], "M", len)
		|| !ft_strncmp(av[1], "Mandelbrot", len))
		env->type = T_MANDEL;
	else if (!ft_strncmp(av[1], "MA", len)
		|| !ft_strncmp(av[1], "MA_set", len))
		env->type = T_MA_SET;
	else if (!ft_strncmp(av[1], "MB", len)
		|| !ft_strncmp(av[1], "Mandelbar", len))
		env->type = T_MB;
	else if (!ft_strncmp(av[1], "BS", len)
		|| !ft_strncmp(av[1], "Burning_Ship", len))
		env->type = T_BS;
	else if (!ft_strncmp(av[1], "JS", len)
		|| !ft_strncmp(av[1], "Julia_S", len))
		env->type = T_JS;
	else
		return (FALSE);
	return (TRUE);
}

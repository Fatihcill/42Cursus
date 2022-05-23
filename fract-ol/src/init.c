/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:16:18 by fcil              #+#    #+#             */
/*   Updated: 2022/05/23 13:19:30 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_initcomplex(double real, double imaginary)
{
	t_complex	c;

	c.r = real;
	c.i = imaginary;
	return (c);
}

void	ft_init_env(t_env *env)
{

}
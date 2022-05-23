/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:45:48 by fcil              #+#    #+#             */
/*   Updated: 2022/05/23 12:35:49 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "ft_printf.h"

//todo R VE İ TANIMLANACAK
typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

//todo BAKILACAK
typedef struct s_img
{
	void		*addr;
	char		*buffer;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

//todo Ana struct yapısı özet açıklama
typedef struct s_env
{
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	int			type;
	long		ite;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	t_img		*img;
}				t_env;

//renk tanımı yapıldı rgb
typedef struct s_color
{
	double		r;
	double		g;
	double		b;
	int			shadow;
}				t_color;

void	terminate(char *str);

# endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:45:48 by fcil              #+#    #+#             */
/*   Updated: 2022/05/23 13:18:41 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "libft.h"

# define TRUE 1
# define FALSE 0
# define T_JULIA	1
# define T_MANDEL	2
# define T_MA_SET	3
# define T_MB		4
# define T_BS		5
# define T_JS		6

//r -> real
//i -> imaginary
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
//todo SHADOW ne için ?
typedef struct s_color
{
	double		r;
	double		g;
	double		b;
	int			shadow;
}				t_color;

int			ft_no_param(void);

#endif

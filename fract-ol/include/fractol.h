/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:45:48 by fcil              #+#    #+#             */
/*   Updated: 2022/05/27 19:55:59 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include "mlx.h"
# include "libft.h"
# include "keypress.h"

# define SIZE_X 1000.0
# define SIZE_Y 1000.0
# define MAX_ITER 5000

typedef struct s_fractol	t_fractol;
typedef void				(*t_funcptr)(t_fractol *frctl);

typedef struct s_complex{
	double	re;
	double	im;
}	t_complex;

typedef struct s_mlximg {
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlximg;

typedef struct s_mlx {
	void		*ptr;
	void		*win;
	t_mlximg	img;
}	t_mlx;

typedef struct s_fractol {
	t_mlx		*mlx;
	t_complex	c;
	t_complex	c_julia;
	t_complex	c_max;
	t_complex	c_min;
	t_complex	scale;
	size_t		iter;
	size_t		max_iter;
	t_funcptr	fractal_func;
	uint8_t		color_shift;
	int			*color_scheme;
	bool		is_fixed;
}	t_fractol;

int			fractol(int argc, char *argv[]);
int			fractol_loop(t_fractol *frctl);

t_fractol	*frctl_init(int argc, char *argv[]);
void		set_input(int argc, char *argv[], t_fractol *frctl);
void		setup_mlx(t_fractol *frctl);
int			set_defaults(t_fractol *frctl);
int			fractol_free_kill_all(t_fractol *frctl);

void		mandelbrot(t_fractol *frctl);
void		julia(t_fractol *frctl);
void		multibrot_set(t_fractol *frctl);

int			get_color(t_fractol *frctl);
void		set_color_array(t_fractol *frctl);

int			zoom(int button, int x, int y, t_fractol *frctl);
int			julia_mouse_motion(int x, int y, t_fractol *frctl);

int			key_actions(int key, t_fractol *frctl);
void		move(int key, t_fractol *frctl);
void		fractal_change(int key, t_fractol *frctl);
void		color_shift(t_fractol *frctl);
void		change_maxiter(int key, t_fractol *frctl);

void		complex_set(t_complex *z, double re, double im);
void		my_mlx_pixel_put(t_mlximg *img, int x, int y, int color);
void		print_help(void);

#endif

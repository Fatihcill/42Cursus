/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:45:48 by fcil              #+#    #+#             */
/*   Updated: 2022/04/14 16:50:02 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_node
{
	int				z;
	struct s_node	*nxt;
}				t_node;

typedef struct s_map
{
	int				width;
	int				height;
	int				*arr_z;
	int				z_min;
	int				z_max;
}				t_map;


void	terminate(char *str);

# endif
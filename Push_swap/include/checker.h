/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:13:25 by fcil              #+#    #+#             */
/*   Updated: 2022/04/22 10:24:02 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_printf.h"
# include "pushswap.h"

typedef struct		s_flags
{
	int				verbose;
	int				colors;
	int				counter;
	int				count;
	int				error;
	int				index;
	int				repeat;
}					t_flags;

#endif /* CHECKER_H */
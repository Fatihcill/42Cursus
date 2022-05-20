/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmoves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:57:05 by fcil              #+#    #+#             */
/*   Updated: 2022/05/20 14:43:14 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stackmoves_setup(t_stack *a, t_stack *b, t_seq *seq)
{
	sx(SETUP, a, b, seq);
	px(SETUP, a, b, seq);
	rx(SETUP, a, b, seq);
	rrx(SETUP, a, b, seq);
}

void	n_pa(int n)
{
	while (n-- > 0)
		pa();
}

void	n_pb(int n)
{
	while (n-- > 0)
		pb();
}

void	n_rrb(int n)
{
	while (n-- > 0)
		rrb();
}

void	n_rra(int n)
{
	while (n-- > 0)
		rra();
}

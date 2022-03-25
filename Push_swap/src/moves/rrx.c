/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:45:18 by fcil              #+#    #+#             */
/*   Updated: 2022/03/25 12:26:49 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_reverse_rotate(t_stack *stack)
{
	if (NULL == stack || 1 >= stack->len)
		return ;
	stack->first = stack->first->prev;
}

void	rrx(int flag, t_stack *a, t_stack *b, t_seq *seq)
{
	static t_stack	*aptr;
	static t_stack	*bptr;
	static t_seq	*seqptr;

	if (SETUP & flag)
	{
		aptr = a;
		bptr = b;
		seqptr = seq;
		return ;
	}
	if (FLAG_A & flag)
		stack_reverse_rotate(aptr);
	if (FLAG_B & flag)
		stack_reverse_rotate(bptr);
	if ((FLAG_B & flag) && (FLAG_A & flag))
		seq_add(seqptr, RRR);
	else if (FLAG_A & flag)
		seq_add(seqptr, RRA);
	else if (FLAG_B & flag)
		seq_add(seqptr, RRB);
}

void	rra(void)
{
	rrx(FLAG_A, NULL, NULL, NULL);
}

void	rrb(void)
{
	rrx(FLAG_B, NULL, NULL, NULL);
}

void	rrr(void)
{
	rrx(FLAG_A | FLAG_B, NULL, NULL, NULL);
}

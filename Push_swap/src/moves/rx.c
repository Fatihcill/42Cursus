/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:43:23 by fcil              #+#    #+#             */
/*   Updated: 2022/03/25 12:25:53 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_rotate(t_stack *stack)
{
	if (NULL == stack || 1 >= stack->len)
		return ;
	stack->first = stack->first->next;
}

void	rx(int flag, t_stack *a, t_stack *b, t_seq *seq)
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
		stack_rotate(aptr);
	if (FLAG_B & flag)
		stack_rotate(bptr);
	if ((FLAG_B & flag) && (FLAG_A & flag))
		seq_add(seqptr, RR);
	else if (FLAG_A & flag)
		seq_add(seqptr, RA);
	else if (FLAG_B & flag)
		seq_add(seqptr, RB);
}

void	ra(void)
{
	rx(FLAG_A, NULL, NULL, NULL);
}

void	rb(void)
{
	rx(FLAG_B, NULL, NULL, NULL);
}

void	rr(void)
{
	rx(FLAG_A | FLAG_B, NULL, NULL, NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:38:43 by fcil              #+#    #+#             */
/*   Updated: 2022/03/25 12:25:27 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_swap(t_stack *stack)
{
	if (NULL == stack || 1 >= stack->len)
		return ;
	if (2 == stack->len)
	{
		stack->first = stack->first->next;
		return ;
	}
	stack->first->prev->next = stack->first->next;
	stack->first->next->prev = stack->first->prev;
	stack->first->prev = stack->first->next;
	stack->first->next = stack->first->next->next;
	stack->first->next->prev = stack->first;
	stack->first->prev->next = stack->first;
	stack->first = stack->first->prev;
}

void	sx(int flag, t_stack *a, t_stack *b, t_seq *seq)
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
		stack_swap(aptr);
	if (FLAG_B & flag)
		stack_swap(bptr);
	if ((FLAG_B & flag) && (FLAG_A & flag))
		seq_add(seqptr, SS);
	else if (FLAG_A & flag)
		seq_add(seqptr, SA);
	else if (FLAG_B & flag)
		seq_add(seqptr, SB);
}

void	sa(void)
{
	sx(FLAG_A, NULL, NULL, NULL);
}

void	sb(void)
{
	sx(FLAG_B, NULL, NULL, NULL);
}

void	ss(void)
{
	sx(FLAG_A | FLAG_B, NULL, NULL, NULL);
}

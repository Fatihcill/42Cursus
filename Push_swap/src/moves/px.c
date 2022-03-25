/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:41:49 by fcil              #+#    #+#             */
/*   Updated: 2022/03/24 13:10:37 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*stack_remove(t_stack *stack)
{
	t_node		*node;

	if (NULL == stack || 0 >= stack->len)
		return (NULL);
	node = stack->first;
	if (1 == stack->len)
	{
		stack->len = 0;
		stack->first = NULL;
		return (node);
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	stack->first = node->next;
	stack->len -= 1;
	return (node);
}

void	px(int flag, t_stack *a, t_stack *b, t_seq *seq)
{
	static t_stack	*aptr;
	static t_stack	*bptr;
	static t_seq	*seqptr;

	if (SETUP & flag)
	{
		aptr = a;
		bptr = b;
		seqptr = seq;
	}
	else if (FLAG_A & flag)
	{
		stack_add_first(aptr, stack_remove(bptr));
		seq_add(seqptr, PA);
	}
	else
	{
		stack_add_first(bptr, stack_remove(aptr));
		seq_add(seqptr, PB);
	}
}

void	pa(void)
{
	px(FLAG_A, NULL, NULL, NULL);
}

void	pb(void)
{
	px(FLAG_B, NULL, NULL, NULL);
}

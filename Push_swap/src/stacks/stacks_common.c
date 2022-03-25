/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:05:34 by fcil              #+#    #+#             */
/*   Updated: 2022/03/24 13:29:02 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*stack_init(t_stack *stack, t_node *node)
{
	stack->first = node;
	node->next = node;
	node->prev = node;
	stack->len = 1;
	return (node);
}

t_node	*stack_add_end(t_stack *stack, t_node *node)
{
	if (NULL == stack || NULL == node || 0 > stack->len)
		return (NULL);
	if (0 == stack->len)
		return (stack_init(stack, node));
	if (1 == stack->len)
	{
		stack->first->next = node;
		stack->first->prev = node;
		node->next = stack->first;
		node->prev = stack->first;
	}
	else
	{
		node->prev = stack->first->prev;
		node->prev->next = node;
		node->next = stack->first;
		stack->first->prev = node;
	}
	stack->len += 1;
	return (node);
}

t_node	*stack_add_first(t_stack *stack, t_node *node)
{
	t_node		*ret;

	ret = stack_add_end(stack, node);
	if (NULL == ret)
		return (NULL);
	stack->first = ret;
	return (ret);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*current;
	int		pos;

	if (NULL == stack || 1 >= stack->len)
		return (1);
	pos = 1;
	current = stack->first;
	while (pos < stack->len)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		pos += 1;
	}
	return (1);
}

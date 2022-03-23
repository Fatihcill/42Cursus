/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:23:21 by fcil              #+#    #+#             */
/*   Updated: 2022/03/23 02:10:38 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_node	*new_node(int value)
{
	t_node	*new;

	if (NULL == (new = malloc(sizeof(t_node))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->value = value;
	new->rank = -1;
	return (new);
}

static t_node			*stack_add_end(t_stack *stack, t_node *node)
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

static t_node			*stack_add_first(t_stack *stack, t_node *node)
{
	t_node		*ret;

	ret = stack_add_end(stack, node);
	if (NULL == ret)
		return (NULL);
	stack->first = ret;
	return (ret);
}

static int	push_all_nodes(t_stack *stack, t_iarray *iarr)
{
	while (iarr->size > 0)
	{
		iarr->size -= 1;
		if (NULL == stack_add_first(stack,
					new_node(iarr->array[iarr->size])))
		{
			stack_free(stack);
			iarr_free(iarr);
			return (1);
		}
	}
	return (0);
}

int			build_stack(t_stack *stack, int *arr, int len)
{
	int		*sorted_arr;

	sorted_arr = arr_checkdoubles(arr, len);
	if (!sorted_arr || !stack || !arr)
		return NULL;
	
	stack->len = 0;
	stack->first = NULL;
	if (/* condition */)
	{
		/* code */
	}
	
}
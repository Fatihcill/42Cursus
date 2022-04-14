/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:23:21 by fcil              #+#    #+#             */
/*   Updated: 2022/03/28 12:07:49 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_free(t_stack *stack)
{
	t_node	*tmp;

	if (NULL == stack || 0 >= stack->len)
		return ;
	while (stack->len > 0)
	{
		tmp = stack->first;
		stack->first = stack->first->next;
		free(tmp);
		stack->len -= 1;
	}
	stack->first = NULL;
}

static t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->value = value;
	new->rank = -1;
	return (new);
}

static int	push_all_nodes(t_stack *stack, int *arr, int len)
{
	while (len > 0)
	{
		len -= 1;
		if (!stack_add_first(stack, new_node(arr[len])))
		{
			stack_free(stack);
			return (1);
		}
	}
	return (0);
}

static void	add_ranks_to_nodes(t_stack *stack, int *sorted, int len)
{
	t_node		*current;
	int			pos;
	int			rank;

	pos = 0;
	current = stack->first;
	while (pos < stack->len)
	{
		rank = -1;
		while (++rank < len)
		{
			if (sorted[rank] == current->value)
			{
				current->rank = rank;
				break ;
			}
		}	
		current = current->next;
		pos += 1;
	}
}

int	build_stack(t_stack *stack, int *arr, int len)
{
	int		*sorted_arr;

	sorted_arr = arr_checkdoubles(arr, len);
	if (!sorted_arr || !stack || !arr)
	{
		return (0);
	}
	stack->len = 0;
	stack->first = NULL;
	if (push_all_nodes(stack, arr, len))
		return (0);
	add_ranks_to_nodes(stack, sorted_arr, len);
	free(sorted_arr);
	return (stack->len);
}

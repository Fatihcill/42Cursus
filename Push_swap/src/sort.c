/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:16:48 by fcil              #+#    #+#             */
/*   Updated: 2022/04/05 12:07:29 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	case2(t_stack *a)
{
	if (a->first->rank > a->first->next->rank)
	{
		sa();
	}
}

void	case3(t_stack *a)
{
	if (a->first->rank > a->first->next->rank)
	{
		if (a->first->prev->rank > a->first->rank)
			sa();
		else if (a->first->prev->rank > a->first->next->rank)
			ra();
		else
		{
			ra();
			sa();
		}
	}
	else
	{
		if (a->first->prev->rank < a->first->rank)
			rra();
		else if (a->first->prev->rank > a->first->next->rank)
			return ;
		else
		{
			rra();
			sa();
		}
	}	
}

int	stacks_sort(t_stack *a, t_stack *b)
{
	if (is_stack_sorted(a) || a->len <= 1)
		return (0);
	else if (a->len == 2)
		case2(a);
	else if (a->len == 3)
		case3(a);
	else
		mysort(a, b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:16:48 by fcil              #+#    #+#             */
/*   Updated: 2022/03/24 13:39:35 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	case2_r(t_stack *a)
{
	if (a->first->rank < a->first->next->rank)
	{
		sa();
	}
}

void	case3_r(t_stack *a)
{
	if (a->first->rank > a->first->next->rank)
	{
		if (a->first->prev->rank > a->first->rank)
			rra();
		else if (a->first->prev->rank > a->first->next->rank)
		{
			rra();
			sa();
		}
	}
	else
	{
		if (a->first->prev->rank < a->first->rank)
			sa();
		else if (a->first->prev->rank > a->first->next->rank)
		{
			ra();
			sa();
		}
		else
			ra();
	}
}

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

int	stacks_sort(t_stack *a, t_stack *b, t_seq *seq)
{
	if (is_stack_sorted(a) || a->len <= 1)
		return (0);
	else if (a->len == 2)
		case2(a);
	else if (a->len == 3)
		case3(a);
	return (0);
}

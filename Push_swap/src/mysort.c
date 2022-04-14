/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:52:53 by fcil              #+#    #+#             */
/*   Updated: 2022/04/05 12:40:47 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


static t_stack*	max_sorted_seq(t_stack *a)
{
	t_stack aligned_st;
	int	first_index;

	aligned_st = ft_memcpy(&aligned_st, a, sizeof(a));	
	while (aligned_st->first->rank != 0)
		aligned_st->first = aligned_st->first->next;
	return aligned_st;
}

void	mysort(t_stack *a, t_stack *b)
{
	t_stack *sorted_seq = max_sorted_seq(a);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:08:32 by fcil              #+#    #+#             */
/*   Updated: 2022/03/27 14:25:56 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	quick_sort(t_stack *a, t_stack *b)
{
	t_quick	info;

	info.blen = 0;
	info.alen = a->len;
	info.minrank = 0;
	info.maxrank = a->len - 1;
	info.topush = a->len / 2;
	info.mid = info.minrank + info.topush;
	info.pushed = 0;
	info.isthisa = 1;
	info.reclvl = 0;
	info.offset = 0;
	while (info.pushed < info.topush)
	{
		if (a->first->rank < info.mid)
		{
			pb();
			info.pushed += 1;
		}
		else
			ra();
	}
	quick_sort_a_ascending(a, b, &info);
	quick_sort_b_descending(a, b, &info);
	n_pa(info.pushed);
}

static void	calculate_info_a(t_quick *info, t_quick *data)
{
	info->reclvl = data->reclvl + 1;
	if (data->isthisa)
	{
		info->alen = data->alen - data->pushed;
		info->blen = 0;
		info->minrank = data->minrank + data->pushed;
		info->maxrank = data->maxrank;
		info->topush = info->alen / 2;
		info->pushed = 0;
		info->mid = info->minrank + info->topush;
		info->isthisa = 1;
	}
	else
	{
		info->alen = data->pushed;
		info->blen = 0;
		info->minrank = data->maxrank - data->pushed + 1;
		info->maxrank = data->maxrank;
		info->topush = info->alen / 2;
		info->pushed = 0;
		info->mid = info->minrank + info->topush;
		info->isthisa = 1;
	}
	info->offset = 0;
}

void	quick_sort_a_ascending(t_stack *a, t_stack *b, t_quick *data)
{
	t_quick	info;

	calculate_info_a(&info, data);
	if (2 == info.alen)
		if (a->first->rank > a->first->next->rank)
			sa();
	if (info.alen <= 2)
		return ;
	while (info.pushed < info.topush)
	{
		if (a->first->rank < info.mid)
		{
			pb();
			info.pushed += 1;
		}
		else
		{
			ra();
			info.offset += 1;
		}
	}
	n_rra(info.offset);
	quick_sort_a_ascending(a, b, &info);
	quick_sort_b_descending(a, b, &info);
	n_pa(info.pushed);
}

static void	calculate_info_b(t_quick *info, t_quick *data)
{
	info->reclvl = data->reclvl + 1;
	if (data->isthisa)
	{
		info->alen = 0;
		info->blen = data->pushed;
		info->minrank = data->minrank;
		info->maxrank = data->minrank + data->pushed - 1;
		info->topush = info->blen / 2;
		info->pushed = 0;
		info->mid = info->maxrank - info->topush;
	}
	else
	{
		info->alen = 0;
		info->blen = data->blen - data->pushed;
		info->minrank = data->minrank;
		info->maxrank = data->maxrank - data->pushed;
		info->topush = info->blen / 2;
		info->pushed = 0;
		info->mid = info->maxrank - info->topush;
	}
	info->isthisa = 0;
	info->offset = 0;
}

void	quick_sort_b_descending(t_stack *a, t_stack *b, t_quick *data)
{
	t_quick	info;

	calculate_info_b(&info, data);
	if (2 == info.blen)
		if (b->first->rank < b->first->next->rank)
			sb();
	if (info.blen <= 2)
		return ;
	while (info.pushed < info.topush)
	{
		if (b->first->rank > info.mid)
		{
			pa();
			info.pushed += 1;
		}
		else
		{
			rb();
			info.offset += 1;
		}
	}
	n_rrb(info.offset);
	quick_sort_a_ascending(a, b, &info);
	quick_sort_b_descending(a, b, &info);
	n_pb(info.pushed);
}

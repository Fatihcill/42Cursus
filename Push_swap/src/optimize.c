/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:50:39 by fcil              #+#    #+#             */
/*   Updated: 2022/03/27 16:31:47 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	should_be_removed(t_instruction *x, t_instruction *y)
{
	return ((x->move == PA && PB == y->move)
		|| (x->move == PB && PA == y->move)
		|| (x->move == RA && RRA == y->move)
		|| (x->move == RB && RRB == y->move)
		|| (x->move == RRA && RA == y->move)
		|| (x->move == RRB && RB == y->move));
}

static t_instruction	*find_next(t_seq *seq,
		t_instruction *cur,
		t_instruction *tmp)
{
	if (cur->next == NULL)
		return (NULL);
	cur->next->next = find_next(seq, cur->next, NULL);
	if (cur->next != NULL && cur->next->next != NULL
		&& should_be_removed(cur->next, cur->next->next))
	{
		tmp = cur->next->next->next;
		free(cur->next->next);
		free(cur->next);
		seq->len -= 2;
		cur->next = tmp;
	}
	return (cur->next);
}

void	seq_optimize(t_seq *seq)
{
	if (seq->len <= 3)
		return ;
	seq->first->next = find_next(seq, seq->first, NULL);
}

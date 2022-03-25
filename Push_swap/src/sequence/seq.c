/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:49:58 by fcil              #+#    #+#             */
/*   Updated: 2022/03/25 12:28:29 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_instruction	*new_instruction(t_move move)
{
	t_instruction	*ret;

	ret = malloc(sizeof(t_instruction));
	if (!ret)
		return (NULL);
	ret->move = move;
	ret->next = NULL;
	return (ret);
}

void	seq_add(t_seq *seq, t_move move)
{
	t_instruction	*ins;

	ins = new_instruction(move);
	if (seq->len < 0 || !ins)
	{
		seq->len = -1;
		return ;
	}
	if (0 == seq->len)
		seq->first = ins;
	else
		seq->last->next = ins;
	seq->last = ins;
	seq->len += 1;
}

void	print_move(t_move move)
{
	if (PA == move)
		write(1, "pa\n", 3);
	else if (PB == move)
		write(1, "pb\n", 3);
	else if (SA == move)
		write(1, "sa\n", 3);
	else if (SB == move)
		write(1, "sb\n", 3);
	else if (SS == move)
		write(1, "ss\n", 3);
	else if (RA == move)
		write(1, "ra\n", 3);
	else if (RB == move)
		write(1, "rb\n", 3);
	else if (RR == move)
		write(1, "rr\n", 3);
	else if (RRA == move)
		write(1, "rra\n", 4);
	else if (RRB == move)
		write(1, "rrb\n", 4);
	else if (RRR == move)
		write(1, "rrr\n", 4);
}

void	seq_print(t_seq *seq)
{
	t_instruction	*current;

	if (0 >= seq->len)
		return ;
	current = seq->first;
	while (NULL != current->next)
	{
		print_move(current->move);
		current = current->next;
	}
	print_move(current->move);
}

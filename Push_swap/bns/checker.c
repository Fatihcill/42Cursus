/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:08:25 by fcil              #+#    #+#             */
/*   Updated: 2022/04/22 10:27:47 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			chk_init_flags(t_flags *flags)
{
	flags->verbose = 0;
	flags->colors = 0;
	flags->error = 0;
	flags->counter = 0;
	flags->index = 0;
	flags->repeat = 0;
	flags->count = 0;
}

static void	init(t_stack *a, t_stack *b, t_seq *seq)
{
	(void)a;
	seq->len = 0;
	seq->first = NULL;
	b->len = 0;
	b->first = 0;
}

int	main(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	t_flags			flags;
	t_seq			seq;

	if (ac < 2)
	{
		ft_printf("Error!");
		return (0);
	}
	chk_init_flags(&flags);
	init(&a, &b, &seq);
	stackmoves_setup(&a, &b, &seq);

}
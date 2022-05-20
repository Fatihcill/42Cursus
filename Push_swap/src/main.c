/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:40:53 by fcil              #+#    #+#             */
/*   Updated: 2022/05/20 14:57:34 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// static void	ft_print_stack(int len, t_stack s)
// {
// 	t_node	*current;

// 	current = s.first;
// 	ft_printf(" stack len : %d \n", s.len);
// 	while (len > 0)
// 	{
// 		ft_printf("rank : %d  value : %d \n", current->rank, current->value);
// 		current = current->next;
// 		len--;
// 	}
// }
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
	t_stack		a;
	t_stack		b;
	t_seq		seq;
	int			*arr;
	int			len;

	len = ac - 1;
	if (ac < 2)
		return (0);
	arr = params_to_array(&len, av);
	if (check_error(&av[1]) || !build_stack(&a, arr, len))
	{
		ft_putstr_fd("Error\n", 2);
		free(arr);
		return (-1);
	}
	init(&a, &b, &seq);
	stackmoves_setup(&a, &b, &seq);
	stacks_sort(&a, &b);
	seq_optimize(&seq);
	seq_print(&seq);
	stack_free(&a);
	stack_free(&b);
	free(arr);
	return (0);
}

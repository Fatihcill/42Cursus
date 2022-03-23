/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:40:53 by fcil              #+#    #+#             */
/*   Updated: 2022/03/23 00:23:31 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_seq		bestseq;
	int			*arr;


	if (ac < 2)
		return (0);
	arr = params_to_array(ac, av);
	build_stack(&a, arr, ac - 1);
	free(arr);
	// {
	// 	ft_dprintf(2, "Error\n");
	// 	return (-1);
	// }
}
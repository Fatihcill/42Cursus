/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:51:33 by fcil              #+#    #+#             */
/*   Updated: 2022/05/20 14:56:22 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

long	ft_atoiv2(char *str)
{
	int		i;
	int		pn;
	long	res;

	pn = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 12) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pn *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * pn);
}

static int	checkoverflow(char *strnum)
{
	long long	num;

	num = ft_atoiv2(strnum);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}

int	check_error(char **array)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
		{
			c = array[i][j];
			if (ft_isalpha(c) || (c >= 33 && c <= 43) || (c >= 58 && c <= 64))
				return (1);
		}
		if (checkoverflow(array[i]))
			return (1);
	}
	return (0);
}

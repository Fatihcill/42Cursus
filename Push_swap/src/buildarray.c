/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildarray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:52:37 by fcil              #+#    #+#             */
/*   Updated: 2022/05/20 14:48:19 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	partition(int *array, int size)
{
	int		i;
	int		mid;
	int		tmp;

	mid = 0;
	i = 0;
	while (i < size - 1)
	{
		if (array[i] < array[size - 1])
		{
			tmp = array[i];
			array[i] = array[mid];
			array[mid] = tmp;
			mid += 1;
		}
		i += 1;
	}
	tmp = array[mid];
	array[mid] = array[size - 1];
	array[size - 1] = tmp;
	return (mid);
}

static void	quicksort(int *array, int size)
{
	int		mid;

	if (size < 2)
		return ;
	mid = partition(array, size);
	quicksort(array, mid);
	quicksort(array + mid + 1, size - mid - 1);
}

int	*params_to_array(int *len, char **av)
{
	int		*array;
	int		i;
	char	**tmp;

	i = 0;
	if (*len == 1)
	{
		*len = 0;
		tmp = ft_split(*(av + 1), ' ');
		while (tmp[*len])
			*len = *len + 1;
		array = ft_calloc(*len, sizeof(int));
		while (++i <= *len)
			array[i - 1] = ft_atoi(tmp[i - 1]);
	}
	else
	{
		array = ft_calloc(*len, sizeof(int));
		while (++i <= *len)
			array[i - 1] = ft_atoi(av[i]);
	}
	return (array);
}

int	*arr_checkdoubles(int *arr, int len)
{
	int	*clonearr;
	int	i;

	i = -1;
	clonearr = ft_calloc(len, sizeof(int));
	if (!clonearr)
		return (NULL);
	while (++i < len)
		clonearr[i] = arr[i];
	quicksort(clonearr, len);
	i = -1;
	while (++i < len - 1)
	{
		if (clonearr[i] == clonearr[i + 1])
		{
			free(clonearr);
			return (NULL);
		}
	}
	return (clonearr);
}

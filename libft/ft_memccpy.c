/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 04:37:58 by fcil              #+#    #+#             */
/*   Updated: 2022/01/21 17:51:42 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*destc;
	const char	*srcc;
	size_t		i;

	destc = (char *)dest;
	srcc = (const char *)src;
	i = 0;
	while (i < n)
	{
		destc[i] = srcc[i];
		if (srcc[i] == (char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}

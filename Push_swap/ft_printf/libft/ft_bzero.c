/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 04:11:05 by fcil              #+#    #+#             */
/*   Updated: 2022/02/02 11:41:19 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*suc;

	i = 0;
	suc = (char *)s;
	while (i < n)
	{
		suc[i] = 0;
		i++;
	}
	s = suc;
}

// s dizisi n'e kadar 0(NULL) ile doldurur.
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:55:56 by fcil              #+#    #+#             */
/*   Updated: 2022/02/02 16:13:07 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	char			*buc;

	i = 0;
	buc = (char *)s;
	while (i < n)
	{
		buc[i] = c;
		i++;
	}
	s = buc;
	return (s);
}
//s dizisini n'ye kadar c byte'i doldurur 

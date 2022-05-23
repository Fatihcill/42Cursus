/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:18:13 by fcil              #+#    #+#             */
/*   Updated: 2022/02/04 18:40:42 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (dest);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dest);
	}
	while (len--)
		*d++ = *s++;
	return (dest);
}

// int main()
// {
//  char a[] = "fatihcil";
//  printf("%s",ft_memmove((a + 2) , a, 4));
// }
// s nin adresi d den kucuk oldugunda, 
// sondan baslanir overleap sorunu olmamasi icin.
// memcpyden farki budur, 
// oyle bir sorun yoksa da direkt normal sekilde s den d ye byteleri alir.
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:54:45 by fcil              #+#    #+#             */
/*   Updated: 2022/02/03 16:49:35 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	index;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_checkset(s1[start], set))
		start++;
	while (end > start && ft_checkset(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (start < end)
		str[index++] = s1[start++];
	str[index] = '\0';
	return (str);
}
// s1 in basinda ve sonunda set deki karakterler aranir
// eger bulunursa kirpilir ve yeni bir string olusturulur
// o string return edilir
//ft_checkset de karakterde string aranir.
//39 da baslangictaki karakter icin kirpma yapiyoruz
//41 de sondaki karakterler icin kirpma yapiyoruz.
// 43 de kirpmadan sonra kalan byte sayisini hesapliyoruz 
// ve yeni bir str olusturuyoruz.
// 48 de yeni str ye verileri aktiriyoruz.
// ve return ediyoruz.
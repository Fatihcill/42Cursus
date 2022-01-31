/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:57:33 by fcil              #+#    #+#             */
/*   Updated: 2022/01/21 20:23:53 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//kaç adet string dizisi elemanı olduğunu hesaplar. 
//"fatih-fatih-fatih" , '-' cevap 2 dir 2 adet ayırıcı var çünkü
unsigned int	str_in_array(const char *s, char delimiter)
{
	unsigned int	qnt;

	qnt = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			while (*s != delimiter && *s)
				s++;
			qnt++;
		}
	}
	return (qnt);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	j;
	unsigned int	a;

	arr = (char **) ft_calloc(str_in_array(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	a = -1;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (*s != c && *s)
			{
				s++;
				j++;
			}
			arr[++a] = (char *) ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(arr[a], s - j, j + 1);
		}
	}
	return (arr);
}
//53. satırdaki while da ayırıcı varsa geçiyoruz. 
//58. satırda bizim string dizimizin ilk elemanına yer açıyoruz. 
//j değeri bizim stringin uzunluğu fatih mesela 5 lik alan null ile 6
// 59 da arr nin a nıncı değerine s-j diyerek oradan başladığımızı belirterek 
//j kadar yazdırıyoruz. yani fatih cil de ilkte s değeri fatih i bitirir ve
//boslukta durur. sonra j 5 olur. s - 5 diyerek, fatih in f sine geri geliriz.
// j + 1 diyerekte null ile birlikte 6 lık alana bunu yazdırır bknz ft_strlcpy.
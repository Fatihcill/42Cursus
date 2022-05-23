/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:20:33 by fcil              #+#    #+#             */
/*   Updated: 2022/02/02 14:27:55 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//basamak sayısı. negatif ise 1 fazla çünkü uzunluğu buluyoruz.
int	get_len(int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr <= 0)
		nbr_len++;
	while (nbr)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;

	digit = get_len(n);
	str = (char *) ft_calloc(digit + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		*str = '0';
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_strlcpy(str, "-2147483648", digit + 1);
			return (str);
		}
		str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		*(str + --digit) = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
//int to string
// 36 da uzunlugu buluyoruz
// 37 de str mizi olusturuyoruz.
// 44 minimum intse problem olmamasi icin manuel sekilde return ediyoruz.
// 54 de basamak basamak str ye charlari ekliyoruz.
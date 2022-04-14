/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:06:06 by fcil              #+#    #+#             */
/*   Updated: 2022/02/21 10:23:48 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	checkid(va_list arg, const char format)
{
	int	len;

	len = 0;
	if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(arg, int));
	else if (format == 'c')
		len += ft_printchar(va_arg(arg, int));
	else if (format == 's')
		len += ft_printstr(va_arg(arg, char *));
	else if (format == '%')
		len += ft_printchar('%');
	else if (format == 'p')
		len += ft_print_ptr(va_arg(arg, unsigned long));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(arg, unsigned int), format);
	return (len);
}

//printf
int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += checkid(arg, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int				a;
// 	int				b;
// 	int				c;
// 	char			*d;
// 	unsigned int	ui;
// 	ui = 4294967295;
// 	a = 50;
// 	b = 44444;
// 	c = 'd';
// 	d = "OMG";
// 	printf("\n%d\n", ft_printf("yey %d WOW %d %c %s %% 
//|||| %i %p || %u", a, b, c, d, a, &a, ui));
// 	printf("\n%d\n", ft_printf("yey %d WOW %d %c %s %% 
//|||| %i %p || %u", a, b, c, d, a, &a, ui));
// }
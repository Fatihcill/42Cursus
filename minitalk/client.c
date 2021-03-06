/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:03:25 by fcil              #+#    #+#             */
/*   Updated: 2022/07/05 12:40:22 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	setup_binary_string(char *str, char **bits)
{
	int		binarysize;
	int		i;
	int		j;
	char	c;

	binarysize = ft_strlen(str) * 8;
	*bits = ft_calloc(binarysize, sizeof(char));
	j = ft_strlen(str);
	while (str[--j])
	{
		c = str[j];
		i = -1;
		while (++i < 8)
		{
			binarysize--;
			if (c & (1 << i))
				bits[0][binarysize] = '1';
			else
				bits[0][binarysize] = '0';
		}
	}
}

void	send_bits(char *bits, int pid)
{
	while (*bits)
	{
		if (*bits == '0')
		{
			if (kill(pid, SIGUSR1) == -1)
				return ;
		}
		else if (*bits == '1')
		{
			if (kill(pid, SIGUSR2) == -1)
				return ;
		}
		else
			return ;
		bits++;
		usleep(WAIT_TIME);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*bits;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	setup_binary_string(argv[2], &bits);
	ft_putstr_fd(bits, 1);
	ft_putchar_fd('\n', 1);
	send_bits(bits, pid);
	free(bits);
	return (0);
}

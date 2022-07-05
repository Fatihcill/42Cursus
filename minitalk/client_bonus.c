/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:03:25 by fcil              #+#    #+#             */
/*   Updated: 2022/07/05 13:04:47 by fcil             ###   ########.fr       */
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

void	action(int signal, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signal == SIGUSR1)
		ft_putstr_fd("Signal Received", 1);
	else if (signal == SIGUSR2)
		ft_putstr_fd("Error: failed to send signal", 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*bits;
	struct sigaction	act;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = action;
	setup_binary_string(argv[2], &bits);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_putstr_fd(bits, 1);
	ft_putchar_fd('\n', 1);
	send_bits(bits, pid);
	free(bits);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:03:25 by fcil              #+#    #+#             */
/*   Updated: 2022/03/09 14:35:53 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** static void	ft_send_next_char_bit_by_bit(char c, int pid)
** This function will take a char c as an argument and send its binary values
** one bit at a time to the process identified by pid argument (our server).
** We will use SIGUSR2 (=31) to send "1" and SIGUSR1 (=30) to send "0".
** The line "if (c & 0x01)" compares the current bit to 1
** The line "c = c >> 1" moves on to the next bit in c.
*/

static void	ft_send_next_char_bit_by_bit(unsigned char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(WAIT_TIME);
	}
}

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
			kill(pid, SIGUSR1);
		}
		else if (*bits == '1')
		{
			kill(pid, SIGUSR2);
		}
		else
			return ;
		bits++;
		usleep(WAIT_TIME);
	}
}
void	reverse_string(char **string)
{
	int	end;
	int	start;
	char t;

	start = 0;
	end = ft_strlen(string[0]) - 1;
	while (start >= end)
	{
		t = string[0][start];
		string[0][start] = string[0][end];
		string[0][end] = t;
		start++;
		end--;
	}

}

int	main(int argc, char **argv)
{
	int		pid;
	int		len;
	int		i;
	char	*bits;

	if (argc != 3)
		return (-1);
	i = -1;
	while (argv[1][++i])
		if (!ft_strchr("0123456789", argv[1][i]))
			return (-1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	len = ft_strlen(argv[2]);
	setup_binary_string(argv[2], &bits);
	ft_putstr_fd(bits, 1);
	// reverse_string(&bits);
	// ft_putchar_fd('\n', 1);
	// ft_putstr_fd(bits, 1);
	send_bits(bits, pid);
	//ft_send_next_char_bit_by_bit(argv[2][0], pid);
	free(bits);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 03:20:54 by fcil              #+#    #+#             */
/*   Updated: 2022/06/14 12:42:42 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_threads(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->number_of_philo)
		pthread_detach(env->philos[i].th_id);
}

void	destroy_mutexes(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->number_of_philo)
		pthread_mutex_destroy(&env->chopsticks[i]);
}

uint64_t	get_time_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int	ft_atoi(char *s)
{
	int	res;
	int	sing;
	int	i;
	int	j;

	res = 0;
	sing = 1;
	i = 0;
	j = -1;
	while (s[++j])
		if (s[j] < '0' || s[j] > '9')
			exit(-1);
	while (s[i] <= 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sing = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - 48);
	return (res * sing);
}

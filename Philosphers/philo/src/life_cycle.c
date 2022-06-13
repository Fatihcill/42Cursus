/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:29:11 by fcil              #+#    #+#             */
/*   Updated: 2022/06/13 14:38:15 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_cycle_checker(void *arg)
{
	int			i;
	uint64_t	timestamp;
	t_env		*env;

	env = (t_env *)arg;
	i = 0;
	while (1)
	{
		if (env->count_done == env->number_of_philo)
			break ;
		if (i == env->number_of_philo)
			i = 0;
		usleep(1000);
		timestamp = get_time_ms();
		if (!env->philos[i].done
			&& ((int)(timestamp - env->philos[i].last_eat) > env->time_to_die))
		{
			printf("%llu %d %s\n", timestamp, env->philos[i].id, "died");
			env->is_running = false;
			break ;
		}
		i++;
	}
	return (NULL);
}

void	*life_cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time_ms();
	if (philo->id % 2 == 1)
	{
		philo_think(philo);
		usleep(philo->env->time_to_eat * 0.25 * 1000);
	}
	while (!philo->done)
	{
		take_forks(philo, get_time_ms());
		philo_eat(philo, get_time_ms());
		leave_forks(philo);
		philo_think(philo);
		if (philo->count_eat == philo->env->must_eat)
		{
			philo->done = true;
			philo->env->count_done++;
			break ;
		}
		philo_sleep(philo);
	}
	return (NULL);
}

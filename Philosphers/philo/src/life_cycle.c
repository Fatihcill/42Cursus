/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:29:11 by fcil              #+#    #+#             */
/*   Updated: 2022/06/08 17:30:41 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->number_of_philo)
		pthread_join(env->philos[i].th_id, NULL);
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
	while (philo->env->is_running)
	{
		take_forks(philo, get_time_ms());
		philo_eat(philo, get_time_ms());
		leave_forks(philo);
		if (philo->count_eat >= philo->env->must_eat)
		{
			philo->done = true;
			philo->env->is_running = false;
			//philo->env->count_done++;
		}
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

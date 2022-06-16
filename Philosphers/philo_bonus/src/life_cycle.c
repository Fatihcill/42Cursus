/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:06:07 by fcil              #+#    #+#             */
/*   Updated: 2022/06/16 14:36:12 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	process(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->number_of_philo)
	{
		env->philos[i].pid = fork();
		if (env->philos[i].pid < 0)
		{
			printf("Error! Fork");
			exit(-1);
		}
		if (env->philos[i].pid == 0)
			life_cycle(&env->philos[i]);
	}
	pthread_create(&env->is_running, NULL, waitp, env);
	pthread_detach(env->is_running);
}

void	life_cycle(t_philo *philo)
{
	pthread_t	checklife;

	if (philo->id % 2 == 1)
	{
		philo_think(philo);
		usleep(philo->env->time_to_eat * 0.25 * 1000);
	}
	philo->last_eat = 0;
	pthread_create(&checklife, NULL, life_cycle_checker, philo);
	pthread_detach(checklife);
	while (1)
	{
		take_forks(philo);
		philo_eat(philo);
		leave_forks(philo);
		philo_think(philo);
		if (philo->count_eat == philo->env->must_eat)
			exit(1);
		philo_sleep(philo);
	}
	exit(1);
}

void	*life_cycle_checker(void *arg)
{
	t_philo		*philo;
	uint64_t	timestamp;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->count_eat == philo->env->must_eat)
			break ;
		timestamp = get_time_ms() - philo->env->start_time;
		if (((int)(timestamp - philo->last_eat)) > philo->env->time_to_die)
		{
			printf("%llu %d %s\n", timestamp, philo->id, "died");
			sem_post(philo->env->isdied);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}

void	*waitp(void *arg)
{
	int		i;
	t_env	*env;

	env = (t_env *)arg;
	i = -1;
	while (++i < env->number_of_philo)
		waitpid(-1, NULL, 0);
	sem_post(env->isdied);
	return (NULL);
}
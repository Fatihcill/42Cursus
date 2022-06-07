/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:29:11 by fcil              #+#    #+#             */
/*   Updated: 2022/06/07 03:39:17 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	join_threads(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->number_of_philo)
	{
		pthread_join(env->philos[i].th_id, NULL);
	}
}

void	*life_cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
	{
		usleep(philo->env->time_to_eat * 0.25 * 1000); // ?
	}
	while (philo->count_eat < philo->env->must_eat) //todo check must eat
	{
		pthread_mutex_lock(&philo->env->chopsticks[philo->chopstick_l]);
		printf("%d. philo %d. chop using \n", philo->id, philo->chopstick_l);
		pthread_mutex_lock(&philo->env->chopsticks[philo->chopstick_r]);
		printf("%d. philo %d. chop using \n", philo->id, philo->chopstick_r);
		printf("EATING %d \n", philo->id);
		usleep(philo->env->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->env->chopsticks[philo->chopstick_l]);
		printf("%d. philo %d. chop free \n", philo->id, philo->chopstick_l);
		pthread_mutex_unlock(&philo->env->chopsticks[philo->chopstick_r]);
		printf("%d. philo %d. chop free \n", philo->id, philo->chopstick_r);
		philo->count_eat++;
		printf("FINISHED %d\n", philo->id);
	}
	return (NULL);
}

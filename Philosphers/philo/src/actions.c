/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:30:49 by fcil              #+#    #+#             */
/*   Updated: 2022/06/13 16:12:36 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo, uint64_t timestamp)
{
	pthread_mutex_lock(&philo->env->chopsticks[philo->chopstick_l]);
	printf("%llu %d %s\n", timestamp, philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->env->chopsticks[philo->chopstick_r]);
	printf("%llu %d %s\n", timestamp, philo->id, "has taken a fork");
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->env->chopsticks[philo->chopstick_l]);
	pthread_mutex_unlock(&philo->env->chopsticks[philo->chopstick_r]);
}

void	philo_eat(t_philo *philo, uint64_t timestamp)
{
	printf("%llu %d %s\n", timestamp, philo->id, "is eating");
	philo->last_eat = timestamp;
	philo->count_eat++;
	usleep(philo->env->time_to_eat * 1000);
}

void	philo_sleep(t_philo *philo)
{
	printf("%llu %d %s\n", get_time_ms() - philo->env->start_time,
		philo->id, "is sleeping");
	usleep(philo->env->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	printf("%llu %d %s\n", get_time_ms() - philo->env->start_time,
		philo->id, "is thinking");
}

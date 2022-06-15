/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:30:49 by fcil              #+#    #+#             */
/*   Updated: 2022/06/15 12:25:22 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo, uint64_t timestamp)
{
	uint64_t	reel_time;

	reel_time = timestamp - philo->env->start_time;
	pthread_mutex_lock(&philo->env->chopsticks[philo->chopstick_l]);
	printf("%llu %d %s\n", reel_time, philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->env->chopsticks[philo->chopstick_r]);
	printf("%llu %d %s\n", reel_time, philo->id, "has taken a fork");
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->env->chopsticks[philo->chopstick_l]);
	pthread_mutex_unlock(&philo->env->chopsticks[philo->chopstick_r]);
}

void	philo_eat(t_philo *philo, uint64_t timestamp)
{
	uint64_t	reel_time;

	reel_time = timestamp - philo->env->start_time;
	printf("%llu %d %s\n", reel_time, philo->id, "is eating");
	philo->last_eat = reel_time;
	philo->count_eat++;
	usleep(philo->env->time_to_eat * 1000);
}

void	philo_sleep(t_philo *philo)
{
	uint64_t	reel_time;

	reel_time = get_time_ms() - philo->env->start_time;
	printf("%llu %d %s\n", reel_time, philo->id, "is sleeping");
	usleep(philo->env->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	uint64_t	reel_time;

	reel_time = get_time_ms() - philo->env->start_time;
	printf("%llu %d %s\n", reel_time, philo->id, "is thinking");
}

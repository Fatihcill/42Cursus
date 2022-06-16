/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:30:49 by fcil              #+#    #+#             */
/*   Updated: 2022/06/16 12:56:51 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	take_forks(t_philo *philo)
{
	uint64_t	reel_time;

	reel_time = get_time_ms() - philo->env->start_time;
	sem_wait(philo->env->chopsticks);
	printf("%llu %d %s\n", reel_time, philo->id, "has taken a fork");
	sem_wait(philo->env->chopsticks);
	printf("%llu %d %s\n", reel_time, philo->id, "has taken a fork");
}

void	leave_forks(t_philo *philo)
{
	sem_post(philo->env->chopsticks);
	sem_post(philo->env->chopsticks);
}

void	philo_eat(t_philo *philo)
{
	uint64_t	reel_time;

	reel_time = get_time_ms() - philo->env->start_time;
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

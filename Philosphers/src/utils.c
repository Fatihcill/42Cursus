/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 03:20:54 by fcil              #+#    #+#             */
/*   Updated: 2022/06/07 03:31:19 by fcil             ###   ########.fr       */
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
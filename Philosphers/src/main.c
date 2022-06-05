/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:11:36 by fcil              #+#    #+#             */
/*   Updated: 2022/06/05 22:12:49 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(int ac, char **av, t_env *env)
{
	env->number_of_philo = atoi(av[1]);
	env->time_to_die = atoi(av[2]);
	env->time_to_eat = atoi(av[3]);
	env->time_to_sleep = atoi(av[4]);
	env->must_eat = -1;
	if (ac == 6)
		env->must_eat = atoi(av[5]);
}

void	init_philo(t_env *env)
{
	int	i;

	env->philos = malloc(sizeof(t_philo) * env->number_of_philo);
	env->chopsticks = malloc(sizeof(pthread_mutex_t) * env->number_of_philo);
	i = -1;
	while (++i < env->number_of_philo)
	{
		env->philos->id = i;
		env->philos[i].chopstick_l = i;
		env->philos[i].chopstick_r = (i + 1) % env->number_of_philo;
		env->philos[i].count_eat = 0;
		env->philos[i].env = env;
	}
}

void	init_threads(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->number_of_philo)
	{
    	pthread_create(&env->philos[i].th_id, NULL, mythreadfun, (void *)&env->philos[i]);
	}
}

void	join_threads(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->number_of_philo)
	{
    	pthread_join(env->philos[i].th_id, NULL);
	}
}

int main(int ac, char **av)
{
	t_env	env;

	if (ac < 5 || ac > 6)
		return (-1);
	init(ac, av, &env);
	init_philo(&env);
	init_threads(&env);
	join_threads(&env);
	return (0);
}
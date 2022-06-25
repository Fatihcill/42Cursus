/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:33:22 by fcil              #+#    #+#             */
/*   Updated: 2022/06/25 14:06:59 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	init(int ac, char **av, t_env *env)
{
	env->number_of_philo = ft_atoi(av[1]);
	env->time_to_die = ft_atoi(av[2]);
	env->time_to_eat = ft_atoi(av[3]);
	env->time_to_sleep = ft_atoi(av[4]);
	env->must_eat = -1;
	if (ac == 6)
		env->must_eat = ft_atoi(av[5]);
	if (env->time_to_die < 60 || env->time_to_eat < 60
		|| env->time_to_sleep < 60)
	{
		printf("Arguments cannot be smaller than 60ms\n");
		exit(-1);
	}
	if (env->number_of_philo > 200)
	{
		printf("Error: Philosopher count cannot be higher than 200\n");
		exit(-1);
	}
	env->start_time = get_time_ms();
}

void	init_philo(t_env *env)
{
	int	i;

	env->philos = malloc(sizeof(t_philo) * env->number_of_philo);
	i = -1;
	while (++i < env->number_of_philo)
	{
		env->philos[i].id = i + 1;
		env->philos[i].count_eat = 0;
		env->philos[i].last_eat = 0;
		env->philos[i].env = env;
	}
}

void	init_sem(t_env *env)
{
	destroy_semaphores();
	env->chopsticks = sem_open("./chopsticks", O_CREAT,
			S_IRWXG, env->number_of_philo);
	env->isdied = sem_open("./isdied", O_CREAT,
			S_IRWXG, 0);
	env->typing = sem_open("./typing", O_CREAT,
			S_IRWXG, 1);
	if (env->chopsticks == SEM_FAILED || env->isdied == SEM_FAILED)
	{
		printf("Error! Sem_Open");
		exit(-1);
	}
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac < 5 || ac > 6)
	{
		printf("Usage: ./philo number_of_philo ");
		printf("time_to_die time_to_eat time_to_sleep must_eat\n");
		exit(-1);
	}
	init(ac, av, &env);
	init_philo(&env);
	init_sem(&env);
	process(&env);
	sem_wait(env.isdied);
	destroy(&env);
	return (0);
}

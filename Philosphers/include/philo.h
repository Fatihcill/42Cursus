/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:10:10 by fcil              #+#    #+#             */
/*   Updated: 2022/06/07 03:30:33 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_env	t_env;
typedef struct s_philo
{
	int				id;
	int				count_eat;
	int				chopstick_r;
	int				chopstick_l;
	bool			done;
	pthread_t		th_id;
	t_env			*env;
}				t_philo;

typedef struct s_env
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				count_done;
	bool			is_running;
	t_philo			*philos;
	pthread_mutex_t	*chopsticks;
}				t_env;

//main
void	init(int ac, char **av, t_env *env);
void	init_philo(t_env *env);
void	init_threads(t_env *env);
void	init_mutexes(t_env *env);

//life_cycle
void	*life_cycle(void *arg);
void	join_threads(t_env *env);

//utils
void	destroy_threads(t_env *env);
void	destroy_mutexes(t_env *env);

#endif
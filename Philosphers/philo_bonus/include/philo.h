/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:10:10 by fcil              #+#    #+#             */
/*   Updated: 2022/06/13 16:24:16 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "semaphore.h"
# include "pthread.h"
# include "stdint.h"
# include "sys/time.h"
# include <pthread.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/stat.h> 
# include "stdbool.h"
# include "sys/time.h"
# include "sys/wait.h"
# include <signal.h>

typedef struct s_env	t_env;
typedef struct s_philo
{
	int				pid;
	int				id;
	int				count_eat;
	uint64_t		last_eat;
	t_env			*env;
}				t_philo;

typedef struct s_env
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	bool			is_died;
	uint64_t		start_time;
	pthread_t		is_running;
	t_philo			*philos;
	sem_t			*chopsticks;
}				t_env;

//main
void		init(int ac, char **av, t_env *env);
void		init_philo(t_env *env);
void		init_threads(t_env *env);
void		init_mutexes(t_env *env);

//life_cycle
void		*life_cycle(void *arg);
void		*life_cycle_checker(void *arg);

//utils
void		destroy_threads(t_env *env);
void		destroy_mutexes(t_env *env);
uint64_t	get_time_ms(void);

//actions
void		take_forks(t_philo *philo, uint64_t timestamp);
void		leave_forks(t_philo *philo);
void		philo_eat(t_philo *philo, uint64_t timestamp);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

#endif
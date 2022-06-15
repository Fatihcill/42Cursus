/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:10:10 by fcil              #+#    #+#             */
/*   Updated: 2022/06/15 17:24:37 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

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
void		init_sem(t_env *env);

//life_cycle
void		life_cycle(t_philo *philo);
void		*life_cycle_checker(void *arg);
void		process(t_env *env);
void		*waitp(void *arg);

//utils
uint64_t	get_time_ms(void);
int			ft_atoi(char *s);

//actions
void		take_forks(t_philo *philo, uint64_t timestamp);
void		leave_forks(t_philo *philo);
void		philo_eat(t_philo *philo, uint64_t timestamp);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

#endif
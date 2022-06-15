/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:10:10 by fcil              #+#    #+#             */
/*   Updated: 2022/06/14 12:40:10 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_env	t_env;
typedef struct s_philo
{
	int				id;
	int				count_eat;
	int				chopstick_r;
	int				chopstick_l;
	bool			done;
	uint64_t		last_eat;
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
	uint64_t		start_time;
	t_philo			*philos;
	pthread_mutex_t	*chopsticks;
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
int			ft_atoi(char *s);

//actions
void		take_forks(t_philo *philo, uint64_t timestamp);
void		leave_forks(t_philo *philo);
void		philo_eat(t_philo *philo, uint64_t timestamp);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

#endif
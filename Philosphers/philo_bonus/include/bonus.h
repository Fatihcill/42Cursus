/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:10:10 by fcil              #+#    #+#             */
/*   Updated: 2022/06/16 14:25:20 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <stdint.h>
# include <signal.h>
# include <fcntl.h>

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
	uint64_t		start_time;
	pthread_t		is_running;
	t_philo			*philos;
	sem_t			*chopsticks;
	sem_t			*isdied;
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
void		destroy(t_env *env);
void		destroy_semaphores(void);

//actions
void		take_forks(t_philo *philo);
void		leave_forks(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

#endif
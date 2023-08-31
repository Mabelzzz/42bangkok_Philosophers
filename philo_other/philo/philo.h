/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:05:48 by araiva            #+#    #+#             */
/*   Updated: 2022/11/12 23:05:49 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define GRAY		"\033[0;37m"
# define LRED		"\033[0;91m"
# define BOLD		"\033[1m"
# define RESET		"\033[0m"

# define S_SLEEPING	0
# define S_THINK	1
# define S_FORK		2
# define S_EATING	3
# define S_FULL		9
# define S_DIED		99
# define USEC		0
# define MSEC		1
# define EVEN		0
# define ODD		1
/**
 * @brief programe data struct
 * n	number_of_philosophers
 * ttd	time_to_die
 * tte	time_to_eat
 * tts	time_to_sleep
 * m	number_of_times_each_philosopher_must_eat
 */
typedef struct s_data
{
	int					n;
	int					ttd;
	int					tte;
	int					tts;
	int					m;
	int					unlimit;
	int					is_end;
	unsigned long int	t;
}	t_data;

typedef struct s_philo
{
	int				idx;
	int				time;
	int				status;
	int				count;
	t_data			data;
	pthread_t		tid;
	pthread_mutex_t	mute;
	struct s_philo	*next;
}	t_philo;

typedef struct s_dinner
{
	t_data				data;
	pthread_t			tid;
	unsigned long int	time;
	t_philo				*philos;
}	t_dinner;

/* Main */
void				*routine(void *arguments);
void				*observer(void *arguments);
void				start(t_dinner dinner, t_philo **philos);

/* Utilities */
unsigned long int	getgametime(t_data data, int unit);
unsigned long int	gettimestamp(int unit);
void				my_usleep(unsigned long int ttime);
int					ft_atoi(const char *nb);
int					ph_lstsize(t_philo *philo);
void				ph_lstfree(t_philo **philos);
void				ph_print(t_philo *philo);
void				ph_create(t_philo **philos, t_data data);
void				ph_think(t_philo *philo);
void				ph_eat(t_philo *philo);
void				ph_sleep(t_philo *philo);

#endif

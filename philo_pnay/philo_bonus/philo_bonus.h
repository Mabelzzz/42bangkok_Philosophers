/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:27:52 by araiva            #+#    #+#             */
/*   Updated: 2022/11/13 14:27:54 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/wait.h>

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
# define F_TAKEN	1
# define F_RELEASE	0
# define USEC		0
# define MSEC		1

typedef struct s_data
{
	int					n;
	int					ttd;
	int					tte;
	int					tts;
	int					m;
	int					*pids;
	int					pstat;
	sem_t				*semt;
	sem_t				*semtp;
	unsigned long int	t;
}	t_data;

typedef struct s_philo
{
	int				idx;
	int				time;
	int				status;
	int				count;
}	t_philo;

/* Main */
void				routine(t_data data, int idx);

/* Utilities */
unsigned long int	gettimestamp(int unit);
unsigned long int	getgametime(t_data data, int unit);
void				my_usleep(unsigned long int ttime);
int					ft_atoi(const char *nb);
void				ph_print(t_data data, t_philo *philo);
t_philo				ph_create(t_data data, int idx);
void				ph_eat(t_data data, t_philo *philo);
void				ph_sleep(t_data data, t_philo *philo);
void				ph_think(t_data data, t_philo *philo);

#endif

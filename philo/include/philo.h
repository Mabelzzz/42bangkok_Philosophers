/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:24:40 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/09/14 23:42:09 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
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

typedef struct s_input
{
	int				num_of_philo;
	int				num_of_eat;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	long long		start_time;
}					t_input;

typedef struct s_philo
{
	int				id;
	int				num_of_ate;
	long long		current;
	long long		last_meal;
	int				eat_cnt;
	t_input			*input;
	pthread_t		thread;
	pthread_mutex_t	my_forks;
	int				f;
}					t_philo;

typedef struct s_data
{
	int					tid;
	int					is_dead;
	pthread_t			check;
	pthread_mutex_t		print;
	t_input				*input;
	t_philo				*philo;
}					t_data;

//ft_atoi.c
int				ft_atoi(const char *str);

//get_time.c
long long		get_time(void);
long long		current_time(t_data *data);
void			spend_time(long long time);

//mutex.c
void			init_mutex(t_data *data);
void			destroy_mutex(t_data *data);

//input.c
int				check_input(int argc, char **argv);
void			get_input(char **argv, t_data *data, t_input *input);
void			set_another_fork(t_data *data);

//philo.c
void			starting(t_data *data);
void			create_pthread(t_data *data);
void			join_pthread(t_data *data);

//routine.c
void			*routine(void *args);
void			take_fork(t_data *data, int tid);
void			eating(t_data *data, int tid);
void			sleeping(t_data *data, int tid);
void			thinking(t_data *data, int tid);

//check_die.c
void			*check_is_dead(void *args);
void			check_is_full(t_data	*data);
void			dead(t_data *data, int tid);

//utils.c
int				put_error(char *str);
void			ft_print(t_data *data, int tid, char *str, char *color);
void			ft_print_fork(t_data *data, int tid, char *color);
void			ft_exit(t_data *data);

#endif

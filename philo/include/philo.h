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

// typedef struct s_fork
// {
// 	int				left;
// 	int				right;
// }					t_fork;

typedef struct s_philo
{
	int				id;
	int				num_of_ate;
	int				time_to_die;
	int				fork_left;
	int				fork_right;
	pthread_t		thread;
	pthread_mutex_t	forks;
}					t_philo;

typedef struct s_input
{
	int				num_philo;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				num_of_eat;
	long long		start_time;
}					t_input;

typedef struct s_data
{
	// int				n_thread;
	// int				philo_dead;
	// long long		t0;
	t_input			*input;
	t_philo			*philo;

	// pthread_t		checker;

	// pthread_mutex_t	table;
	// pthread_mutex_t	write;
}					t_data;

long long	get_time(void);
void		*routine(void *args);
int			check_input(int argc, char **argv);
int			ft_atoi(const char *str);
void		create_pthread(t_data *data, int argc, char **argv);
void		get_input(t_input *input, char **argv);

#endif
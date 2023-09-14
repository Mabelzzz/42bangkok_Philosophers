#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define PHILO		data->philo
# define IS_DEAD	data->is_dead
# define DIE		data->input->time_to_die
# define EAT		data->input->time_to_eat
# define SLP		data->input->time_to_sleep
# define NUM_EAT	data->input->num_of_eat
# define NUM_PHILO	data->input->num_of_philo
# define START		data->input->start_time

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
	int				time_to_die;
	int				fork_left;
	int				fork_right;
	long long		current;
	long long		last_meal;
	int				eat_cnt;
	t_input			*input;
	pthread_t		thread;
	pthread_mutex_t	my_forks;
	// pthread_mutex_t	another_forks;
	int				f;
}					t_philo;

typedef struct s_data
{
	int					tid;
	int					status_die;
	int					is_dead;
	// int				philo_dead;
	// long long		t0;
	pthread_t		check;
	pthread_mutex_t	print;
	t_input			*input;
	t_philo			*philo;

	// pthread_t		checker;

	// pthread_mutex_t	table;
	// pthread_mutex_t	write;
}					t_data;

int		ft_atoi(const char *str);


long long	get_time(void);
long long	current_time(t_data *data);
void		spend_time(long long time);

void	init_mutex(t_data *data);
void	destroy_mutex(t_data *data);

int		check_input(int argc, char **argv);
void	get_input(char **argv, t_data *data, t_input *input);

void		set_another_fork(t_data *data);
void		take_fork(t_data *data, int tid);
void		create_pthread(t_data *data);

void	*routine(void *args);
void	eating(t_data *data, int tid);
void	sleeping(t_data *data, int tid);
void	thinking(t_data *data, int tid);
void	dead(t_data *data, int tid);

int		check_die(t_data *data, int tid, int eat);
void	*check_is_dead(void *args);
void	check_who_die(t_data *data, int tid);

void	ft_print(t_data *data, int tid, char *str, char *color);
void	ft_print_fork(t_data *data, int tid, char *color);
void	ft_exit(t_data *data);

#endif

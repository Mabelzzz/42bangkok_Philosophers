
#include "philo.h"

void		set_fork(t_data *data);
void		*routine(void *args);
long long	get_time(void);
void		create_pthread(t_data *data, int argc, char **argv);
void		my_sleep(long long start, long long time);
// void		ft_print(t_philo *philo, char *str);
void	ft_print(t_philo *philo, char *str, char *color);

int	main(int argc, char **argv)
{
	t_data	data;

	// data = NULL;
	// data = malloc(sizeof(t_data));
	if(check_input(argc, argv))
		return (1);
	// printf("check argv = %d\n", check_input(argc, argv));
	data.input = malloc(sizeof(t_input));
	get_input(argc, argv, data.input);
	create_pthread(&data, argc, argv);

	return (0);
}

void	set_fork(t_data *data)
{
	int	i;

	i = -1;
	while(++i < data->input->num_philo)
	{
		printf("i = %d < %d\n", i, data->input->num_philo);
		// data->philo[i].fork_left = i;
		if (i != data->input->num_philo - 1)
		{
			printf("if i = %d < %d\n", i, data->input->num_philo);
			data->philo[i].another_forks = data->philo[i + 1].my_forks;
		}
		else
		{
			printf("el i = %d < %d\n", i, data->input->num_philo);
			data->philo[i].another_forks = data->philo[0].my_forks;
		}
			// data->philo[i].fork_right = 0;
	}
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}

void	*routine(void *args)
{
	// t_data	*data;
	t_philo		*philo;

	// data = (t_data *)args;
	philo = (t_philo *)args;

	while(1)
	{
		// pthread_mutex_lock(&data->philo[data->tid].forks);
		// printf("Test philo id = %d get_time --> %llu\n", philo->id, get_time());
		if(pthread_mutex_lock(&philo->my_forks) == 0)
			// printf("Philo %d has taken a my_fork ( ˘▽˘)っ Y\n", philo->id);
			ft_print(philo, "has taken a my_fork", MAGENTA);
		if(pthread_mutex_lock(&philo->another_forks) == 0)
			// printf("Philo %d has taken a another_fork ( ˘▽˘)っ Y\n", philo->id);
			ft_print(philo, "has taken a another_fork", MAGENTA);
		// pthread_mutex_lock(&philo->fork);
		// eating(philo);
		philo->current = get_time() - philo->input->start_time;
		ft_print(philo, "is eating", GREEN);
		my_sleep(philo->current, (long long)philo->input->time_to_eat);
		philo->eat_cnt++;
		// printf("Test philo id = %d now_time --> %llu\n", data->philo[data->tid].id, get_time() - data->input->start_time);
		// printf("-------------------------------------------------------------------------------------------\n");
		pthread_mutex_unlock(&philo->my_forks);
		pthread_mutex_unlock(&philo->another_forks);
		philo->current = get_time() - philo->input->start_time;
		ft_print(philo, "is sleeping", BLUE);
		my_sleep(philo->current, (long long)philo->input->time_to_sleep);
		philo->current = get_time() - philo->input->start_time;
		ft_print(philo, "is thinking", YELLOW);
		// sleeping(philo);

	}
	return (NULL);
}

void	my_sleep(long long start, long long time)
{
	while(get_time() - start < time * 1000)
		usleep(1);
}

// void	eating(t_philo *philo)
// {
// 	long long current;
// 	long long start;

// 	start = get_time();
// 	current = get_time();
// 	my_sleep(get_time(), philo->input->time_to_eat);
// }

void	ft_print(t_philo *philo, char *str, char *color)
{
	if(pthread_mutex_lock(&philo->print) == 0)
		printf("%sPhilo[%lld] %d %s\n"RESET, color, philo->current/1000, philo->id, str);
	pthread_mutex_unlock(&philo->print);
}

void	create_pthread(t_data *data, int argc, char **argv)
{
	int	i;

	i = -1;
	(void) argv;
	(void) argc;

	data->philo = malloc(sizeof(t_philo) * data->input->num_philo);
	pthread_mutex_init(&data->print, NULL);
	while (++i < data->input->num_philo)
	{
		pthread_mutex_init(&data->philo[i].my_forks, NULL);
		// printf("Thread %d before started\n", data->philo[data->tid].id);
		data->philo[i].print = data->print;
		data->philo[i].input = data->input;
	}
	set_fork(data);
	i = -1;
	while (++i < data->input->num_philo)
	{
		// data->tid = i;
		data->philo[i].id = i + 1;
		// printf("Thread %d %d before started\n", i, data->philo[i].id);
		if (pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]) != 0)
		{
			perror("Fail to create thread");
			return ;
		}
		// printf("Thread %d has started\n", i);
	}
	i = -1;
	while (++i < data->input->num_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return ;
		// printf("Thread %d has finished execution\n", i);

	}
}


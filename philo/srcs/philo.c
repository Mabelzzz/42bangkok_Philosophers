
#include "../include/philo.h"
# include <stdio.h>

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
	set_fork(&data);
	create_pthread(&data, argc, argv);

	return (0);
}

void	set_fork(t_data *data)
{
	int	i;

	i = -1;
	while(++i < data->input->num_philo)
	{
		// data->philo[i].fork_left = i;
		if (i != data->input->num_philo - 1)
			data->philo[i].another_forks = &data->philo[i + 1].my_forks;
		else
			data->philo[i].another_forks = &data->philo[0].my_forks;
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

	// pthread_mutex_lock(&data->philo[data->tid].forks);
	printf("Test philo id = %d get_time --> %llu\n", philo->id, get_time());
	if(pthread_mutex_lock(&philo->my_forks) == 0)
		printf("Philo %d has taken a my_fork ( ˘▽˘)っ Y\n", philo->id);
	if(pthread_mutex_lock(philo->another_forks) == 0)
		printf("Philo %d has taken a another_fork ( ˘▽˘)っ Y\n", philo->id);
	// pthread_mutex_lock(&philo->fork);

	// printf("Test philo id = %d now_time --> %llu\n", data->philo[data->tid].id, get_time() - data->input->start_time);
	// printf("-------------------------------------------------------------------------------------------\n");
	// pthread_mutex_unlock(&data->philo[data->tid].forks);
	return (NULL);
}

void	create_pthread(t_data *data, int argc, char **argv)
{
	int	i;

	i = -1;
	(void) argv;
	(void) argc;

	data->philo = malloc(sizeof(t_philo) * data->input->num_philo);
	while (++i < data->input->num_philo)
	// {
		// pthread_mutex_init(&data->philo[i].forks, NULL);
		// data->tid = i;
		// data->philo[data->tid].id = i + 1;
		printf("Thread %d before started\n", data->philo[i].id);
	// }
	i = -1;
	while (++i < data->input->num_philo)
	{
		// data->tid = i;
		data->philo[i].id = i + 1;
		printf("Thread %d %d before started\n", i, data->philo[i].id);
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


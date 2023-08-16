
#include "../include/philo.h"
# include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if(check_input(argc, argv))
		return (1);
	// printf("check argv = %d\n", check_input(argc, argv));
	data.input = malloc(sizeof(t_input));
	get_input(data.input, argv);
	create_pthread(&data, argc, argv);

	return (0);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}

void	*routine(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	pthread_mutex_lock(&data->philo[data->philo->id].forks);
	// printf("Test  time --> \n");
	printf("Test philo id = %d get_time --> %llu\n", data->philo->id, get_time() - data->input->start_time);
	pthread_mutex_unlock(&data->philo[data->philo->id].forks);
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
	{
		data->philo->id = i;
		printf("Thread %d before started\n", i);
		if (pthread_create(&data->philo[i].thread, NULL, &routine, data) != 0)
		{
			perror("Fail to create thread");
			return ;
		}
		printf("Thread %d has started\n", i);
	}
	i = -1;
	while (++i < data->input->num_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return ;
		printf("Thread %d has finished execution\n", i);

	}
}

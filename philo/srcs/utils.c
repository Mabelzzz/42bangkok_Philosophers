#include "philo.h"

void	ft_print(t_data *data, int tid, char *str, char *color);
void	ft_print_fork(t_data *data, int tid, char *color);
void	ft_exit(t_data *data);

void	ft_print(t_data *data, int tid, char *str, char *color)
{

	if (pthread_mutex_lock(&data->print) == 0)
	{
		PHILO[tid].current = current_time(data);
		printf("%sPhilo[%lld] %d %s\n"RESET, color, PHILO[tid].current, tid + 1, str);
	}
	pthread_mutex_unlock(&data->print);
}

void	ft_print_fork(t_data *data, int tid, char *color)
{

	if (pthread_mutex_lock(&data->print) == 0)
	{
		printf("%sPhilo[%lld] %d %s\n"RESET, color, PHILO[tid].current, tid + 1, "has taken a my_fork");
		printf("%sPhilo[%lld] %d %s\n"RESET, color, PHILO[tid].current, tid + 1, "has taken a another_fork");
	}
	pthread_mutex_unlock(&data->print);
}

void	ft_exit(t_data *data)
{
	destroy_mutex(data);
	free(PHILO);
	free(data->input);
	exit(0);
}

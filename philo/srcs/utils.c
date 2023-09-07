#include "philo.h"

void	ft_print(t_data *data, int tid, char *str, char *color);
void	ft_print_fork(t_data *data, int tid, char *color);

void	ft_print(t_data *data, int tid, char *str, char *color)
{

	if (pthread_mutex_lock(&data->print) == 0)
	{
		// printf("i = %d f = %d ", tid, PHILO[tid].f);
		PHILO[tid].current = current_time(data);
		printf("%sPhilo[%lld] %d %s\n"RESET, color, PHILO[tid].current, tid + 1, str);
		if (str[3] == 'd')
			exit(0);
	}
		// printf("%sPhilo[%lld] %d %s\n"RESET, color, current_time(philo)/1000, philo->id, str);
	pthread_mutex_unlock(&data->print);
}

void	ft_print_fork(t_data *data, int tid, char *color)
{

	if (pthread_mutex_lock(&data->print) == 0)
	{
		// printf("i = %d f = %d ", tid, PHILO[tid].f);
		PHILO[tid].current = current_time(data);
		printf("%sPhilo[%lld] %d %s\n"RESET, color, PHILO[tid].current, tid + 1, "has taken a my_fork");
		printf("%sPhilo[%lld] %d %s\n"RESET, color, PHILO[tid].current, tid + 1, "has taken a another_fork");
	}
		// printf("%sPhilo[%lld] %d %s\n"RESET, color, current_time(philo)/1000, philo->id, str);
	pthread_mutex_unlock(&data->print);
}

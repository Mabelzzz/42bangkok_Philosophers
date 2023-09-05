#include "philo.h"

void	ft_print(t_data *data, int tid, char *str, char *color)
{
	if (pthread_mutex_lock(&data->print) == 0)
	{
		// printf("i = %d f = %d ", tid, data->philo[tid].f);
		printf("%sPhilo[%lld] %d %s\n"RESET, color, get_time()/1000 - data->input->start_time, tid + 1, str);
	}
		// printf("%sPhilo[%lld] %d %s\n"RESET, color, current_time(philo)/1000, philo->id, str);
	pthread_mutex_unlock(&data->print);
}

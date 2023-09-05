#include "philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_init(&data->print, NULL);
	while (++i < data->input->num_philo)
		pthread_mutex_init(&data->philo[i].my_forks, NULL);
}

#include "philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_init(&data->print, NULL);
	while (++i < NUM_PHILO)
		pthread_mutex_init(&PHILO[i].my_forks, NULL);
}

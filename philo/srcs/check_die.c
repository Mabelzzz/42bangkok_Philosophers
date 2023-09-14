#include "philo.h"

void	*check_is_dead(void *args)
{
	int			id;
	long long	now;
	t_data 		*data;

	data = (t_data *)args;
	id = -1;
	while (!IS_DEAD)
	{
		id = -1;
		while (++id < NUM_PHILO)
		{
			now = current_time(data);
			if (now - PHILO[id].last_meal > DIE)
			{
				IS_DEAD = 1;
				dead(data, id);
			}
		}
	}
	return (NULL);
}

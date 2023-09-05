#include "philo.h"

int	check_die(t_data *data, int tid)
{
	int		alive;

	alive = data->input->time_to_die * data->philo[tid].eat_cnt;
	if (get_time()/1000 > alive)
		return (1);
	return (0);
}

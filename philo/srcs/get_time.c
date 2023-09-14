#include "philo.h"

long long	get_time(void);
long long	current_time(t_data *data);
void		spend_time(long long time);

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}

long long	current_time(t_data *data)
{
	long long	new_time;

	new_time = get_time()/1000;
	return (new_time - data->input->start_time);
}

void	spend_time(long long time)
{
	long long	start;

	start = get_time();
	while(get_time() - start < time)
		usleep(1);
}

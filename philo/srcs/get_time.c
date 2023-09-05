#include "philo.h"

long long	get_time(void);
long long	current_time(t_philo *philo);
void		spend_time(long long start, long long time);

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}

long long	current_time(t_philo *philo)
{
	long long	new_time;

	new_time = get_time();
	return (new_time - philo->input->start_time);
}

void	spend_time(long long start, long long time)
{
	// start = get_time();
	while(get_time() - start < time)
		usleep(1);
}

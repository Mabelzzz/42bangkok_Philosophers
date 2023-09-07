#include "philo.h"

long long	get_time(void);
long long	current_time(t_data *data);
void		spend_time(t_data *data, long long time, int tid, int eat);

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

void	spend_time(t_data *data, long long time, int tid, int eat)
{
	long long	start;
	long long	now;
	// long long	tmp;

	(void) eat;
	(void) data;
	(void) tid;
	// if (eat == 1)
		// tmp = DIE * (PHILO[tid].eat_cnt + 1);
	// else
	// 	tmp = DIE * PHILO[tid].eat_cnt;
	start = get_time();
	now = get_time();
	while(!IS_DEAD && now - start < time)
	{
		// if (now > tmp)
		// 	dead(data, tid);
		// if (current_time(data) - PHILO[tid].last_meal > DIE)
		// 	dead(data, tid);
		usleep(100);
		now = get_time();
	}
}

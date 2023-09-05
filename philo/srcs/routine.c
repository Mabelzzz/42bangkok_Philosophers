#include "philo.h"

void	*routine(void *args);
void	eating(t_data *data, int tid);
void	sleeping(t_data *data, int tid);
void	thinking(t_data *data, int tid);

void	*routine(void *args)
{
	int		i;
	t_data	*data;

	data = (t_data *)args;
	i = data->tid;
	if (i % 2 == 0)
		spend_time(get_time(), (long long)(data->input->time_to_eat * 1000));
	while (1)
	{
		eating(data, i);
		sleeping(data, i);
		thinking(data, i);
	}
	return (NULL);
}

void	eating(t_data *data, int tid)
{
	take_fork(data, tid);
	ft_print(data, tid, "is eating", GREEN);
	spend_time(get_time(), (long long)(data->input->time_to_eat * 1000));
	data->philo[tid].eat_cnt++;
	
	pthread_mutex_unlock(&data->philo[tid].my_forks);
	pthread_mutex_unlock(&data->philo[data->philo[tid].f].my_forks);
}

void	sleeping(t_data *data, int tid)
{
	ft_print(data, tid, "is sleeping", BLUE);
	spend_time(get_time(), (long long)(data->input->time_to_sleep * 1000));
}

void	thinking(t_data *data, int tid)
{
	ft_print(data, tid, "is thinking", YELLOW);
}

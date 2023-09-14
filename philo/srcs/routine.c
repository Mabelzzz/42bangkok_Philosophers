#include "philo.h"

void	*routine(void *args);
void	eating(t_data *data, int tid);
void	sleeping(t_data *data, int tid);
void	thinking(t_data *data, int tid);
void	dead(t_data *data, int tid);

void	*routine(void *args)
{
	int		i;
	t_data	*data;

	data = (t_data *)args;
	i = data->tid;
	PHILO[i].eat_cnt = 0;
	if (i % 2 != 0)
		usleep(10);
	PHILO[i].last_meal = data->input->start_time;
	while (!IS_DEAD && (PHILO[i].eat_cnt < NUM_EAT || NUM_EAT == -1))
	{
		eating(data, i);
		sleeping(data, i);
		thinking(data, i);
	}
	return (NULL);
}

void	eating(t_data *data, int tid)
{
	if(!IS_DEAD)
		take_fork(data, tid);
	else
		dead(data, tid);
	ft_print(data, tid, "is eating", GREEN);
	PHILO[tid].last_meal = current_time(data);
	PHILO[tid].eat_cnt++;
	spend_time((long long)(EAT * 1000));
	pthread_mutex_unlock(&PHILO[tid].my_forks);
	pthread_mutex_unlock(&PHILO[PHILO[tid].f].my_forks);
	if (PHILO[tid].eat_cnt == data->input->num_of_eat)
		exit(0);
}

void	sleeping(t_data *data, int tid)
{
	ft_print(data, tid, "is sleeping", BLUE);
	spend_time((long long)(SLP * 1000));
}

void	thinking(t_data *data, int tid)
{
	ft_print(data, tid, "is thinking", YELLOW);
}

void	dead(t_data *data, int tid)
{
	ft_print(data, tid, "is die", RED);
	ft_exit(data);
}

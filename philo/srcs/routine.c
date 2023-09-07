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
	// if (i % 2 != 0)
	// 	usleep(10);
		// spend_time(data, (long long)((EAT - 10) * 1000), i, 1);
	// while (!check_die(data, i, 1))
	PHILO[i].last_meal = data->input->start_time;
	while (!IS_DEAD && (PHILO[i].eat_cnt < NUM_EAT || NUM_EAT == -1))
	{
		// if (check_die(data, i, 1))
		// 	dead(data, i);
		eating(data, i);
		sleeping(data, i);
		thinking(data, i);
	}
	// if (IS_DEAD)
	// 	dead(data, i);
	return (NULL);
}

void	eating(t_data *data, int tid)
{
	if(!IS_DEAD)
		take_fork(data, tid);
	PHILO[tid].last_meal = current_time(data);
	ft_print(data, tid, "is eating", GREEN);
	// if (current_time(data) + EAT >)
	spend_time(data, (long long)(EAT * 1000), tid, 1);
	PHILO[tid].eat_cnt++;
	pthread_mutex_unlock(&PHILO[tid].my_forks);
	pthread_mutex_unlock(&PHILO[PHILO[tid].f].my_forks);
}

void	sleeping(t_data *data, int tid)
{
	if(!IS_DEAD)
	{
		ft_print(data, tid, "is sleeping", BLUE);
		spend_time(data, (long long)(SLP * 1000), tid, 2);
	}
}

void	thinking(t_data *data, int tid)
{
	if(!IS_DEAD)
		ft_print(data, tid, "is thinking", YELLOW);
}

void	dead(t_data *data, int tid)
{
	// if (check_die(data, tid))
	// 	dead(data, tid);
	ft_print(data, tid, "is die", RED);
	exit(1);
}

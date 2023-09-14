/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:27:12 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/09/14 23:38:32 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args);
void	take_fork(t_data *data, int tid);
void	eating(t_data *data, int tid);
void	sleeping(t_data *data, int tid);
void	thinking(t_data *data, int tid);

void	*routine(void *args)
{
	int		i;
	t_data	*data;

	data = (t_data *)args;
	i = data->tid;
	data->philo[i].eat_cnt = 0;
	if (i % 2 != 0)
		usleep(10);
	data->philo[i].last_meal = data->input->start_time;
	while (!data->is_dead)
	{
		eating(data, i);
		sleeping(data, i);
		thinking(data, i);
	}
	return (NULL);
}

void	take_fork(t_data *data, int tid)
{
	if (!pthread_mutex_lock(&data->philo[tid].my_forks)
		&& !pthread_mutex_lock(&data->philo[data->philo[tid].f].my_forks))
		ft_print_fork(data, tid, MAGENTA);
}

void	eating(t_data *data, int tid)
{
	if (!data->is_dead)
		take_fork(data, tid);
	else
		dead(data, tid);
	ft_print(data, tid, "is eating", GREEN);
	data->philo[tid].last_meal = current_time(data);
	data->philo[tid].eat_cnt++;
	check_is_full(data);
	spend_time((long long)(data->input->time_to_eat * 1000));
	pthread_mutex_unlock(&data->philo[tid].my_forks);
	pthread_mutex_unlock(&data->philo[data->philo[tid].f].my_forks);
}

void	sleeping(t_data *data, int tid)
{
	ft_print(data, tid, "is sleeping", BLUE);
	spend_time((long long)(data->input->time_to_sleep * 1000));
}

void	thinking(t_data *data, int tid)
{
	ft_print(data, tid, "is thinking", YELLOW);
}

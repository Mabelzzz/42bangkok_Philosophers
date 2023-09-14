/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:26:14 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/09/14 23:41:07 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_is_dead(void *args);
void	check_is_full(t_data	*data);
void	dead(t_data *data, int tid);

void	*check_is_dead(void *args)
{
	int			id;
	long long	now;
	t_data		*data;

	data = (t_data *)args;
	id = -1;
	while (!data->is_dead)
	{
		id = -1;
		while (++id < data->input->num_of_philo)
		{
			now = current_time(data);
			if (now - data->philo[id].last_meal > data->input->time_to_die)
			{
				data->is_dead = 1;
				dead(data, id);
			}
		}
	}
	return (NULL);
}

void	check_is_full(t_data	*data)
{
	int			id;
	int			eat_all;
	int			ck;

	id = -1;
	eat_all = 0;
	ck = 0;
	if (pthread_mutex_lock(&data->print) == 0)
	{
		while (++id < data->input->num_of_philo)
		{
			eat_all += data->philo[id].eat_cnt;
			if (data->philo[id].eat_cnt != data->input->num_of_eat)
				ck = -1;
		}
		if (eat_all == (data->input->num_of_eat * \
		data->input->num_of_philo) && !ck)
		{
			data->is_dead = 1;
			ft_exit(data);
		}
	}
	pthread_mutex_unlock(&data->print);
}

void	dead(t_data *data, int tid)
{
	ft_print(data, tid, "is die", RED);
	ft_exit(data);
}

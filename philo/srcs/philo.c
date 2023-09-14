/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:26:54 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/09/14 23:42:33 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		starting(t_data *data);
void		create_pthread(t_data *data);
void		join_pthread(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv))
		return (1);
	data.input = malloc(sizeof(t_input));
	get_input(argv, &data, data.input);
	starting(&data);
	return (0);
}

void	starting(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->input->num_of_philo);
	init_mutex(data);
	set_another_fork(data);
	data->input->start_time = get_time() / 1000;
	if (data->input->num_of_philo <= 1)
	{
		usleep(100);
		dead(data, 0);
	}
	create_pthread(data);
	join_pthread(data);
}

void	create_pthread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->input->num_of_philo)
	{
		data->philo[i].input = data->input;
		data->philo[i].id = i + 1;
		data->tid = i;
		if (pthread_create(&data->philo[i].thread, NULL, &routine, data) != 0)
		{
			perror("Fail to create thread");
			return ;
		}
		usleep(10);
	}
	if (pthread_create(&data->check, NULL, &check_is_dead, data) != 0)
		perror("Fail to create thread");
	usleep(10);
}

void	join_pthread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->input->num_of_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return ;
	}
	pthread_join(data->check, NULL);
}

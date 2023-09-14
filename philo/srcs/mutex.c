/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:26:37 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/09/14 22:54:42 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_data *data);
void	destroy_mutex(t_data *data);

void	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_init(&data->print, NULL);
	while (++i < data->input->num_of_philo)
		pthread_mutex_init(&data->philo[i].my_forks, NULL);
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->print);
	while (++i < data->input->num_of_philo)
		pthread_mutex_destroy(&data->philo[i].my_forks);
}

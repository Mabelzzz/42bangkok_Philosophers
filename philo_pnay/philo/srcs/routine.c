/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:42:41 by araiva            #+#    #+#             */
/*   Updated: 2022/11/12 22:42:42 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	died_onlyone(t_philo *philo);

void	*routine(void *arguments)
{
	t_philo	*philo;
	t_data	data;

	philo = ((t_philo *) arguments);
	data = philo->data;
	died_onlyone(philo);
	while (1)
	{
		pthread_mutex_lock(&philo->mute);
		ph_eat(philo);
		if (philo->data.is_end || philo->status == S_DIED)
			return (NULL);
		if (philo->count == data.m)
		{
			pthread_mutex_unlock(&philo->mute);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->mute);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (NULL);
}

static void	died_onlyone(t_philo *philo)
{
	if (philo->next == philo)
	{
		my_usleep(philo->data.ttd * 1000);
		philo->status = S_DIED;
	}
}

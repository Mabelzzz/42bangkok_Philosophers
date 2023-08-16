/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_activities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:29:33 by araiva            #+#    #+#             */
/*   Updated: 2022/11/13 17:29:34 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_live(t_philo *philo);

void	ph_eat(t_philo *philo)
{
	if (philo->status != S_THINK)
		return ;
	if (!is_live(philo))
		return ;
	pthread_mutex_lock(&philo->next->mute);
	philo->status = S_FORK;
	ph_print(philo);
	ph_print(philo);
	philo->status = S_EATING;
	ph_print(philo);
	my_usleep(philo->data.tte * 1000);
	philo->count++;
	if (philo->count == philo->data.m)
	{
		philo->status = S_FULL;
		ph_print(philo);
	}
	pthread_mutex_unlock(&philo->next->mute);
}

void	ph_sleep(t_philo *philo)
{
	if (philo->status != S_EATING)
		return ;
	philo->status = S_SLEEPING;
	philo->time = getgametime(philo->data, USEC);
	ph_print(philo);
	my_usleep(philo->data.tts * 1000);
}

void	ph_think(t_philo *philo)
{
	if (philo->status != S_SLEEPING)
		return ;
	philo->status = S_THINK;
	ph_print(philo);
	if (philo->next == philo)
		philo->status = S_DIED;
}

static int	is_live(t_philo *philo)
{
	unsigned long int	ttl;
	unsigned long int	ttd;

	ttl = getgametime(philo->data, USEC) - philo->time;
	ttd = philo->data.ttd * 1000;
	if (ttl + philo->data.tte * 1000 > ttd)
	{
		my_usleep(ttd - ttl);
		philo->data.is_end = 1;
		philo->status = S_DIED;
		return (0);
	}
	else
		return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_activities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:29:01 by araiva            #+#    #+#             */
/*   Updated: 2022/11/13 14:29:01 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	is_live(t_data data, t_philo *philo);

void	ph_eat(t_data data, t_philo *philo)
{
	if (philo->status != S_THINK)
		return ;
	if (!is_live(data, philo))
		return ;
	philo->status = S_FORK;
	ph_print(data, philo);
	ph_print(data, philo);
	philo->status = S_EATING;
	ph_print(data, philo);
	my_usleep(data.tte * 1000);
	philo->count++;
}

void	ph_sleep(t_data data, t_philo *philo)
{
	if (philo->status != S_EATING)
		return ;
	philo->status = S_SLEEPING;
	philo->time = getgametime(data, USEC);
	ph_print(data, philo);
	my_usleep(data.tts * 1000);
}

void	ph_think(t_data data, t_philo *philo)
{
	if (philo->status != S_SLEEPING)
		return ;
	philo->status = S_THINK;
	ph_print(data, philo);
	my_usleep(50);
}

static int	is_live(t_data data, t_philo *philo)
{
	unsigned long int	ttl;
	unsigned long int	ttd;
	unsigned long int	tte;

	ttl = getgametime(data, USEC) - philo->time;
	ttd = data.ttd * 1000;
	tte = data.tte * 1000;
	if (ttl + tte > ttd)
	{
		my_usleep(ttd - ttl);
		philo->status = S_DIED;
		return (0);
	}
	else
		return (1);
}

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
#include "philo_bonus.h"

static void	exit_onlyone(t_philo	philo, t_data data);
static void	exit_died(t_philo	philo, t_data data);
static void	handy_fork(t_data data, int act);

void	routine(t_data data, int idx)
{
	t_philo	philo;

	philo = ph_create(data, idx);
	exit_onlyone(philo, data);
	while (1)
	{
		handy_fork(data, F_TAKEN);
		ph_eat(data, &philo);
		exit_died(philo, data);
		handy_fork(data, F_RELEASE);
		ph_sleep(data, &philo);
		ph_think(data, &philo);
		if (philo.count == data.m)
		{
			philo.status = S_FULL;
			ph_print(data, &philo);
			return ;
		}
	}
	exit(0);
}

static void	exit_onlyone(t_philo philo, t_data data)
{
	if (data.n == 1)
	{
		philo.status = S_DIED;
		my_usleep(data.ttd * 1000);
		ph_print(data, &philo);
		exit(1);
	}
}

static void	exit_died(t_philo philo, t_data data)
{
	if (philo.status == S_DIED)
	{
		ph_print(data, &philo);
		exit(1);
	}
}

static void	handy_fork(t_data data, int act)
{
	if (act == F_TAKEN)
	{
		sem_wait(data.semt);
		sem_wait(data.semt);
	}
	if (act == F_RELEASE)
	{
		sem_post(data.semt);
		sem_post(data.semt);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:59:08 by araiva            #+#    #+#             */
/*   Updated: 2022/11/12 22:59:09 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	ph_delone(t_philo *philo);

void	ph_lstfree(t_philo **philos)
{
	t_philo	*philo;
	t_philo	*tmp;

	philo = *philos;
	while (philo && philo->next != *philos)
	{
		tmp = philo->next;
		ph_delone(philo);
		philo = tmp;
	}
	ph_delone(philo);
}

static void	ph_delone(t_philo *philo)
{
	pthread_mutex_destroy(&philo->mute);
	free(philo);
}

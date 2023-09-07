/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:53:32 by araiva            #+#    #+#             */
/*   Updated: 2022/11/12 22:53:33 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	start_order(t_philo *philo, t_dinner dinner, int order);

void	start(t_dinner dinner, t_philo **philos)
{
	if (!*philos)
		return ;
	pthread_create(&dinner.tid, NULL, &observer, &dinner);
	start_order(*philos, dinner, ODD);
	usleep(100);
	start_order(*philos, dinner, EVEN);
	pthread_join(dinner.tid, NULL);
}

static void	start_order(t_philo *philo, t_dinner dinner, int order)
{
	int	i;

	i = 1;
	while (i <= dinner.data.n)
	{
		if (i % 2 == order)
		{
			pthread_create(&philo->tid, NULL, &routine, philo);
			pthread_detach(philo->tid);
		}
		philo = philo->next;
		i++;
	}
}

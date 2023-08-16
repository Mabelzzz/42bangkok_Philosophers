/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:59:28 by araiva            #+#    #+#             */
/*   Updated: 2022/11/12 22:59:29 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static t_philo	*create_philo(int idx, t_data data);
static void		ph_lstadd(t_philo **philo, t_philo *new);

void	ph_create(t_philo **philos, t_data data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data.n)
	{
		philo = create_philo(i, data);
		ph_lstadd(philos, philo);
		i++;
	}
}

static t_philo	*create_philo(int idx, t_data data)
{
	t_philo			*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->idx = idx + 1;
	philo->data = data;
	philo->next = philo;
	philo->count = 0;
	philo->status = S_THINK;
	philo->time = getgametime(philo->data, USEC);
	if (pthread_mutex_init(&philo->mute, NULL) != 0)
	{
		free(philo);
		return (NULL);
	}
	return (philo);
}

static void	ph_lstadd(t_philo **philo, t_philo *new)
{
	t_philo	*tmp;

	if (!*philo)
		*philo = new;
	else
	{
		tmp = *philo;
		while (tmp->next != *philo)
			tmp = tmp->next;
		tmp->next = new;
		new->next = *philo;
	}
}

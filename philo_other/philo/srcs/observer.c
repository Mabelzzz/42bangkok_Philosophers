/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:42:52 by araiva            #+#    #+#             */
/*   Updated: 2022/11/12 22:42:54 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static int	is_died(t_dinner dinner);
static int	is_full(t_dinner dinner);

void	*observer(void *arguments)
{
	t_dinner	dinner;

	dinner = *(t_dinner *) arguments;
	while (1)
	{
		if (is_died(dinner))
			return (NULL);
		if (is_full(dinner))
			return (NULL);
	}
	return (NULL);
}

static int	is_died(t_dinner dinner)
{
	t_philo	*philo;
	int		i;

	i = 1;
	philo = dinner.philos;
	while (i <= dinner.data.n)
	{
		if (philo->status == S_DIED)
		{
			ph_print(philo);
			return (1);
		}
		philo = philo->next;
		i++;
	}
	return (0);
}

static int	is_full(t_dinner dinner)
{
	t_philo	*philo;
	int		i;

	i = 1;
	philo = dinner.philos;
	if (dinner.data.m < 0)
		return (0);
	while (i <= dinner.data.n)
	{
		if (philo->count < dinner.data.m)
			return (0);
		philo = philo->next;
		i++;
	}
	return (1);
}

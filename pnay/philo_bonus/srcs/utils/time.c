/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:56:14 by araiva            #+#    #+#             */
/*   Updated: 2022/11/12 22:56:15 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

unsigned long int	gettimestamp(int unit)
{
	struct timeval	now;
	long int		timestamp;
	int				rc;

	rc = gettimeofday(&now, NULL);
	if (rc < 0)
		return (-1);
	timestamp = now.tv_sec * 1000000 + now.tv_usec;
	if (unit == USEC)
		return (timestamp);
	else
		return (timestamp / 1000);
}

unsigned long int	getgametime(t_data data, int unit)
{
	unsigned long int	curtime;

	curtime = gettimestamp(USEC) - data.t;
	if (unit == USEC)
		return (curtime);
	else
		return (curtime / 1000);
}

void	my_usleep(unsigned long int ttime)
{
	unsigned long int	end;

	end = gettimestamp(USEC) + ttime;
	while (gettimestamp(USEC) < end)
		;
}

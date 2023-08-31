/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:58:23 by araiva            #+#    #+#             */
/*   Updated: 2022/11/12 22:58:24 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ph_print(t_philo *philo)
{
	unsigned long int	time;
	int					stat;

	time = getgametime(philo->data, MSEC);
	stat = philo->status;
	if (stat == S_FORK)
		printf("%ld %d has taken a fork\n", time, philo->idx);
	else if (stat == S_EATING)
		printf(YELLOW"%ld %d is eating"RESET"\n", time, philo->idx);
	else if (stat == S_SLEEPING)
		printf(CYAN"%ld %d is sleeping"RESET"\n", time, philo->idx);
	else if (stat == S_THINK)
		printf("%ld %d is thinking\n", time, philo->idx);
	else if (stat == S_FULL)
		printf(GREEN"%ld %d full"RESET"\n", time, philo->idx);
	else if (stat == S_DIED)
		printf(RED"%ld %d died"RESET"\n", time, philo->idx);
	else
		printf("%ld %d ??\n", time, philo->idx);
}

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
#include "philo_bonus.h"

static void	ph_print_str(t_philo *philo, unsigned long int time);

void	ph_print(t_data data, t_philo *philo)
{
	unsigned long int	time;
	int					stat;

	time = getgametime(data, MSEC);
	stat = philo->status;
	sem_wait(data.semtp);
	ph_print_str(philo, time);
	if (stat != S_DIED)
		sem_post(data.semtp);
}

static void	ph_print_str(t_philo *philo, unsigned long int time)
{
	if (philo->status == S_FORK)
		printf("%ld %d has taken a fork\n", time, philo->idx);
	else if (philo->status == S_EATING)
		printf(YELLOW"%ld %d is eating"RESET"\n", time, philo->idx);
	else if (philo->status == S_SLEEPING)
		printf(CYAN"%ld %d is sleeping"RESET"\n", time, philo->idx);
	else if (philo->status == S_THINK)
		printf("%ld %d is thinking\n", time, philo->idx);
	else if (philo->status == S_FULL)
		printf(GREEN"%ld %d is full"RESET"\n", time, philo->idx);
	else if (philo->status == S_DIED)
		printf(RED"%ld %d died"RESET"\n", time, philo->idx);
	else
		printf("%ld %d ??\n", time, philo->idx);
}

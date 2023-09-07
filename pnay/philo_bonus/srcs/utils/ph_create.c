/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:29:13 by araiva            #+#    #+#             */
/*   Updated: 2022/11/13 14:29:14 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	ph_create(t_data data, int idx)
{
	t_philo	philo;

	philo.idx = idx;
	philo.count = 0;
	philo.status = S_THINK;
	philo.time = getgametime(data, USEC);
	return (philo);
}

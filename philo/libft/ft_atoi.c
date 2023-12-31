/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:50:47 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/09/14 23:50:51 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long	index;
	long	result;
	long	minus;

	minus = 1;
	index = 0;
	result = 0;
	while ((str[index] == '\t' || str[index] == '\n' || str[index] == '\v'
			|| str[index] == '\f' || str[index] == '\r' || str[index] == ' '))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			minus *= -1;
		index++;
	}
	while (str[index] >= 48 && str[index] <= 57)
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	result *= minus;
	if (str[index] != 0 || result > 2147483647 || result < -2147483648)
		return (-1);
	return (result);
}

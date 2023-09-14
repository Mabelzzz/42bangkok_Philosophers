/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:28:24 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/09/14 23:28:21 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		put_error(char *str);
void	ft_print(t_data *data, int tid, char *str, char *color);
void	ft_print_fork(t_data *data, int tid, char *color);
void	ft_exit(t_data *data);

int	put_error(char *str)
{
	printf("%s%s\n"RESET, LRED, str);
	return (1);
}

void	ft_print(t_data *data, int tid, char *str, char *color)
{
	if (pthread_mutex_lock(&data->print) == 0)
	{
		data->philo[tid].current = current_time(data);
		printf("%s[%lld] %d %s\n"RESET, color, \
		data->philo[tid].current, tid + 1, str);
	}
	pthread_mutex_unlock(&data->print);
}

void	ft_print_fork(t_data *data, int tid, char *color)
{
	if (pthread_mutex_lock(&data->print) == 0)
	{
		printf("%s[%lld] %d %s\n"RESET, color, \
		data->philo[tid].current, tid + 1, "has taken a fork");
		printf("%s[%lld] %d %s\n"RESET, color, \
		data->philo[tid].current, tid + 1, "has taken a fork");
	}
	pthread_mutex_unlock(&data->print);
}

void	ft_exit(t_data *data)
{
	destroy_mutex(data);
	free(data->philo);
	free(data->input);
	exit(0);
}

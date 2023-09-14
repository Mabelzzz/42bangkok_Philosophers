/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:29:59 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/09/14 23:37:23 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		check_input(int argc, char **argv);
void	get_input(char **argv, t_data *data, t_input *input);
void	set_another_fork(t_data *data);

int	check_input(int argc, char **argv)
{
	if (argc < 5)
		return (put_error("Error: input must be at least 4 argument"));
	if (argc > 6)
		return (put_error("Error: input must be less than 6 argument"));
	if (ft_atoi(argv[1]) < 1)
		return (put_error("Error: number of philosophers must be least 1"));
	if (ft_atoi(argv[1]) > 200)
		return (put_error("Number of philosophers should be less than 200"));
	if (ft_atoi(argv[2]) <= 0)
		return (put_error("Error: time to die must be more than 0"));
	if (ft_atoi(argv[3]) <= 0)
		return (put_error("Error: time to eat must be more than 0"));
	if (ft_atoi(argv[4]) <= 0)
		return (put_error("Error: time_to_sleep must be more than 0"));
	if (argc == 6 && argv[5] && ft_atoi(argv[5]) <= 0)
		return (put_error("Error: number of times each \
		philosopher must eat should be more than 0"));
	return (0);
}

void	get_input(char **argv, t_data *data, t_input *input)
{
	data->is_dead = 0;
	input->num_of_philo = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	input->num_of_eat = -1;
	if (argv[5])
		input->num_of_eat = ft_atoi(argv[5]);
}

void	set_another_fork(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->input->num_of_philo)
	{
		if (i != data->input->num_of_philo - 1)
			data->philo[i].f = i + 1;
		else
			data->philo[i].f = 0;
	}
}

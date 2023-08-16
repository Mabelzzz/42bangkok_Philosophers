/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:28:06 by araiva            #+#    #+#             */
/*   Updated: 2022/10/03 18:28:07 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	validate(int argc, char *argv[]);
static int	setup(int argc, char *argv[], t_data *data);
static void	setup_dinner(t_dinner *dinner, t_data data, t_philo *philos);

int	main(int argc, char *argv[])
{
	t_data		data;
	t_dinner	dinner;
	t_philo		*philos;

	philos = NULL;
	if (!!validate(argc, argv))
		return (0);
	setup(argc, argv, &data);
	ph_create(&philos, data);
	setup_dinner(&dinner, data, philos);
	start(dinner, &philos);
	ph_lstfree(&philos);
	return (0);
}

static int	validate(int argc, char *argv[])
{
	if (argc < 5)
		return (printf("%sError: need at least 4 argument%s\n", LRED, RESET));
	if (ft_atoi(argv[1]) < 1
		|| ft_atoi(argv[2]) < 1
		|| ft_atoi(argv[3]) < 1
		|| ft_atoi(argv[4]) < 1)
		return (printf("%sError:invalid argument%s\n", LRED, RESET));
	if (argc > 5 && ft_atoi(argv[5]) <= 0)
		return (printf("%sError: times cannot less than 0%s\n", LRED, RESET));
	return (0);
}

static int	setup(int argc, char *argv[], t_data *data)
{
	data->n = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	data->t = gettimestamp(USEC);
	if (argc > 5 && ft_atoi(argv[5]))
		data->m = ft_atoi(argv[5]);
	else
		data->m = -1;
	data->is_end = 0;
	return (0);
}

static void	setup_dinner(t_dinner *dinner, t_data data, t_philo *philos)
{
	dinner->data = data;
	dinner->time = gettimestamp(USEC);
	dinner->philos = philos;
}

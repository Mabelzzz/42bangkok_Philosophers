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
#include "philo_bonus.h"

static int	validate(int argc, char *argv[]);
static void	setup(int argc, char *argv[], t_data *data);
static void	dexit(t_data data);
static void	nexit(t_data data);

int	main(int argc, char *argv[])
{
	t_data	data;
	pid_t	pid;
	int		i;

	if (!!validate(argc, argv))
		return (0);
	setup(argc, argv, &data);
	i = 0;
	while (i++ < data.n)
	{
		pid = fork();
		if (pid == 0)
		{
			routine(data, i);
			break ;
		}
		else
			data.pids[i - 1] = pid;
	}
	waitpid(-1, &data.pstat, 0);
	if (pid != 0 && WEXITSTATUS(data.pstat) == 1)
		dexit(data);
	waitpid(data.pids[data.n - 1], &data.pstat, 0);
	nexit(data);
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

static void	setup(int argc, char *argv[], t_data *data)
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
	data->pids = malloc(sizeof(int) * data->n);
	sem_unlink("/araiva");
	sem_unlink("/araiva_print");
	data->semt = sem_open("/araiva", O_CREAT, S_IRUSR | S_IWUSR, data->n);
	data->semtp = sem_open("/araiva_print", O_CREAT, S_IRUSR | S_IWUSR, 1);
}

static void	dexit(t_data data)
{
	int	i;

	i = 0;
	while (i < data.n)
	{
		kill(data.pids[i], SIGKILL);
		i++;
	}
	free(data.pids);
	sem_close(data.semt);
	sem_close(data.semtp);
	exit(1);
}

static void	nexit(t_data data)
{
	free(data.pids);
	sem_close(data.semt);
	sem_close(data.semtp);
	exit(0);
}

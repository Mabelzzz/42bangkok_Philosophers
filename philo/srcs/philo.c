
#include "philo.h"

void		set_another_fork(t_data *data);
void		take_fork(t_data *data, int tid);
void		starting(t_data *data);
void		create_pthread(t_data *data);
void		join_pthread(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	if(check_input(argc, argv))
		return (1);
	data.input = malloc(sizeof(t_input));
	get_input(argv, &data, data.input);
	starting(&data);
	// create_pthread(&data);
	return (0);
}

void	set_another_fork(t_data *data)
{
	int	i;

	i = -1;
	while(++i < NUM_PHILO)
	{
		if (i != NUM_PHILO - 1)
			PHILO[i].f = i + 1;
		else
			PHILO[i].f = 0;
	}
}

void	take_fork(t_data *data, int tid)
{
	if(!pthread_mutex_lock(&PHILO[tid].my_forks)
		&& !pthread_mutex_lock(&PHILO[PHILO[tid].f].my_forks))
		ft_print_fork(data, tid, MAGENTA);
}

void	starting(t_data *data)
{
	PHILO = malloc(sizeof(t_philo) * NUM_PHILO);
	init_mutex(data);
	set_another_fork(data);
	data->input->start_time = get_time() / 1000;
	if (NUM_PHILO <= 1)
	{
		usleep(100);
		dead(data, 0);
	}
	create_pthread(data);
	join_pthread(data);
}

void	create_pthread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < NUM_PHILO)
	{
		PHILO[i].input = data->input;
		PHILO[i].id = i + 1;
		data->tid = i;
		if (pthread_create(&PHILO[i].thread, NULL, &routine, data) != 0)
		{
			perror("Fail to create thread");
			return ;
		}
		usleep(10);
	}
	if (pthread_create(&data->check, NULL, &check_is_dead, data) != 0)
		perror("Fail to create thread");
	usleep(10);
}

void	join_pthread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < NUM_PHILO)
	{
		if (pthread_join(PHILO[i].thread, NULL) != 0)
			return ;
	}
	pthread_join(data->check, NULL);
}

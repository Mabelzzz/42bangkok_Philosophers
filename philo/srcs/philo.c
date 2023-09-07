
#include "philo.h"

void		set_fork(t_data *data);
void		take_fork(t_data *data, int tid);
void		create_pthread(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	// data = NULL;
	// data = malloc(sizeof(t_data));
	if(check_input(argc, argv))
		return (1);
	// printf("check argv = %d\n", check_input(argc, argv));
	data.input = malloc(sizeof(t_input));
	get_input(argc, argv, data.input);
	create_pthread(&data);

	return (0);
}

void	set_fork(t_data *data)
{
	int	i;

	i = -1;
	while(++i < NUM_PHILO)
	{
		// PHILO[i].fork_left = i;
		if (i != NUM_PHILO - 1)
		{
			// PHILO[i].another_forks = PHILO[i + 1].my_forks;
			PHILO[i].f = i + 1;
			// printf("i = %d f = %d ", i, PHILO[i].f);
		}
		else
		{
			// PHILO[i].another_forks = PHILO[0].my_forks;
			PHILO[i].f = 0;
			// printf("i = %d f = %d ", i, PHILO[i].f);
		}
			// PHILO[i].fork_right = 0;
	}
}

void	take_fork(t_data *data, int tid)
{
	if(!pthread_mutex_lock(&PHILO[tid].my_forks)
		&& !pthread_mutex_lock(&PHILO[PHILO[tid].f].my_forks))
		ft_print_fork(data, tid, MAGENTA);
}

void	create_pthread(t_data *data)
{
	int	i;

	i = -1;
	PHILO = malloc(sizeof(t_philo) * NUM_PHILO);
	init_mutex(data);
	set_fork(data);
	IS_DEAD = 0;
	data->input->start_time = get_time() / 1000;
	if (NUM_PHILO <= 1)
	{
		usleep(10);
		dead(data, 0);
	}
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
		// if (check_die(data, i + 1, 1))
		// 	dead(data, i + 1);
		usleep(10);
	}
	if (pthread_create(&data->check, NULL, &check_is_dead, data) != 0)
		perror("Fail to create thread");
	usleep(10);
	i = -1;
	while (++i < NUM_PHILO)
	{
		if (pthread_join(PHILO[i].thread, NULL) != 0)
			return ;
	}
	pthread_join(data->check, NULL);
	// check_is_dead(data);
}


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
	while(++i < data->input->num_philo)
	{
		// data->philo[i].fork_left = i;
		if (i != data->input->num_philo - 1)
		{
			// data->philo[i].another_forks = data->philo[i + 1].my_forks;
			data->philo[i].f = i + 1;
			// printf("i = %d f = %d ", i, data->philo[i].f);
		}
		else
		{
			// data->philo[i].another_forks = data->philo[0].my_forks;
			data->philo[i].f = 0;
			// printf("i = %d f = %d ", i, data->philo[i].f);
		}
			// data->philo[i].fork_right = 0;
	}
}

void	take_fork(t_data *data, int tid)
{
	if(!pthread_mutex_lock(&data->philo[tid].my_forks))
	{
		ft_print(data, tid, "has taken a my_fork", MAGENTA);
		// data->philo[i].fork_left = 1;
	}
	if(!pthread_mutex_lock(&data->philo[data->philo[tid].f].my_forks))
	{
		ft_print(data, tid, "has taken a another_fork", MAGENTA);
		// data->philo[i].fork_right = 1;
	}
}

void	create_pthread(t_data *data)
{
	int	i;

	i = -1;
	data->philo = malloc(sizeof(t_philo) * data->input->num_philo);
	init_mutex(data);
	set_fork(data);
	data->input->start_time = get_time() / 1000;
	while (++i < data->input->num_philo)
	{
		data->philo[i].input = data->input;
		data->philo[i].id = i + 1;
		data->tid = i;
		if (pthread_create(&data->philo[i].thread, NULL, &routine, data) != 0)
		{
			perror("Fail to create thread");
			return ;
		}
		usleep(3);
	}
	i = -1;
	while (++i < data->input->num_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return ;
	}
}

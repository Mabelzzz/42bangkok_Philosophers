
#include "philo.h"

void	get_input(t_input *input, char **argv)
{
	input->num_philo = ft_atoi(argv[1]);
	input->time_to_eat = ft_atoi(argv[2]);
	input->time_to_die = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		input->num_of_eat = ft_atoi(argv[5]);
	else
		input->num_of_eat = -1;
	input->start_time = get_time();
}


int	check_input(int argc, char **argv)
{
	if (argc < 5)
		return (printf("%sError: input must be at least 4 argument%s\n", LRED, RESET));
	if (argc > 6)
		return (printf("%sError: input must be less than 6 argument%s\n", LRED, RESET));
	if (ft_atoi(argv[1]) < 1)
		return (printf("%sError: number of philosophers must be at least 1%s\n", LRED, RESET));
	if (ft_atoi(argv[2]) <= 0)
		return (printf("%sError: time to die must be more than 0%s\n", LRED, RESET));
	if (ft_atoi(argv[3]) <= 0)
		return (printf("%sError: time to eat must be more than 0%s\n", LRED, RESET));
	if (ft_atoi(argv[4]) <= 0)
		return (printf("%sError: time_to_sleep must be more than 0%s\n", LRED, RESET));
	if (argv[4] && ft_atoi(argv[4]) <= 0)
		return (printf("%sError:  number of times each philosopher must eat should be more than 0%s\n", LRED, RESET));
	return (0);
}

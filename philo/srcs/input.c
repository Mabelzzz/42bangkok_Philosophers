
#include "philo.h"

int		check_input(int argc, char **argv);
void	get_input(int argc, char **argv, t_input *input);

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
	if (argc == 6 && argv[5] && ft_atoi(argv[5]) <= 0)
		return (printf("%sError:  number of times each philosopher must eat should be more than 0%s\n", LRED, RESET));
	return (0);
}

void	get_input(int argc, char **argv, t_input *input)
{
	input->start_time = get_time();
	input->num_philo = ft_atoi(argv[1]);
	input->time_to_eat = ft_atoi(argv[2]);
	input->time_to_die = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6 && argv[5])
		input->num_of_eat = ft_atoi(argv[5]);
}


#include "../include/philo.h"
# include <stdio.h>

int	main(int argc, char **argv)
{
	t_data data;

	if(check_input(argc, argv))
		return (1);
	get_input(argc, argv, &data.input);
	// if(get_input(argc, argv))


}

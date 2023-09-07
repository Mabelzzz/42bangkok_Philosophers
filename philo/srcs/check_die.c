#include "philo.h"

void	check_who_die(t_data *data, int tid)
{
	long long	now;

	// IS_DEAD = 0;
	// while (!IS_DEAD)
	// {
		now = current_time(data);
		if (now - PHILO[tid].last_meal > DIE)
		{
		// printf("tid [%d] cur = %lld last_meal = %lld = %lld > die %d\n", tid, now, PHILO[tid].last_meal, now - PHILO[tid].last_meal, DIE);
			// printf("hi2\n");
			IS_DEAD = 1;
			dead(data, tid);
		}
	// 	usleep(1);
	// }
}

int	check_die(t_data *data, int tid, int eat)
{
	long long		alive;
	int		i;
	long long	now;

	i = -1;

	now = current_time(data);
	if (eat == 1)
		alive = DIE * (PHILO[tid].eat_cnt + 1);
	else
		alive = DIE * PHILO[tid].eat_cnt;
	// printf("PHILO[tid].current = %lld > alive = %d\n", PHILO[tid].current, alive);
	if (now > alive)
		return (1);
	if (current_time(data) - PHILO[tid].last_meal > DIE)
		return (1);
			// dead(data, tid);
	if (now % DIE == 0)
	{
		// printf("now = %lld----------\n", now);
		while (++i < NUM_PHILO)
		{
			if (now / DIE > PHILO[i].eat_cnt)
				return (1);
		}
	}

	return (0);
}

void	*check_is_dead(void *args)
{
	int			id;
	long long	now;
	t_data 		*data;

	data = (t_data *)args;
	id = -1;
	// IS_DEAD = 0;
	while (!IS_DEAD)
	{
		id = -1;
		while (++id < NUM_PHILO)
		{
			now = current_time(data);
			if (now - PHILO[id].last_meal > DIE)
			{
			// printf("id [%d] cur = %lld last_meal = %lld = %lld > die %d\n", id, now, PHILO[id].last_meal, now - PHILO[id].last_meal, DIE);
				// printf("hi2\n");
				IS_DEAD = 1;
				dead(data, id);
			}
				// printf("hi3 now %lld / DIE %d = %lld  > PHILO[%d].eat_cnt %d\n", now, DIE, now / DIE, id, PHILO[id].eat_cnt);
			// if (now / DIE > PHILO[id].eat_cnt)
			// {
			// 	IS_DEAD = 1;
			// 	dead(data, id);
			// }
			// printf("eat_cnt %d < Num_eat %d\n", PHILO[id].eat_cnt, NUM_EAT);
			// if (NUM_EAT != -1 && (PHILO[id].eat_cnt < NUM_EAT ) && !IS_DEAD)
			// {
			// 	printf("hi\n");
			// 	IS_DEAD = 1;
			// 	// dead(data, i);
			// }
		}
		// usleep(1);
	}
	return (NULL);
}

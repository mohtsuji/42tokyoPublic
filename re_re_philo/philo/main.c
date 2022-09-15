/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:05:35 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/12/20 11:53:00 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

__attribute__((destructor))
static void destructor()
{
    system("leaks philo");
}

int	thinking(t_data *d)
{
	struct timeval	now;
	long long		time;

	if (gettimeofday(&now, NULL) == -1)
		return (put_error("error gettimeofday\n"));
	time = now.tv_sec * 1000 + now.tv_usec / 1000;
	if (pthread_mutex_lock(&(d->mutex->finish)) != 0)
		return (put_error("finish mutex lock error\n"));
	if (put_timestamp("is thinking", d, time) != 0)
		return (2);
	if (pthread_mutex_unlock(&(d->mutex->finish)) != 0)
		return (put_error("finish mutex unlock error\n"));
	return (0);
}

int	sleeping(t_data *d)
{
	struct timeval	now;
	long long		time;

	if (gettimeofday(&now, NULL) == -1)
		return (put_error("error gettimeofday\n"));
	time = now.tv_sec * 1000 + now.tv_usec / 1000;
	if (pthread_mutex_lock(&(d->mutex->finish)) != 0)
		return (put_error("finish mutex lock error\n"));
	if (put_timestamp("is sleeping", d, time) != 0)
		return (2);
	if (pthread_mutex_unlock(&(d->mutex->finish)) != 0)
		return (put_error("finish mutex unlock error\n"));
	if (measure_time(d->init->to_sleep, time) != 0)
		return (1);
	return (0);
}

int	eating(t_data *d)
{
	if (take_fork(d, d->r_fork) != 0)
		return (1);
	if (d->r_fork == d->l_fork)
		return (eat_philo_one(d));
	if (take_fork(d, d->l_fork) != 0)
		return (1);
	if (eat_start(d) != 0)
		return (1);
	if (drop_fork(d, d->r_fork) != 0)
		return (1);
	if (drop_fork(d, d->l_fork) != 0)
		return (1);
	return (0);
}

void	*p_unlock(t_data *d)
{
	pthread_mutex_unlock(&(d->mutex->finish));
	pthread_mutex_unlock(&(d->mutex->dead[d->my_num]));
	pthread_mutex_unlock(&(d->mutex->fork[d->r_fork]));
	pthread_mutex_unlock(&(d->mutex->fork[d->l_fork]));
	return (NULL);
}

void	*p_move(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (d->my_num % 2 != 0)
	{
		if (usleep(500) != 0)
			return (put_error_n("error usleep\n"));
	}
	while (1)
	{
		if (eating(d) != 0)
			return (p_unlock(d));
		if (sleeping(d) != 0)
			return (p_unlock(d));
		if (thinking(d) != 0)
			return (p_unlock(d));
	}
}

int	main(int argc, char **argv)
{
	t_data		*d;
	t_init		init;
	t_mutex		mutex;
	int			p_num;

	if (argc < 5 || 6 < argc)
		return (put_error("argc error\n"));
	p_num = ft_atoi(argv[1]);
	if (p_num < 1)
		return (put_error("p_num error\n"));
	if (data_malloc(&d, argv, &init, &mutex) != 0)
		return (all_free(d, &init, &mutex));
	if (thread_malloc(d, p_num) != 0)
	{
		destroy_mutex(&mutex, p_num);
		return (all_free(d, &init, &mutex));
	}
	destroy_mutex(&mutex, p_num);
	all_free(d, &init, &mutex);
	return (0);
}

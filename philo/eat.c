/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:41:17 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/12/20 12:08:59 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_philo_one(t_data *d)
{
	while (1)
	{
		if (d->init->finish == 1)
			return (1);
	}
	return (1);
}

int	eat_num_check(t_data *d)
{
	int	i;

	i = 0;
	if (d->init->must_eat == -1)
		return (0);
	while (i < d->init->p_num)
	{
		if (d->init->must_eat > d->init->eat_num[i])
			return (0);
		i++;
	}
	d->init->finish = 1;
	return (1);
}

int	eat_start(t_data *d)
{
	struct timeval	now;
	long long		time;

	if (pthread_mutex_lock(&(d->mutex->dead[d->my_num])) != 0)
		return (put_error("dead_mutex lock error\n"));
	if (gettimeofday(&now, NULL) == -1)
		return (put_error("error gettimeofday\n"));
	time = now.tv_sec * 1000 + now.tv_usec / 1000;
	d->init->init_die[d->my_num] = time;
	if (pthread_mutex_unlock(&(d->mutex->dead[d->my_num])) != 0)
		return (put_error("dead_mutex unlock error\n"));
	if (pthread_mutex_lock(&(d->mutex->finish)) != 0)
		return (put_error("finish_mutex lock error\n"));
	if (put_timestamp("is eating", d, time) != 0)
		return (2);
	d->init->eat_num[d->my_num] += 1;
	if (eat_num_check(d) != 0)
		return (2);
	if (pthread_mutex_unlock(&(d->mutex->finish)) != 0)
		return (put_error("finish_mutex unlock error\n"));
	if (measure_time(d->init->to_eat, time) != 0)
		return (1);
	return (0);
}

int	take_fork(t_data *d, int hand)
{
	struct timeval	now;
	long long		time;

	if (pthread_mutex_lock(&(d->mutex->fork[hand])) != 0)
		return (put_error("fork_mutex lock error\n"));
	if (gettimeofday(&now, NULL) == -1)
		return (put_error("error gettimeofday\n"));
	time = now.tv_sec * 1000 + now.tv_usec / 1000;
	if (pthread_mutex_lock(&(d->mutex->finish)) != 0)
		return (put_error("finish_mutex lock error\n"));
	if (put_timestamp("has taken a fork", d, time) != 0)
		return (2);
	if (pthread_mutex_unlock(&(d->mutex->finish)) != 0)
		return (put_error("finish_mutex unlock error\n"));
	d->init->fork[hand] = 1;
	return (0);
}

int	drop_fork(t_data *d, int hand)
{
	d->init->fork[hand] = 0;
	if (pthread_mutex_unlock(&(d->mutex->fork[hand])) != 0)
		return (put_error("fork_mutex unlock error\n"));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 23:02:17 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/12/20 11:20:28 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	died(t_data *d, long long time)
{
	if (pthread_mutex_lock(&(d->mutex->finish)) != 0)
		return (put_error("finish mutex lock error\n"));
	if (put_timestamp("died", d, time) != 0)
		return (2);
	d->init->finish = 1;
	if (pthread_mutex_unlock(&(d->mutex->finish)) != 0)
		return (put_error("finish mutex unlock error\n"));
	return (0);
}

int	dead_check(t_data *d)
{
	struct timeval	now;
	long long		time;

	if (gettimeofday(&now, NULL) == -1)
		return (put_error("error gettimeofday\n"));
	time = now.tv_sec * 1000 + now.tv_usec / 1000;
	if (time - d->init->init_die[d->my_num] >= d->init->to_die)
	{
		died(d, time);
		return (2);
	}
	return (0);
}

void	*m_unlock(t_data *d, char *message)
{
	if (message != NULL)
		printf("%s\n", message);
	pthread_mutex_unlock(&(d->mutex->finish));
	pthread_mutex_unlock(&(d->mutex->dead[d->my_num]));
	return (NULL);
}

void	*m_move(void *data)
{
	t_data			*d;

	d = (t_data *)data;
	while (1)
	{
		if (pthread_mutex_lock(&(d->mutex->finish)) != 0)
			return (m_unlock(d, "finish mutex lock error"));
		if (d->init->finish == 1)
			return (m_unlock(d, NULL));
		if (pthread_mutex_unlock(&(d->mutex->finish)) != 0)
			return (m_unlock(d, "finish mutex unlock error"));
		if (pthread_mutex_lock(&(d->mutex->dead[d->my_num])) != 0)
			return (m_unlock(d, "monitor_mutex lock error"));
		if (dead_check(d) != 0)
			return (m_unlock(d, NULL));
		if (pthread_mutex_unlock(&(d->mutex->dead[d->my_num])) != 0)
			return (m_unlock(d, "monitor_mutex unlock error"));
		if (usleep(500) != 0)
			return (m_unlock(d, "error usleep"));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:54:56 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/12/20 11:20:18 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(pthread_t *philo, pthread_t *monitor, t_data *d, int p_num)
{
	int	i;

	i = 0;
	while (i < p_num)
	{
		if (pthread_create(&(philo[i]), NULL, p_move, (void *)&(d[i])) != 0)
			return (put_error("pthread_create error\n"));
		if (pthread_create(&(monitor[i]), NULL, m_move, (void *)&(d[i])) != 0)
			return (put_error("pthread_create error\n"));
		i++;
	}
	return (0);
}

int	join_thread(pthread_t *philo, pthread_t *monitor, int p_num)
{
	int	i;

	i = 0;
	while (i < p_num)
	{
		if (pthread_join(philo[i], NULL) != 0)
			return (put_error("pthread_join error\n"));
		if (pthread_join(monitor[i], NULL) != 0)
			return (put_error("pthread_join error\n"));
		i++;
	}
	return (0);
}

int	thread_malloc(t_data *d, int p_num)
{
	pthread_t	*philo;
	pthread_t	*monitor;

	philo = (pthread_t *)malloc(sizeof(pthread_t) * p_num);
	monitor = (pthread_t *)malloc(sizeof(pthread_t) * p_num);
	if (philo == NULL || monitor == NULL)
		return (put_error("thread malloc error\n"));
	create_thread(philo, monitor, d, p_num);
	join_thread(philo, monitor, p_num);
	free(philo);
	free(monitor);
	return (0);
}

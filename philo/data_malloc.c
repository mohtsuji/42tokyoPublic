/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:05:05 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/12/20 12:00:17 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_one(t_data **d, t_init *init, t_mutex *mutex)
{
	(*d)[0].my_num = 0;
	(*d)[0].r_fork = 0;
	(*d)[0].l_fork = 0;
	(*d)[0].init = init;
	(*d)[0].mutex = mutex;
	return (0);
}

int	set_init_value(t_init *init, char **argv)
{
	init->p_num = ft_atoi(argv[1]);
	init->to_die = ft_atoi(argv[2]);
	init->to_eat = ft_atoi(argv[3]);
	init->to_sleep = ft_atoi(argv[4]);
	init->finish = 0;
	if (argv[5] != NULL)
	{
		init->must_eat = ft_atoi(argv[5]);
		if (init->must_eat <= 0)
			return (put_error("illegal argv\n"));
	}
	else
		init->must_eat = -1;
	if (init->to_die < 0 || init->to_eat < 0 || init->to_sleep < 0)
		return (put_error("illegal argv\n"));
	return (0);
}

int	set_init_malloc(t_init *init, int p_num)
{
	struct timeval	time;
	int				i;

	i = 0;
	if (gettimeofday(&time, NULL) == -1)
		return (put_error("set_now_time\n"));
	while (i < p_num)
	{
		init->init_die[i] = time.tv_sec * 1000 + time.tv_usec / 1000;
		init->eat_num[i] = 0;
		init->fork[i] = 0;
		i++;
	}
	return (0);
}

void	set_data(t_data **d, int p_num, t_init *init, t_mutex *mutex)
{
	int		i;

	(*d)[0].my_num = 0;
	(*d)[0].r_fork = 0;
	(*d)[0].l_fork = p_num - 1;
	(*d)[0].init = init;
	(*d)[0].mutex = mutex;
	i = 1;
	while (i < p_num)
	{
		(*d)[i].my_num = i;
		(*d)[i].r_fork = i;
		(*d)[i].l_fork = i - 1;
		(*d)[i].init = init;
		(*d)[i].mutex = mutex;
		i++;
	}
}

int	init_mutex(t_mutex *mutex, int p_num)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(mutex->finish), NULL) != 0)
		return (put_error("finish mutex_init error\n"));
	while (i < p_num)
	{
		if (pthread_mutex_init(&(mutex->fork[i]), NULL) != 0)
			return (put_error("fork mutex_init error\n"));
		if (pthread_mutex_init(&(mutex->dead[i]), NULL) != 0)
			return (put_error("dead mutex_init error\n"));
		i++;
	}
	return (0);
}

int	data_malloc(t_data **d, char **argv, t_init *init, t_mutex *mutex)
{
	int	p_num;

	p_num = ft_atoi(argv[1]);
	*d = (t_data *)malloc(sizeof(t_data) * p_num);
	init->init_die = (long long *)malloc(sizeof(long long) * p_num);
	init->eat_num = (int *)malloc(sizeof(int) * p_num);
	init->fork = (int *)malloc(sizeof(int) * p_num);
	mutex->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * p_num);
	mutex->dead = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * p_num);
	if (*d == NULL || init->init_die == NULL || init->eat_num == NULL || \
		init->fork == NULL || mutex->fork == NULL || mutex->dead == NULL)
		return (put_error("malloc error\n"));
	if (set_init_value(init, argv) != 0)
		return (1);
	if (set_init_malloc(init, p_num) != 0)
		return (1);
	if (init_mutex(mutex, p_num) != 0)
		return (1);
	if (p_num == 1)
		return (philo_one(d, init, mutex));
	set_data(d, p_num, init, mutex);
	return (0);
}

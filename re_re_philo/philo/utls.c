/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:09:59 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/12/20 10:39:35 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_timestamp(char *message, t_data *d, long long time)
{
	if (d->init->finish == 1)
		return (2);
	printf("%lld %d %s\n", time, d->my_num + 1, message);
	return (0);
}

int	measure_time(int limit, long long start)
{
	struct timeval	time;
	long long		now;

	while (1)
	{
		if (gettimeofday(&time, NULL) == -1)
			return (put_error("error gettimeofday\n"));
		now = time.tv_sec * 1000 + time.tv_usec / 1000;
		if (now - start > limit)
			break ;
		if (usleep(500) != 0)
			return (put_error("error usleep\n"));
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	const char	*s;
	long		ans;

	s = str;
	ans = 0;
	if (*s == '-')
		return (-1);
	if (*s < '0' || *s > '9')
		return (-1);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (-1);
		ans = ans * 10 + (*s - '0');
		if (ans > 2147483647)
			return (-1);
		++s;
	}
	return ((int)ans);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL || fd < 0)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

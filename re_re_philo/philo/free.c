/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:45:43 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/12/20 11:40:29 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_mutex *mutex, int p_num)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&(mutex->finish)) != 0)
		printf("error finish mutex_destroy\n");
	while (i < p_num)
	{
		if (pthread_mutex_destroy(&(mutex->fork[i])) != 0)
			printf("error fork mutex_destroy\n");
		if (pthread_mutex_destroy(&(mutex->dead[i])) != 0)
			printf("error dead mutex_destroy\n");
		i++;
	}
	return ;
}

int	all_free(t_data *d, t_init *init, t_mutex *mutex)
{
	free(mutex->fork);
	free(mutex->dead);
	free(init->init_die);
	free(init->eat_num);
	free(init->fork);
	free(d);
	return (1);
}

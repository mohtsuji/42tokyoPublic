/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:18:57 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/12/20 11:59:53 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_mutex
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*dead;
	pthread_mutex_t	finish;
}					t_mutex;

typedef struct s_init
{
	int			to_eat;
	int			to_sleep;
	int			to_die;
	int			must_eat;
	int			finish;
	int			p_num;
	int			*eat_num;
	int			*fork;
	long long	*init_die;
}				t_init;

typedef struct s_data
{
	int			my_num;
	int			r_fork;
	int			l_fork;
	t_init		*init;
	t_mutex		*mutex;
}				t_data;

void	ft_putstr_fd(char *s, int fd);
int		put_error(char *message);
int		ft_atoi(const char *str);
int		data_malloc(t_data **d, char **argv, t_init *init, t_mutex *mutex);
int		data_thread_free(t_data *d);
int		thread_malloc(t_data *d, int p_num);
void	*p_move(void *data);
void	destroy_mutex(t_mutex *mutexi, int p_num);
int		measure_time(int limit, long long start);
int		put_timestamp(char *message, t_data *d, long long time);
int		drop_fork(t_data *d, int hand);
int		take_fork(t_data *d, int hand);
int		eat_start(t_data *d);
void	*put_error_n(char *message);
void	*m_move(void *data);
int		eat_philo_one(t_data *d);
int		all_free(t_data *d, t_init *init, t_mutex *mutex);

#endif

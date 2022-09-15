/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:26:31 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/12 20:59:47 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <libc.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_bit
{
	char	msg;
	int		size;
	int		end_check;
	int		client_pid;
	int		initial_signal;
	int		finish;
}				t_bit;

int		ft_atoi(char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
void	error_msg(char *str);
void	send_signal(pid_t pid, char position, char bit);

#endif

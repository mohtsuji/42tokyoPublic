/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:26:31 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/12 23:14:31 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit	g_bit;

void	put_bit1(int signm)
{
	(void)signm;
	g_bit.msg |= (1 << g_bit.size);
	g_bit.size++;
	if (g_bit.size == 8)
	{
		write(1, &(g_bit.msg), 1);
		g_bit.size = 0;
	}
}

void	put_bit0(int signm)
{
	(void)signm;
	g_bit.msg &= ~(1 << g_bit.size);
	g_bit.size++;
	if (g_bit.size == 8)
	{
		write(1, &(g_bit.msg), 1);
		g_bit.size = 0;
	}
}

void	init_set(struct sigaction *act1, struct sigaction *act0)
{
	act1->sa_handler = put_bit1;
	act0->sa_handler = put_bit0;
	act1->sa_flags = 0;
	act0->sa_flags = 0;
	if (sigemptyset(&act1->sa_mask) != 0 || \
		sigemptyset(&act0->sa_mask) != 0)
		error_msg("sigemptyset error\n");
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act1;
	struct sigaction	act0;

	pid = getpid();
	ft_putnbr_fd((int)pid, 1);
	ft_putstr_fd("\n", 1);
	init_set(&act1, &act0);
	g_bit.size = 0;
	while (1)
	{
		if (sigaction(SIGUSR1, &act1, NULL) != 0)
			error_msg("sigaction error\n");
		if (sigaction(SIGUSR2, &act0, NULL) != 0)
			error_msg("sigaction error\n");
	}
	return (0);
}

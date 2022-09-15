/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:26:31 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/11/25 14:50:23 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_bit	g_bit;

void	end_or_putchar(pid_t client_pid)
{
	//最後にここに入る。1が8回続いたら終了の合図でここに入る
	if (g_bit.end_check == 8 && g_bit.initial_signal == 1)
	{
		if (kill(client_pid, SIGUSR1) == -1)
			error_msg("put_bit1 kill error\n");
		g_bit.size = 0;
		g_bit.finish = 0;
	}
	//2番めにここに入る。文字列を受け取る
	else if (g_bit.size == 8 && g_bit.initial_signal == 1)
	{
		write(1, &(g_bit.msg), 1);
		g_bit.size = 0;
	}
}

void	put_bit1(int signm)
{
	pid_t	client_pid;

//	printf("signum1=%d\n", signm);
	(void)signm;
	client_pid = (pid_t)g_bit.client_pid;
	if (g_bit.initial_signal == 1)
		g_bit.msg |= (1 << g_bit.size);
	else
		g_bit.client_pid |= (1 << g_bit.size);
	g_bit.size++;
	g_bit.end_check++;
	if (g_bit.initial_signal == 1)
		end_or_putchar(client_pid);
	//まず最初にここに入るはず。clientのpidを受け取る
	if (g_bit.size == 32)
	{
		g_bit.initial_signal = 1;
		g_bit.size = 0;
		g_bit.finish = 1;
	}
}

void	put_bit0(int signm)
{
	(void)signm;
//	printf("signum0=%d\n", signm);
	if (g_bit.initial_signal == 1)
		g_bit.msg &= ~(1 << g_bit.size);
	else
		g_bit.client_pid &= ~(1 << g_bit.size);
	g_bit.size++;
	g_bit.end_check = 0;
	//2番めにここに入る。文字列を受け取る
	if (g_bit.size == 8 && g_bit.initial_signal == 1)
	{
		write(1, &(g_bit.msg), 1);
		g_bit.size = 0;
	}
	//まず最初にここに入るはず。clientのpidを受け取る
	if (g_bit.size == 32)
	{
		g_bit.initial_signal = 1;
		g_bit.size = 0;
		g_bit.finish = 1;
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
	g_bit.end_check = 0;
	g_bit.finish = 0;
	while (1)
	{
		if (g_bit.finish == 0)
			g_bit.initial_signal = 0;
		//SIGUSR1にシグナルが来た＝バイナリ1，2にシグナルが来た＝バイナリ0
		if (sigaction(SIGUSR1, &act1, NULL) != 0)
			error_msg("sigaction error\n");
		if (sigaction(SIGUSR2, &act0, NULL) != 0)
			error_msg("sigaction error\n");
	}
	return (0);
}

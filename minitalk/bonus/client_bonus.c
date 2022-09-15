/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:30:37 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/13 11:24:44 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char(pid_t pid, char *str)
{
	int	len;
	int	bit;
	int	i;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		bit = 0;
		while (bit < 8)
		{
			send_signal(pid, str[i], bit);
			if (usleep(200) == -1)
				error_msg("usleep error\n");
			bit++;
		}
		i++;
	}
}

void	send_finish(pid_t server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (kill(server_pid, SIGUSR1) == -1)
			error_msg("send_finish kill error\n");
		usleep(20);
		bit++;
	}
}

void	send_pid(pid_t server_pid, pid_t client_pid)
{
	int	bit;
	int	pid;

	bit = 0;
	pid = (int)client_pid;
	while (bit < 32)
	{
		if (pid & (1 << bit))
		{
			if (kill(server_pid, SIGUSR1) == -1)
				error_msg("send_pid USR1 kill error\n");
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				error_msg("send_pid USR2 kill error\n");
		}
		if (usleep(500) == -1)
			error_msg("usleep error\n");
		bit++;
	}
}

void	receive_finish(int signum)
{
	(void)signum;
	ft_putstr_fd("every signal received\n", 1);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	pid_t				client_pid;
	struct sigaction	act;

	if (argc != 3)
		error_msg("argc==3 error\n");
	//終了のシグナルを受け取るためにhandlerを設定
	act.sa_handler = receive_finish;
	act.sa_flags = 0;
	if (sigemptyset(&act.sa_mask) != 0)
		error_msg("sigemptyset error\n");
	server_pid = (pid_t)ft_atoi(argv[1]);
	//server_pidに-1を入れられるとすべてのプロセスが終了するので除外する
	if (server_pid == -1)
		error_msg("No!! PID == -1\n");
	client_pid = getpid();
	//終了シグナルを送信してもらうために，自分のPIDをserverに送る
	send_pid(server_pid, client_pid);
	//文字列を送信する
	send_char(server_pid, argv[2]);
	if (sigaction(SIGUSR1, &act, NULL) != 0)
		error_msg("sigaction error\n");
	//すべての文字列を送信したことをserverに教える
	send_finish(server_pid);
}

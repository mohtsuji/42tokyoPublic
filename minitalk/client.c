/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:30:37 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/12 23:10:45 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int argc, char **argv)
{
	pid_t				server_pid;

	if (argc != 3)
		error_msg("argc==3 error\n");
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid == -1)
		error_msg("No!! PID == -1\n");
	send_char(server_pid, argv[2]);
}

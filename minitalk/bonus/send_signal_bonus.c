/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:40:27 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/12 22:11:36 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_signal(pid_t pid, char position, char bit)
{
	if (position & (1 << bit))
	{
		if (kill(pid, SIGUSR1) == -1)
			error_msg("send USR1 kill error\n");
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			error_msg("send USR2 kill error\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:27:06 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/30 15:10:53 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_info *info)
{
	if (info->worldmap[info->posy][info->posx + 1] == '0' || \
		info->worldmap[info->posy][info->posx + 1] == 'C')
	{
		if (info->worldmap[info->posy][info->posx + 1] == 'C')
			info->c_num--;
		info->worldmap[info->posy][info->posx] = '0';
		info->posx += 1;
		info->worldmap[info->posy][info->posx] = 'P';
		info->move_num++;
		printf("current move number : %d\n", info->move_num);
	}
	else if (info->worldmap[info->posy][info->posx + 1] == 'E' && \
			info->c_num == 0)
		exit(0);
}

void	move_left(t_info *info)
{
	if (info->worldmap[info->posy][info->posx - 1] == '0' || \
		info->worldmap[info->posy][info->posx - 1] == 'C')
	{
		if (info->worldmap[info->posy][info->posx - 1] == 'C')
			info->c_num--;
		info->worldmap[info->posy][info->posx] = '0';
		info->posx -= 1;
		info->worldmap[info->posy][info->posx] = 'P';
		info->move_num++;
		printf("current move number : %d\n", info->move_num);
	}
	else if (info->worldmap[info->posy][info->posx - 1] == 'E' && \
			info->c_num == 0)
		exit(0);
}

void	move_front(t_info *info)
{
	if (info->worldmap[info->posy - 1][info->posx] == '0' || \
		info->worldmap[info->posy - 1][info->posx] == 'C')
	{
		if (info->worldmap[info->posy - 1][info->posx] == 'C')
			info->c_num--;
		info->worldmap[info->posy][info->posx] = '0';
		info->posy -= 1;
		info->worldmap[info->posy][info->posx] = 'P';
		info->move_num++;
		printf("current move number : %d\n", info->move_num);
	}
	else if (info->worldmap[info->posy - 1][info->posx] == 'E' && \
			info->c_num == 0)
		exit(0);
}

void	move_back(t_info *info)
{
	if (info->worldmap[info->posy + 1][info->posx] == '0' || \
		info->worldmap[info->posy + 1][info->posx] == 'C')
	{
		if (info->worldmap[info->posy + 1][info->posx] == 'C')
			info->c_num--;
		info->worldmap[info->posy][info->posx] = '0';
		info->posy += 1;
		info->worldmap[info->posy][info->posx] = 'P';
		info->move_num++;
		printf("current move number : %d\n", info->move_num);
	}
	else if (info->worldmap[info->posy + 1][info->posx] == 'E' && \
			info->c_num == 0)
		exit(0);
}

int	close_game(t_info *info)
{
	(void)info;
	exit(0);
}

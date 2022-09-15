/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:10:43 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/01/31 01:44:55 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_info *info)
{
	if ((info->worldmap[(int)(info->posx + info->px *
		info->mspeed)][(int)(info->posy)]) == '0')
		info->posx += info->px * info->mspeed;
	if ((info->worldmap[(int)(info->posx)][(int)(info->posy +
		info->py * info->mspeed)]) == '0')
		info->posy += info->py * info->mspeed;
}

void	move_left(t_info *info)
{
	if ((info->worldmap[(int)(info->posx - info->px *
		info->mspeed)][(int)(info->posy)]) == '0')
		info->posx -= info->px * info->mspeed;
	if ((info->worldmap[(int)(info->posx)][(int)(info->posy -
		info->py * info->mspeed)]) == '0')
		info->posy -= info->py * info->mspeed;
}

void	move_front(t_info *info)
{
	if ((info->worldmap[(int)(info->posx + info->dirx *
		info->mspeed)][(int)(info->posy)]) == '0')
		info->posx += info->dirx * info->mspeed;
	if ((info->worldmap[(int)(info->posx)][(int)(info->posy +
		info->diry * info->mspeed)]) == '0')
		info->posy += info->diry * info->mspeed;
}

void	move_back(t_info *info)
{
	if ((info->worldmap[(int)(info->posx - info->dirx *
		info->mspeed)][(int)(info->posy)]) == '0')
		info->posx -= info->dirx * info->mspeed;
	if ((info->worldmap[(int)(info->posx)][(int)(info->posy -
		info->diry * info->mspeed)]) == '0')
		info->posy -= info->diry * info->mspeed;
}

int		key_press(int key, t_info *info)
{
	if (key == K_W)
		move_front(info);
	if (key == K_S)
		move_back(info);
	if (key == K_D)
		move_right(info);
	if (key == K_A)
		move_left(info);
	if (key == K_L)
		rotate_left(info);
	if (key == K_R)
		rotate_right(info);
	if (key == K_ESC)
		exit(0);
	return (0);
}

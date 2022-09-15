/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 21:26:41 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/26 18:46:40 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		move_vertical(t_params *param)
{
	const double speed = 0.2;

	if (param->player->fwd)
	{
		if (param->info->map
		[(int)(param->player->px + param->player->dx * speed)]
		[(int)(param->player->py)] == '0')
			param->player->px += param->player->dx * speed * 0.5;
		if (param->info->map
		[(int)(param->player->px)]
		[(int)(param->player->py + param->player->dy * speed)] == '0')
			param->player->py += param->player->dy * speed * 0.5;
	}
	else if (param->player->back)
	{
		if (param->info->map
		[(int)(param->player->px - param->player->dx * speed)]
		[(int)(param->player->py)] == '0')
			param->player->px -= param->player->dx * speed * 0.5;
		if (param->info->map
		[(int)(param->player->px)]
		[(int)(param->player->py - param->player->dy * speed)] == '0')
			param->player->py -= param->player->dy * speed * 0.5;
	}
	return (1);
}

static int		move_horizontal(t_params *param)
{
	const double speed = 0.2;

	if (param->player->right)
	{
		if (param->info->map
		[(int)(param->player->px + param->player->plx * speed)]
		[(int)(param->player->py)] == '0')
			param->player->px += param->player->plx * speed * 0.5;
		if (param->info->map
		[(int)(param->player->px)]
		[(int)(param->player->py + param->player->ply * speed)] == '0')
			param->player->py += param->player->ply * speed * 0.5;
	}
	else if (param->player->left)
	{
		if (param->info->map
		[(int)(param->player->px - param->player->plx * speed)]
		[(int)(param->player->py)] == '0')
			param->player->px -= param->player->plx * speed * 0.5;
		if (param->info->map
		[(int)(param->player->px)]
		[(int)(param->player->py - param->player->ply * speed)] == '0')
			param->player->py -= param->player->ply * speed * 0.5;
	}
	return (1);
}

static int		rot_left(t_params *param)
{
	const double	rot = 0.05;
	double			olddx;
	double			oldpx;
	t_player		*player;

	player = param->player;
	olddx = player->dx;
	oldpx = player->plx;
	param->player->dx = player->dx * cos(rot) - player->dy * sin(rot);
	param->player->dy = olddx * sin(rot) + player->dy * cos(rot);
	param->player->plx = player->plx * cos(rot)
	- player->ply * sin(rot);
	param->player->ply = oldpx * sin(rot) + player->ply * cos(rot);
	return (1);
}

static int		rot_right(t_params *param)
{
	const double	rot = 0.05;
	double			olddx;
	double			oldpx;
	t_player		*player;

	player = param->player;
	olddx = player->dx;
	oldpx = player->plx;
	param->player->dx = player->dx * cos(-rot) - player->dy * sin(-rot);
	param->player->dy = olddx * sin(-rot) + player->dy * cos(-rot);
	param->player->plx = player->plx * cos(-rot)
	- player->ply * sin(-rot);
	param->player->ply = oldpx * sin(-rot) + player->ply * cos(-rot);
	return (1);
}

int				move_player(t_params *param)
{
	if (param->player->fwd || param->player->back)
		return (move_vertical(param));
	if (param->player->right || param->player->left)
		return (move_horizontal(param));
	if (param->player->rot_left)
		return (rot_left(param));
	if (param->player->rot_right)
		return (rot_right(param));
	return (0);
}

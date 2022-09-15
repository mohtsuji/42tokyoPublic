/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:26:16 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 00:11:05 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ca_direction(t_info *info)
{
	info->ct.mapx = (int)info->posx;
	info->ct.mapy = (int)info->posy;
	if (info->ct.rdiry == 0)
		info->ct.dx = 0;
	else if (info->ct.rdirx == 0)
		info->ct.dx = 1;
	else
		info->ct.dx = fabs(1 / info->ct.rdirx);
	if (info->ct.rdirx == 0)
		info->ct.dy = 0;
	else if (info->ct.rdiry == 0)
		info->ct.dy = 1;
	else
		info->ct.dy = fabs(1 / info->ct.rdiry);
}

void	ca_direction2(t_info *info)
{
	if (info->ct.rdirx < 0)
	{
		info->ct.stepx = -1;
		info->ct.sdistx = (info->posx - info->ct.mapx) * info->ct.dx;
	}
	else
	{
		info->ct.stepx = 1;
		info->ct.sdistx = (info->ct.mapx + 1.0 - info->posx) * info->ct.dx;
	}
	if (info->ct.rdiry < 0)
	{
		info->ct.stepy = -1;
		info->ct.sdisty = (info->posy - info->ct.mapy) * info->ct.dy;
	}
	else
	{
		info->ct.stepy = 1;
		info->ct.sdisty = (info->ct.mapy + 1.0 - info->posy) * info->ct.dy;
	}
}

void	hit_dir(t_info *info, int *side)
{
	info->hit = 0;
	while (info->hit == 0)
	{
		if (info->ct.sdistx < info->ct.sdisty)
		{
			info->ct.sdistx += info->ct.dx;
			info->ct.mapx += info->ct.stepx;
			*side = 0;
		}
		else
		{
			info->ct.sdisty += info->ct.dy;
			info->ct.mapy += info->ct.stepy;
			*side = 1;
		}
		if (info->worldmap[info->ct.mapx][info->ct.mapy] == '1')
			info->hit = 1;
	}
	if (*side == 0)
		info->ct.pwdist = (info->ct.mapx - info->posx +
		(1 - info->ct.stepx) / 2) / info->ct.rdirx;
	else
		info->ct.pwdist = (info->ct.mapy - info->posy
		+ (1 - info->ct.stepy) / 2) / info->ct.rdiry;
}

void	draw_ready(t_info *info, int *side, int *texn)
{
	info->ct.dstart = -info->ct.lheight / 2 + info->height / 2;
	if (info->ct.dstart < 0)
		info->ct.dstart = 0;
	info->ct.dend = info->ct.lheight / 2 + info->height / 2;
	if (info->ct.dend >= info->height)
		info->ct.dend = info->height - 1;
	if (*side == 1 && info->ct.rdiry > 0)
		*texn = 3;
	if (*side == 1 && info->ct.rdiry <= 0)
		*texn = 2;
	if (*side == 0 && info->ct.rdirx <= 0)
		*texn = 0;
	if (*side == 0 && info->ct.rdirx > 0)
		*texn = 1;
	if (*side == 0)
		info->ct.wallx = info->posy + info->ct.pwdist * info->ct.rdiry;
	else
		info->ct.wallx = info->posx + info->ct.pwdist * info->ct.rdirx;
	info->ct.wallx -= floor(info->ct.wallx);
}

void	calc(t_info *info)
{
	int		side;
	int		x;

	x = 0;
	while (x < info->width)
	{
		info->ct.cx = 2 * x / (double)info->width - 1;
		info->ct.rdirx = info->dirx + info->px * info->ct.cx;
		info->ct.rdiry = info->diry + info->py * info->ct.cx;
		ca_direction(info);
		ca_direction2(info);
		hit_dir(info, &side);
		info->ct.lheight = (int)(info->height / info->ct.pwdist);
		draw_ready(info, &side, &(info->texn));
		info->ct.texx = (int)(info->ct.wallx * (double)TEXWIDTH);
		if (side == 0 && info->ct.rdirx > 0)
			info->ct.texx = TEXWIDTH - info->ct.texx - 1;
		if (side == 1 && info->ct.rdiry < 0)
			info->ct.texx = TEXWIDTH - info->ct.texx - 1;
		info->step = 1.0 * TEXHEIGHT / info->ct.lheight;
		info->ct.texpos = (info->ct.dstart - info->height /
		2 + info->ct.lheight / 2) * info->step;
		set_color(info, &x, &(info->texn), &side);
		info->zbuf[x++] = info->ct.pwdist;
	}
}

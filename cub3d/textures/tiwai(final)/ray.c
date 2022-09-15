/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:29:03 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/26 16:34:55 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		set_camera(t_params *param)
{
	param->ray->cx = 2 * param->ray->x / (double)(param->mlx->w) - 1;
	param->ray->rdx = param->player->dx
		+ param->player->plx * param->ray->cx;
	param->ray->rdy = param->player->dy
		+ param->player->ply * param->ray->cx;
	param->ray->mx = (int)(param->player->px);
	param->ray->my = (int)(param->player->py);
	if (param->ray->rdy == 0)
		param->ray->ddx = 0;
	else if (param->ray->rdx == 0)
		param->ray->ddx = 1;
	else
		param->ray->ddx = fabs(1 / param->ray->rdx);
	if (param->ray->rdx == 0)
		param->ray->ddy = 0;
	else if (param->ray->rdy == 0)
		param->ray->ddy = 1;
	else
		param->ray->ddy = fabs(1 / param->ray->rdy);
	param->ray->hit = 0;
}

static void		set_raydir(t_params *param)
{
	if (param->ray->rdx < 0)
	{
		param->ray->stx = -1;
		param->ray->sdx = (param->player->px
			- param->ray->mx) * param->ray->ddx;
	}
	else
	{
		param->ray->stx = 1;
		param->ray->sdx = (param->ray->mx + 1.0
			- param->player->px) * param->ray->ddx;
	}
	if (param->ray->rdy < 0)
	{
		param->ray->sty = -1;
		param->ray->sdy = (param->player->py
			- param->ray->my) * param->ray->ddy;
	}
	else
	{
		param->ray->sty = 1;
		param->ray->sdy = (param->ray->my + 1.0
			- param->player->py) * param->ray->ddy;
	}
}

static void		search_hit(t_params *param)
{
	while (param->ray->hit == 0)
	{
		if (param->ray->sdx < param->ray->sdy)
		{
			param->ray->sdx += param->ray->ddx;
			param->ray->mx += param->ray->stx;
			param->ray->side = 0;
		}
		else
		{
			param->ray->sdy += param->ray->ddy;
			param->ray->my += param->ray->sty;
			param->ray->side = 1;
		}
		if (param->info->map[param->ray->mx][param->ray->my] == '1')
			param->ray->hit = 1;
	}
	if (param->ray->side == 0)
		param->ray->pdist = (param->ray->mx - param->player->px
			+ (1 - param->ray->stx) / 2) / (param->ray->rdx);
	else
		param->ray->pdist = (param->ray->my - param->player->py
			+ (1 - param->ray->sty) / 2) / (param->ray->rdy);
	param->zbuffer[param->ray->x] = param->ray->pdist;
}

static void		tex_param(t_params *param)
{
	param->ray->lh = (int)(param->mlx->h / param->ray->pdist);
	param->ray->dstart = -1 * param->ray->lh / 2 + param->mlx->h / 2;
	if (param->ray->dstart < 0)
		param->ray->dstart = 0;
	param->ray->dend = param->ray->lh / 2 + param->mlx->h / 2;
	if (param->ray->dend >= param->mlx->h)
		param->ray->dend = param->mlx->h - 1;
	if (param->ray->side == 0)
	{
		if (param->ray->rdx < 0)
			param->ray->tex_num = 0;
		else if (param->ray->rdx >= 0)
			param->ray->tex_num = 1;
	}
	else
	{
		if (param->ray->rdy < 0)
			param->ray->tex_num = 2;
		else if (param->ray->rdy >= 0)
			param->ray->tex_num = 3;
	}
}

int				raycast(t_params *param)
{
	t_ray ray;

	param->ray = &ray;
	param->ray->x = 0;
	while (param->ray->x < param->mlx->w)
	{
		set_camera(param);
		set_raydir(param);
		search_hit(param);
		tex_param(param);
		tex_draw_prep(param);
		draw_ceil(param);
		draw_texture(param);
		draw_floor(param);
		param->ray->x++;
	}
	return (0);
}

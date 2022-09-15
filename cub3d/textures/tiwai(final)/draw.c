/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:11:08 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/30 20:47:21 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		tex_draw_prep(t_params *p)
{
	if (p->ray->side == 0)
		p->ray->wallx = p->player->py
		+ p->ray->pdist * p->ray->rdy;
	else
		p->ray->wallx = p->player->px
		+ p->ray->pdist * p->ray->rdx;
	p->ray->wallx -= floor((p->ray->wallx));
	p->ray->tex_x = (int)(p->ray->wallx * (double)(p->tw[p->ray->tex_num]));
	if (p->ray->side == 0 && p->ray->rdx > 0)
		p->ray->tex_x = p->tw[p->ray->tex_num] - p->ray->tex_x - 1;
	if (p->ray->side == 1 && p->ray->rdy < 0)
		p->ray->tex_x = p->tw[p->ray->tex_num] - p->ray->tex_x - 1;
	p->ray->step = 1.0 * p->th[p->ray->tex_num] / p->ray->lh;
	p->ray->tex_pos = (p->ray->dstart - p->mlx->h / 2
	+ p->ray->lh / 2) * p->ray->step;
}

void		draw_ceil(t_params *p)
{
	unsigned char	*s;
	unsigned int	c;

	p->ray->y = 0;
	while (p->ray->y < p->ray->dstart)
	{
		c = (unsigned int)p->info->ceilling_color;
		s = (unsigned char *)&c;
		p->mlx->d_img[p->ray->y * p->mlx->sl \
		+ p->ray->x * p->mlx->bit / 8] = s[0];
		p->mlx->d_img[p->ray->y * p->mlx->sl \
		+ p->ray->x * p->mlx->bit / 8 + 1] = s[1];
		p->mlx->d_img[p->ray->y * p->mlx->sl \
		+ p->ray->x * p->mlx->bit / 8 + 2] = s[2];
		p->ray->y++;
	}
}

void		draw_texture(t_params *p)
{
	t_color col;

	p->ray->y = p->ray->dstart;
	while (p->ray->y < p->ray->dend)
	{
		p->ray->tex_y = (int)p->ray->tex_pos;
		p->ray->tex_pos += p->ray->step;
		col.dst = \
		mlx_get_data_addr(p->tex[p->ray->tex_num], &col.bp, &col.sl, &col.end);
		col.color = *(unsigned int *)(col.dst + p->ray->tex_y * col.sl \
		+ p->ray->tex_x * col.bp / 8);
		col.src = (unsigned char*)&col.color;
		p->mlx->d_img[p->ray->y * p->mlx->sl \
		+ p->ray->x * p->mlx->bit / 8] = col.src[0];
		p->mlx->d_img[p->ray->y * p->mlx->sl \
		+ p->ray->x * p->mlx->bit / 8 + 1] = col.src[1];
		p->mlx->d_img[p->ray->y * p->mlx->sl \
		+ p->ray->x * p->mlx->bit / 8 + 2] = col.src[2];
		p->ray->y++;
	}
}

void		draw_floor(t_params *p)
{
	unsigned char	*s;
	unsigned int	c;

	p->ray->y = p->ray->dend;
	while (p->ray->y < p->mlx->h)
	{
		c = (unsigned int)p->info->floor_color;
		s = (unsigned char *)&c;
		p->mlx->d_img[p->ray->y * p->mlx->sl \
		+ p->ray->x * p->mlx->bit / 8] = s[0];
		p->mlx->d_img[p->ray->y * p->mlx->sl \
		+ p->ray->x * p->mlx->bit / 8 + 1] = s[1];
		p->mlx->d_img[p->ray->y * p->mlx->sl \
		+ p->ray->x * p->mlx->bit / 8 + 2] = s[2];
		p->ray->y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 01:49:39 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 00:43:30 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize(t_image *image, t_sprite *sprite)
{
	(*image).height = 0;
	(*image).width = 0;
	(*image).color = 0;
	(*sprite).x = 0;
	(*sprite).y = 0;
}

void	info_initia2(t_info *info)
{
	info->mspeed = 0.05;
	info->rspeed = 0.05;
	info->flag = 0;
	info->flag_pos = 0;
	info->worldmap = 0;
	info->numsprites = 0;
	info->sprite = 0;
	info->sorder = 0;
	info->sdis = 0;
	info->fcolor = 0;
	info->ccolor = 0;
	info->save = 0;
	info->image = 0;
	info->hit = 0;
	info->step = 0;
	info->texn = 0;
	info->stripe = 0;
	info->d = 0;
	info->color = 0;
}

void	init_img(t_img *img)
{
	img->ptr = 0;
	img->img = 0;
	img->data = 0;
	img->size_l = 0;
	img->bpp = 0;
	img->endian = 0;
	img->img_width = 0;
	img->img_height = 0;
}

void	info_initialize(t_info *info)
{
	t_image		image;
	t_sprite	sprite;

	info->posx = 0;
	info->posy = 0;
	info->dirx = 0;
	info->diry = 0;
	info->px = 0;
	info->py = 0;
	info->width = 0;
	info->height = 0;
	info->mlx = 0;
	info->win = 0;
	info->buf = 0;
	info->zbuf = 0;
	info->texture = 0;
	info_initia2(info);
	initialize(&image, &sprite);
	info->image = &image;
	info->sprite = &sprite;
	init_img(&(info->img));
}

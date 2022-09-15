/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:09:33 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 00:12:06 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprite(t_info *info, int *i)
{
	info->cs.spritex = info->sprite[info->sorder[*i]].x - info->posx;
	info->cs.spritey = info->sprite[info->sorder[*i]].y - info->posy;
	info->cs.invdet = 1.0 / (info->px * info->diry - info->dirx * info->py);
	info->cs.tx = info->cs.invdet * (info->diry *
	info->cs.spritex - info->dirx * info->cs.spritey);
	info->cs.ty = info->cs.invdet * (-info->py *
	info->cs.spritex + info->px * info->cs.spritey);
	info->cs.sx = (int)((info->width / 2) * (1 + info->cs.tx / info->cs.ty));
	info->cs.ms = (int)(VMOVE / info->cs.ty);
	info->cs.sh = (int)fabs((info->height / info->cs.ty) / VDIV);
	info->cs.dstarty = -info->cs.sh / 2 + info->height / 2 + info->cs.ms;
	if (info->cs.dstarty < 0)
		info->cs.dstarty = 0;
	info->cs.dendy = info->cs.sh / 2 + info->height / 2 + info->cs.ms;
	if (info->cs.dendy >= info->height)
		info->cs.dendy = info->height - 1;
	info->cs.swidth = (int)fabs((info->height / info->cs.ty) / UDIV);
	info->cs.dstartx = -info->cs.swidth / 2 + info->cs.sx;
	if (info->cs.dstartx < 0)
		info->cs.dstartx = 0;
	info->cs.dendx = info->cs.swidth / 2 + info->cs.sx;
	if (info->cs.dendx >= info->width)
		info->cs.dendx = info->width - 1;
}

void	sprite_color(t_info *info)
{
	int		y;

	info->stripe = info->cs.dstartx;
	while (info->stripe < info->cs.dendx)
	{
		info->cs.texx = (int)((256 * (info->stripe - (-info->cs.swidth / 2 +
		info->cs.sx)) * TEXWIDTH / info->cs.swidth) / 256);
		if (info->cs.ty > 0 && info->stripe > 0 && info->stripe < info->width &&
		info->cs.ty < info->zbuf[info->stripe])
		{
			y = info->cs.dstarty;
			while (y < info->cs.dendy)
			{
				info->d = (y - info->cs.ms) * 256 - info->height *
				128 + info->cs.sh * 128;
				info->cs.texy = ((info->d * TEXHEIGHT) / info->cs.sh) / 256;
				info->color = info->texture[4][TEXWIDTH *
				info->cs.texy + info->cs.texx];
				if ((info->color & 0x00FFFFFF) != 0)
					info->buf[y][info->stripe] = info->color;
				y++;
			}
		}
		info->stripe++;
	}
}

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	tmp.first = 0;
	tmp.second = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;
	int		i;

	i = 0;
	if ((sprites = (t_pair*)malloc(sizeof(t_pair) * amount)) == NULL)
		exit(1);
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}

void	calc_sprite(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->numsprites)
	{
		info->sorder[i] = i;
		info->sdis[i] = ((info->posx - info->sprite[i].x) *
		(info->posx - info->sprite[i].x) + (info->posy - info->sprite[i].y) *
		(info->posy - info->sprite[i].y));
		i++;
	}
	sort_sprites(info->sorder, info->sdis, info->numsprites);
	i = 0;
	while (i < info->numsprites)
	{
		set_sprite(info, &i);
		sprite_color(info);
		i++;
	}
}

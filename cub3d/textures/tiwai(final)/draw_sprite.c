/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:04:37 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/30 15:14:41 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		fill_pxsl(t_params *p, t_drawspr *d)
{
	d->sp = mlx_get_data_addr(*(p->tex + 4), &(d->bp), &(d->sl), &(d->end));
	d->tex = (int)(d->sl * (d->stripe - (-d->sw / 2 + d->ssx)) \
	* p->tw[4] / d->sw) / d->sl;
	d->d = \
	d->horizon * d->sl - p->mlx->h * d->sl / 2 + d->sh * d->sl / 2;
	d->tey = ((d->d * p->th[4]) / d->sh) / d->sl;
	d->color = *(int *)(d->sp + d->tey * d->sl + d->tex * d->bp / 8);
	if ((d->color & NOTBLACK) != 0)
	{
		d->src = (char *)&(d->color);
		p->mlx->d_img[d->horizon * p->mlx->sl \
		+ d->stripe * p->mlx->bit / 8] = \
		d->src[0];
		p->mlx->d_img[d->horizon * p->mlx->sl \
		+ d->stripe * p->mlx->bit / 8 + 1] = d->src[1];
		p->mlx->d_img[d->horizon * p->mlx->sl \
		+ d->stripe * p->mlx->bit / 8 + 2] = d->src[2];
	}
}

void		draw_sprite(t_params *p, t_drawspr *d)
{
	d->stripe = d->dsx;
	while (d->stripe < d->dex)
	{
		if (d->trsy > 0 && d->stripe > 0 \
		&& d->stripe < p->mlx->w && d->trsy < p->zbuffer[d->stripe])
		{
			d->horizon = d->dsy;
			while (d->horizon < d->dey)
			{
				fill_pxsl(p, d);
				d->horizon++;
			}
		}
		d->stripe++;
	}
}

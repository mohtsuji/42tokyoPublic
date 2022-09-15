/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:48:41 by tiwai             #+#    #+#             */
/*   Updated: 2020/12/08 00:13:32 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				comp_dist(t_list *current, t_list *next, t_params *p)
{
	double		d1;
	double		d2;
	t_sprite	*cr_sp;
	t_sprite	*nx_sp;

	if (next == NULL)
		return (0);
	cr_sp = (t_sprite *)current->content;
	nx_sp = (t_sprite *)next->content;
	d1 = (cr_sp->x - p->player->px) * (cr_sp->x - p->player->px) \
	+ (cr_sp->y - p->player->py) * (cr_sp->y - p->player->py);
	d2 = (nx_sp->x - p->player->px) * (nx_sp->x - p->player->px) \
	+ (nx_sp->y - p->player->py) * (nx_sp->y - p->player->py);
	return (d2 > d1);
}

static void		swap_lst(t_list *current, t_list *next)
{
	t_sprite	*cr_sp;
	t_sprite	*nx_sp;
	double		tmp_x;
	double		tmp_y;

	cr_sp = (t_sprite *)current->content;
	nx_sp = (t_sprite *)next->content;
	tmp_x = cr_sp->x;
	tmp_y = cr_sp->y;
	cr_sp->x = nx_sp->x;
	cr_sp->y = nx_sp->y;
	nx_sp->x = tmp_x;
	nx_sp->y = tmp_y;
}

static void		sort_sprite(t_params *param)
{
	t_list *lst;
	t_list *start;

	lst = param->lst;
	start = lst;
	while (lst != NULL)
	{
		if (comp_dist(lst, lst->next, param))
		{
			swap_lst(lst, lst->next);
			lst = start;
			continue ;
		}
		lst = lst->next;
	}
}

static void		set_sprite(t_params *p, t_sprite *sprite, t_drawspr *d)
{
	d->sprite_x = sprite->x - p->player->px + 0.5;
	d->sprite_y = sprite->y - p->player->py + 0.5;
	d->inv = \
	1.0 / (p->player->plx * p->player->dy - p->player->dx * p->player->ply);
	d->trsx = \
	d->inv * (p->player->dy * d->sprite_x - p->player->dx * d->sprite_y);
	d->trsy = \
	d->inv * (p->player->ply * -1 * d->sprite_x + p->player->plx * d->sprite_y);
	d->ssx = (int)((p->mlx->w / 2) * (1 + d->trsx / d->trsy));
	d->sh = (int)fabs(p->mlx->h / d->trsy);
	d->dsy = -d->sh / 2 + p->mlx->h / 2;
	if (d->dsy < 0)
		d->dsy = 0;
	d->dey = d->sh / 2 + p->mlx->h / 2;
	if (d->dey >= p->mlx->h)
		d->dey = p->mlx->h - 1;
	d->sw = (int)fabs(p->mlx->h / d->trsy);
	d->dsx = -1 * d->sw / 2 + d->ssx;
	if (d->dsx < 0)
		d->dsx = 0;
	d->dex = d->sw / 2 + d->ssx;
	if (d->dex >= p->mlx->w)
		d->dex = p->mlx->w - 1;
}

void			sprite(t_params *param)
{
	t_sprite	sprite;
	t_drawspr	draw;
	t_list		*current;

	sort_sprite(param);
	current = param->lst;
	while (current != NULL)
	{
		sprite = *(t_sprite *)current->content;
		set_sprite(param, &sprite, &draw);
		draw_sprite(param, &draw);
		current = current->next;
	}
}

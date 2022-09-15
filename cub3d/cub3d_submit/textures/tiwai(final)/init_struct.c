/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:21:35 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/30 15:20:31 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlxstr(t_mlx *m)
{
	m->mlx_ptr = 0;
	m->window_ptr = 0;
	m->img = 0;
	m->d_img = 0;
	m->bit = 0;
	m->sl = 0;
	m->end = 0;
	m->w = 0;
	m->h = 0;
}

void	init_prmstr(t_params *p)
{
	int i;

	i = 0;
	p->mlx = 0;
	p->player = 0;
	p->ray = 0;
	p->info = 0;
	p->lst = 0;
	p->zbuffer = 0;
	while (i < 5)
	{
		p->tex[i] = 0;
		p->tw[i] = 0;
		p->th[i] = 0;
		++i;
	}
}

void	init_plyrstr(t_player *p)
{
	p->px = 0;
	p->py = 0;
	p->dx = 0;
	p->dy = 0;
	p->plx = 0;
	p->ply = 0;
	p->fwd = 0;
	p->back = 0;
	p->right = 0;
	p->left = 0;
	p->rot_left = 0;
	p->rot_right = 0;
}

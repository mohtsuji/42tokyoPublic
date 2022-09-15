/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:54:18 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/28 18:19:33 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player(t_params *param, int x, int y)
{
	static double	dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	static double	plane[4][2] =
	{{0, 0.66}, {0, -0.66}, {-0.66, 0}, {0.66, 0}};
	int				i;

	i = 0;
	if (param->info->map[x][y] == 'N')
		i = 0;
	else if (param->info->map[x][y] == 'S')
		i = 1;
	else if (param->info->map[x][y] == 'W')
		i = 2;
	else if (param->info->map[x][y] == 'E')
		i = 3;
	param->player->px = (double)x + 0.5;
	param->player->py = (double)y + 0.5;
	param->player->dx = dir[i][0];
	param->player->dy = dir[i][1];
	param->player->plx = plane[i][0];
	param->player->ply = plane[i][1];
	param->info->map[x][y] = '0';
}

void		init_player(t_params *param)
{
	int x;
	int y;

	x = 0;
	while (param->info->map[x] != NULL)
	{
		y = 0;
		while (param->info->map[x][y] != '\0')
		{
			if (param->info->map[x][y] == 'N' || param->info->map[x][y] == 'S'
			|| param->info->map[x][y] == 'W' || param->info->map[x][y] == 'E')
				set_player(param, x, y);
			++y;
		}
		++x;
	}
}

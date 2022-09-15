/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:43:32 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/01/31 15:16:33 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_n(t_info *info, int i, int j)
{
	if (info->flag_pos != 0)
		put_error("Error\ndouble position");
	info->worldmap[i][j] = '0';
	info->posx = (double)(i + 0.5);
	info->posy = (double)(j + 0.5);
	info->dirx = -1.0;
	info->diry = 0.0;
	info->px = 0.0;
	info->py = 0.66;
	info->flag_pos |= N;
}

void		set_s(t_info *info, int i, int j)
{
	if (info->flag_pos != 0)
		put_error("Error\ndouble position");
	info->posx = (double)(i + 0.5);
	info->posy = (double)(j + 0.5);
	info->worldmap[i][j] = '0';
	info->dirx = 1.0;
	info->diry = 0.0;
	info->px = 0.0;
	info->py = -0.66;
	info->flag_pos |= S;
}

void		set_e(t_info *info, int i, int j)
{
	if (info->flag_pos != 0)
		put_error("Error\ndouble position");
	info->posx = (double)(i + 0.5);
	info->posy = (double)(j + 0.5);
	info->worldmap[i][j] = '0';
	info->dirx = 0.0;
	info->diry = 1.0;
	info->px = 0.66;
	info->py = 0.0;
	info->flag_pos |= E;
}

void		set_w(t_info *info, int i, int j)
{
	if (info->flag_pos != 0)
		put_error("Error\ndouble position");
	info->worldmap[i][j] = '0';
	info->posx = (double)(i + 0.5);
	info->posy = (double)(j + 0.5);
	info->dirx = 0.0;
	info->diry = -1.0;
	info->px = -0.66;
	info->py = 0.0;
	info->flag_pos |= W;
}

void		search_pos(t_info *info)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (info->worldmap[i] != NULL)
	{
		while (info->worldmap[i][j] != '\0')
		{
			check_chara(info, i, j);
			if (info->worldmap[i][j] == 'N')
				set_n(info, i, j);
			if (info->worldmap[i][j] == 'S')
				set_s(info, i, j);
			if (info->worldmap[i][j] == 'E')
				set_e(info, i, j);
			if (info->worldmap[i][j] == 'W')
				set_w(info, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	if (info->flag_pos == 0)
		put_error("Error\nnot position");
}

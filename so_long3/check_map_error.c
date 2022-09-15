/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:59:45 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/30 15:03:33 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_surrounded(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->width)
	{
		if (info->worldmap[0][i] != '1' || \
			info->worldmap[info->height - 1][i] != '1')
			put_error("Error\nnot wall surrounded");
		i++;
	}
	i = 0;
	while (i < info->height)
	{
		if (info->worldmap[i][0] != '1' || \
			info->worldmap[i][info->width - 1] != '1')
			put_error("Error\nnot wall surrounded");
		i++;
	}
}

void	check_map_under(t_info *info)
{
	int		i;

	i = 0;
	while (info->worldmap[i] != NULL && info->worldmap[i][0] == '\0')
		i++;
	while (info->worldmap[i] != NULL && info->worldmap[i][0] != '\0')
		i++;
	while (info->worldmap[i] != NULL && info->worldmap[i][0] == '\0')
		i++;
	while (info->worldmap[i] != NULL && info->worldmap[i][0] != '\0')
		put_error("Error\nmap error");
}

void	check_illegal_character(t_info *info, int i, int j)
{
	if (info->worldmap[i][j] != '0' && info->worldmap[i][j] != '1' &&
		info->worldmap[i][j] != 'E' && info->worldmap[i][j] != 'C' &&
		info->worldmap[i][j] != 'P')
		put_error("Error\nillegal character in map or under map");
	if (info->worldmap[i][j] == 'E')
		info->E = 1;
	if (info->worldmap[i][j] == 'P')
		info->P = 1;
	if (info->worldmap[i][j] == 'C')
		info->C = 1;
}

void	check_map_error(t_info *info)
{
	int	w_size;
	int	h_size;
	int	i;
	int	j;

	mlx_get_screen_size(info->mlx, &w_size, &h_size);
	if (w_size < info->w_width || h_size < info->w_height)
		put_error("Error\nmapsize too big");
	wall_surrounded(info);
	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			check_illegal_character(info, i, j);
			j++;
		}
		i++;
	}
	if (info->C == 0 || info->P == 0 || info->E == 0)
		put_error("Error\nlack of element");
	check_map_under(info);
}

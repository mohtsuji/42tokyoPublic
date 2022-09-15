/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 22:39:56 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/01/31 00:21:36 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dfs_map(t_info *info, t_cmap *map, int x, int y)
{
	if (x < 0 || y < 0 || info->worldmap[x] == NULL ||
	info->worldmap[x][y] == '\0' || info->worldmap[x][y] == ' ')
	{
		map->check = 0;
		return ;
	}
	if (info->worldmap[x][y] == '1' || map->c_map[x][y] == 'g')
		return ;
	map->c_map[x][y] = 'g';
	dfs_map(info, map, x + 1, y);
	dfs_map(info, map, x - 1, y);
	dfs_map(info, map, x, y + 1);
	dfs_map(info, map, x, y - 1);
}

void	check_mapsize(char **map)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
			++j;
		size += j;
		if (size > 500 * 500)
		{
			perror("Error\nmap is too big");
			exit(1);
		}
		j = 0;
		++i;
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
	{
		perror("Error\nmap error");
		exit(1);
	}
}

void	check_map(t_info *info)
{
	info->map.check = 1;
	check_mapsize(info->map.c_map);
	dfs_map(info, &(info->map), (int)info->posx, (int)info->posy);
	if (info->map.check == 0)
	{
		perror("Error\ninvalid map");
		exit(1);
	}
	check_map_under(info);
}

void	check_win_size(t_info *info)
{
	int		w;
	int		h;

	w = 0;
	h = 0;
	mlx_get_screen_size(info->mlx, &w, &h);
	if (info->width > w || info->width == -2)
		info->width = w;
	if (info->height > h || info->height == -2)
		info->height = h;
}

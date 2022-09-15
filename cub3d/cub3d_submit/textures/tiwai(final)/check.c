/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 21:11:57 by tiwai             #+#    #+#             */
/*   Updated: 2020/12/01 00:03:28 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		error_char(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str != 'N' && *str != 'S' && *str != 'W' &&
		*str != 'E' && *str != '0' && *str != '1' &&
		*str != '2' && *str != '\n' && *str != ' ')
			error_str("file: bad character in the map\n");
		if (*str == 'N' || *str == 'S' || *str == 'W' || *str == 'E')
		{
			*str = '0';
			++count;
		}
		++str;
	}
	if (count != 1)
		error_str("file: map error\n");
}

static void	dfs_map(t_params *param, t_cmap *cmap, int x, int y)
{
	if (x < 0 || y < 0 || param->info->map[x] == NULL ||
	param->info->map[x][y] == ' ' || param->info->map[x][y] == '\0')
	{
		cmap->check = 0;
		return ;
	}
	if (param->info->map[x][y] == '1' || cmap->c_map[x][y] == 'g')
		return ;
	cmap->c_map[x][y] = 'g';
	dfs_map(param, cmap, x + 1, y);
	dfs_map(param, cmap, x - 1, y);
	dfs_map(param, cmap, x, y + 1);
	dfs_map(param, cmap, x, y - 1);
}

void		check_mapsize(char **map)
{
	int i;
	int j;
	int volume;

	i = 0;
	j = 0;
	volume = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
			++j;
		volume += j;
		if (volume > 500 * 500)
			error_str("Sorry, the map is too big\n");
		j = 0;
		++i;
	}
}

void		check_map(t_params *param)
{
	t_cmap cmap;

	count_newline(param->info->map_str);
	cmap.check = 1;
	cmap.c_map = ft_split(param->info->map_str, '\n');
	check_mapsize(cmap.c_map);
	dfs_map(param, &cmap, (int)param->player->px, (int)param->player->py);
	free_multi(&cmap.c_map);
	if (cmap.check == 0)
		error_str("map: not a valid map\n");
}

void		check_filename(char *str)
{
	while (*str)
		++str;
	str -= 4;
	if (ft_strcmp(str, ".cub") != 0)
		error_str("file: make sure it is .cub file\n");
}

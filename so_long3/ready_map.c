/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:33:57 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/30 17:57:09 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_start_position(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	info->c_num = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if (info->worldmap[i][j] == 'P')
			{
				if (info->posy != 0 && info->posx != 0)
					info->worldmap[info->posy][info->posx] = '0';
				info->posy = i;
				info->posx = j;
			}
			else if (info->worldmap[i][j] == 'C')
				info->c_num++;
			j++;
		}
		i++;
	}
}

void	copy_map(t_info *info, char ***line)
{
	int		i;

	i = 0;
	info->worldmap = (char **)xmalloc(sizeof(char *) * (info->height + 1));
	while (i < info->height)
	{
		info->worldmap[i] = safe_dup((*line)[i]);
		i++;
	}
	info->worldmap[i] = NULL;
	get_start_position(info);
}

void	buf_malloc(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	info->buf = (unsigned int **)xmalloc(sizeof(unsigned int *) * \
				info->w_height);
	while (i < info->w_height)
	{
		info->buf[i] = (unsigned int *)xmalloc(sizeof(unsigned int) * \
						info->w_width);
		i++;
	}
	i = 0;
	while (i < info->w_height)
	{
		while (j < info->w_width)
			info->buf[i][j++] = 0;
		j = 0;
		i++;
	}
}

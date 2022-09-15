/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 00:41:02 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 13:29:56 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_chara(t_info *info, int i, int j)
{
	if (info->worldmap[i][j] != 'N' && info->worldmap[i][j] != 'S' &&
		info->worldmap[i][j] != 'E' && info->worldmap[i][j] != 'W' &&
		info->worldmap[i][j] != '1' && info->worldmap[i][j] != '2' &&
		info->worldmap[i][j] != '0' && info->worldmap[i][j] != ' ')
		put_error("Error\nillegal character in map or under map");
}

void	check_space_only(char ***line, int *i)
{
	int		j;

	j = 0;
	while ((*line)[*i][j] != 0)
	{
		if ((*line)[*i][j] != ' ')
			put_error("Error\ninvalid character in file");
		j++;
	}
}

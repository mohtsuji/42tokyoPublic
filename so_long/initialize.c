/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:40:08 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/28 22:49:15 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_info *info)
{
	info->mlx = NULL;
	info->buf = 0;
	info->texture = 0;
	info->worldmap = NULL;
	info->posx = 0;
	info->posy = 0;
	info->win = NULL;
	info->width = 0;
	info->height = 0;
	info->c_num = 0;
	info->move_num = 0;
	info->E = 0;
	info->P = 0;
	info->C = 0;
}

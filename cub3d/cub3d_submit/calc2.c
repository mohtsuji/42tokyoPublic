/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 00:19:00 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 00:11:19 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_color(t_info *info, int *x, int *texn, int *side)
{
	int	y;
	int	color;

	y = 0;
	while (y < info->ct.dstart)
	{
		color = info->ccolor;
		info->buf[y][*x] = color;
		y++;
	}
	y = info->ct.dstart;
	while (y < info->ct.dend)
	{
		info->ct.texy = (int)info->ct.texpos & (TEXHEIGHT - 1);
		info->ct.texpos += info->step;
		color = info->texture[*texn][TEXHEIGHT * info->ct.texy + info->ct.texx];
		if (*side == 1)
			color = (color >> 1) & 8355711;
		info->buf[y++][*x] = color;
	}
	while (y < info->height)
	{
		color = info->fcolor;
		info->buf[y++][*x] = color;
	}
}

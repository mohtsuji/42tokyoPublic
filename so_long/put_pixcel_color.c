/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixcel_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:48:55 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/30 17:22:16 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_pixcel(t_info *info, long tex_x, char position, unsigned int *buf)
{
	if (position == '1' || position == '0')
		*buf = info->texture[char_atoi(position)][tex_x];
	else if (position == 'C')
		*buf = info->texture[2][tex_x];
	else if (position == 'P')
		*buf = info->texture[4][tex_x];
	else if (position == 'E')
		*buf = info->texture[3][tex_x];
	(void)tex_x;
	(void)buf;
}

void	pixcel_set(t_info *info, int p1, int p2, int y)
{
	int	x;

	x = 0;
	while (x < info->img.img_width)
	{
		set_pixcel(info, 64 * y + x, info->worldmap[p1][p2], \
				&(info->buf[64 * p1 + y][64 * p2 + x]));
		x++;
	}
}

void	put_pixcel_color(t_info *info)
{
	int	p1;
	int	p2;
	int	y;

	p1 = 0;
	while (p1 < info->height)
	{
		y = 0;
		while (y < info->img.img_height)
		{
			p2 = 0;
			while (p2 < info->width)
			{
				pixcel_set(info, p1, p2, y);
				p2++;
			}
			y++;
		}
		p1++;
	}
}

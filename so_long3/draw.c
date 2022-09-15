/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 09:08:30 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/30 15:04:01 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_info *info)
{
	int	real_width;
	int	y;
	int	x;

	y = 0;
	real_width = info->w_width - (info->w_width % 4);
	while (y < info->w_height)
	{
		x = 0;
		while (x < real_width)
		{
			info->img.data[y * info->w_width + x] = info->buf[y][x];
			x++;
		}
		while (x < info->w_width)
		{
			info->img.data[y * info->w_width + x] = 0;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	mlx_do_sync(info->mlx);
}

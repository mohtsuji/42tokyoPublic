/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:56:57 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/30 15:12:07 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_info *info)
{
	if (key == K_W)
		move_front(info);
	if (key == K_S)
		move_back(info);
	if (key == K_D)
		move_right(info);
	if (key == K_A)
		move_left(info);
	if (key == K_ESC)
		exit(0);
	return (0);
}

int	main_loop(t_info *info)
{
	put_pixcel_color(info);
	draw(info);
	return (0);
}

void	loop_mlx(t_info *info)
{
	info->win = mlx_new_window(info->mlx, info->w_width, info->w_height, \
				"so_long");
	info->img.img = mlx_new_image(info->mlx, info->w_width, info->w_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &(info->img.bpp), \
	&(info->img.size_l), &(info->img.endian));
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, 2, (1L << 0), &key_press, info);
	mlx_hook(info->win, 17, (1L << 17), &close_game, info);
	mlx_loop(info->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:02:54 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 00:43:54 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_info *info, int *texture, char *path)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	if ((info->img.img = mlx_xpm_file_to_image(info->mlx, path,
		&(info->img.img_width), &(info->img.img_height))) == NULL)
		put_error("Error\ninvalid image file");
	if (info->img.img_width != 64 || info->img.img_height != 64)
		put_error("Error\ninvalid image file");
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
		&(info->img.bpp), &(info->img.size_l), &(info->img.endian));
	while (y < info->img.img_height)
	{
		while (x < info->img.img_width)
		{
			texture[info->img.img_width * y + x] =
			info->img.data[info->img.img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(info->mlx, info->img.img);
}

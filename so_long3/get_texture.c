/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:52:53 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/30 15:09:41 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_info *info, int *texture, char *path)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	info->img.img = mlx_xpm_file_to_image(info->mlx, path, \
		&(info->img.img_width), &(info->img.img_height));
	if (info->img.img == NULL)
		put_error("Error\ninvalid image file");
	if (info->img.img_width != 64 || info->img.img_height != 64)
		put_error("Error\n64 invalid image file");
	info->img.data = (int *)mlx_get_data_addr(info->img.img, \
		&(info->img.bpp), &(info->img.size_l), &(info->img.endian));
	while (y < info->img.img_height)
	{
		while (x < info->img.img_width)
		{
			texture[info->img.img_width * y + x] = \
			info->img.data[info->img.img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(info->mlx, info->img.img);
}

void	tex_malloc(t_info *info)
{
	int		i;
	int		j;
	long	size;

	i = 0;
	j = 0;
	size = TEXHEIGHT * TEXWIDTH;
	info->texture = (int **)xmalloc(sizeof(int *) * 5);
	while (i < 5)
	{
		info->texture[i] = (int *)xmalloc(sizeof(int) * size);
		i++;
	}
	while (i < 5)
	{
		while (j < TEXHEIGHT * TEXWIDTH)
		{
			info->texture[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_texture(t_info *info)
{
	tex_malloc(info);
	load_image(info, info->texture[1], "./textures/greystone.xpm");
	load_image(info, info->texture[2], "./textures/barrel.xpm");
	load_image(info, info->texture[0], "./textures/greenlight.xpm");
	load_image(info, info->texture[3], "./textures/bluestone.xpm");
	load_image(info, info->texture[4], "./textures/eagle.xpm");
}

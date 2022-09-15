/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:28:09 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/01/31 16:03:33 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	zero_pad(int fd, int pad)
{
	unsigned char	zero[3];

	ft_bzero(zero, 3);
	if (pad > 0)
		write(fd, &zero, pad);
}

void	write_header(int fd, t_info *info)
{
	unsigned char	buf[54];
	unsigned int	file_size;

	file_size = 54 + info->width * 4 * info->height;
	ft_bzero(buf, 54);
	buf[0] = (unsigned char)'B';
	buf[1] = (unsigned char)'M';
	ft_memcpy(buf + 2, &file_size, sizeof(file_size));
	buf[10] = (unsigned char)54;
	buf[14] = (unsigned char)40;
	ft_memcpy(buf + 18, &info->width, sizeof(info->width));
	ft_memcpy(buf + 22, &info->height, sizeof(info->height));
	buf[26] = (unsigned char)1;
	buf[28] = (unsigned char)32;
	write(fd, buf, 54);
}

void	write_bmp(int fd, t_info *info)
{
	int				y;
	int				x;
	unsigned char	*buf;
	unsigned int	color;

	x = info->height - 1;
	y = 0;
	while (x >= 0)
	{
		y = 0;
		while (y < info->width)
		{
			color = info->buf[x][y];
			buf = (unsigned char *)&color;
			write(fd, buf, 3);
			zero_pad(fd, 1);
			y++;
		}
		--x;
	}
}

void	get_bit(t_info *info)
{
	int		fd;

	fd = open("./bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd == -1)
		put_error("Error\nmiss open");
	write_header(fd, info);
	write_bmp(fd, info);
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:59:09 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/30 17:12:11 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_nbr_buf(unsigned char *start, int count, int n)
{
	int i;

	i = 0;
	while (count > 0)
	{
		start[i] = (unsigned char)(n % 256);
		n /= 256;
		++i;
		--count;
	}
}

static void	file_header(int fd, t_mlx *mlx)
{
	unsigned char buf[54];

	ft_bzero(buf, 54);
	buf[0] = (unsigned char)'B';
	buf[1] = (unsigned char)'M';
	put_nbr_buf(buf + 2, 4, 54 + mlx->w * 4 * mlx->h);
	buf[10] = (unsigned char)54;
	buf[14] = (unsigned char)40;
	put_nbr_buf(buf + 18, 4, mlx->w);
	put_nbr_buf(buf + 22, 4, mlx->h);
	buf[26] = (unsigned char)1;
	buf[28] = (unsigned char)32;
	write(fd, buf, 54);
}

static void	zero_pad(int fd, int pad)
{
	unsigned char zero[3];

	ft_bzero(zero, 3);
	if (pad > 0)
		write(fd, &zero, pad);
}

static void	img_data(int fd, t_mlx *mlx)
{
	int				y;
	int				x;
	unsigned char	*buf;
	unsigned int	color;

	x = mlx->h - 1;
	y = 0;
	while (x >= 0)
	{
		y = 0;
		while (y < mlx->w)
		{
			color =
			*(unsigned int *)(mlx->d_img + x * mlx->sl + y * mlx->bit / 8);
			buf = (unsigned char*)&color;
			write(fd, buf, 3);
			zero_pad(fd, 1);
			++y;
		}
		--x;
	}
}

int			screenshot(t_params *param)
{
	int fd;

	fd = open("first_img.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		error_str("could not creat a bmp file\n");
	raycast(param);
	sprite(param);
	file_header(fd, param->mlx);
	img_data(fd, param->mlx);
	close(fd);
	return (0);
}

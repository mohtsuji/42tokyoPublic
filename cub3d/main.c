/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:40:29 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 00:47:07 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(t_info *info)
{
	int	real_width;
	int	y;
	int	x;

	y = 0;
	real_width = info->width - (info->width % 4);
	while (y < info->height)
	{
		x = 0;
		while (x < real_width)
		{
			info->img.data[y * info->width + x] = info->buf[y][x];
			x++;
		}
		while (x < info->width)
		{
			info->img.data[y * info->width + x] = 0;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	mlx_do_sync(info->mlx);
}

void	read_map(char ***line, int fd)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	j = 0;
	while (i == 1)
	{
		i = get_next_line(fd, &tmp);
		if (((*line)[j] = ft_strdup(tmp)) == NULL)
			put_error("Error\nerror in strdup");
		j++;
		free(tmp);
	}
	(*line)[j] = NULL;
	if (i == -1)
		put_error("Error\ninvalid file");
}

void	main_error(int argc, char **argv, t_info *info)
{
	if (argc != 3 && argc != 2)
		put_error("Error\nillegal number in comandline");
	if (argc == 3)
	{
		if (ft_match(argv[2], "--save") == 0)
			put_error("Error\ninvalid character in comandline");
		info->save = 1;
	}
	if (ft_cub(argv[1], ".cub") == 0)
		put_error("Error\ninvalid map");
}

void	loop_mlx(t_info *info)
{
	if (info->save == 0)
		info->win =
		mlx_new_window(info->mlx, info->width, info->height, "cub3D");
	info->img.img = mlx_new_image(info->mlx, info->width, info->height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &(info->img.bpp),
	&(info->img.size_l), &(info->img.endian));
	mlx_loop_hook(info->mlx, &main_loop, info);
	if (info->save == 0)
	{
		mlx_hook(info->win, 2, (1L << 0), &key_press, info);
		mlx_hook(info->win, 17, (1L << 17), &close_game, info);
	}
	mlx_loop(info->mlx);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		**line;
	int			count;
	t_info		info;

	info_initialize(&info);
	info.mlx = mlx_init();
	main_error(argc, argv, &info);
	count = line_malloc(argv[1], &line);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		put_error("Error\ninvalid map");
	read_map(&line, fd);
	close(fd);
	tex_malloc(&info);
	get_info(&line, &info, &count);
	check_win_size(&info);
	buf_malloc(&info);
	if (!(info.zbuf = (double *)malloc(sizeof(double) * info.width)))
		put_error("Error\nmiss malloc");
	loop_mlx(&info);
	free_buf(&info);
	return (0);
}

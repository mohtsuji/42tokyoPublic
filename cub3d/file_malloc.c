/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:08:53 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 00:17:50 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		line_malloc(char *pass, char ***line)
{
	char	*tmp;
	int		i;
	int		fd;
	int		count;

	i = 1;
	fd = 0;
	count = 0;
	fd = open(pass, O_RDONLY);
	if (fd == -1)
		put_error("Error\ninvalid file");
	tmp = NULL;
	while (i == 1)
	{
		i = get_next_line(fd, &tmp);
		count++;
		free(tmp);
	}
	if (!((*line) = (char **)malloc(sizeof(char *) * (count + 1))))
		put_error("Error\nerror at malloc");
	close(fd);
	return (count);
}

void	tex_malloc(t_info *info)
{
	int		i;
	int		j;
	long	size;

	i = 0;
	j = 0;
	size = TEXHEIGHT * TEXWIDTH;
	if (!(info->texture = (int **)malloc(sizeof(int *) * 5)))
		put_error("Error\nerror at malloc");
	while (i < 5)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) * size)))
			put_error("Error\nerror at malloc");
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

void	buf_malloc(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(info->buf = \
			(unsigned int **)malloc(sizeof(unsigned int *) * info->height)))
		put_error("Error\nerror at malloc");
	while (i < info->height)
	{
		if (!(info->buf[i] = \
			(unsigned int *)malloc(sizeof(unsigned int) * info->width)))
			put_error("Error\nerror at malloc");
		i++;
	}
	i = 0;
	while (i < info->height)
	{
		while (j < info->width)
			info->buf[i][j++] = 0;
		j = 0;
		i++;
	}
}

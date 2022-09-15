/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 23:00:27 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/30 21:18:23 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ext_inf(t_info *inf, char ***ext, char **line)
{
	if (ft_strcmp((*ext)[0], "R") == 0)
		set_resol(inf, ext);
	else if (ft_strcmp((*ext)[0], "NO") == 0)
		set_texture(inf, ext, 0, NORTH);
	else if (ft_strcmp((*ext)[0], "SO") == 0)
		set_texture(inf, ext, 1, SOUTH);
	else if (ft_strcmp((*ext)[0], "WE") == 0)
		set_texture(inf, ext, 2, WEST);
	else if (ft_strcmp((*ext)[0], "EA") == 0)
		set_texture(inf, ext, 3, EAST);
	else if (ft_strcmp((*ext)[0], "S") == 0)
		set_texture(inf, ext, 4, SPRITE);
	else if (ft_strcmp((*ext)[0], "F") == 0)
		set_color(inf, FLOOR, line);
	else if (ft_strcmp((*ext)[0], "C") == 0)
		set_color(inf, CEIL, line);
	else
		error_str("file:unknown key\n");
}

void	extract(char **line, t_info *inf)
{
	char			**ext;

	if (!(ext = ft_split(*line, ' ')))
		error_str("memory allocation failure\n");
	if (ext[0] == NULL)
	{
		free(*line);
		free_multi(&ext);
		return ;
	}
	ext_inf(inf, &ext, line);
	free_multi(&ext);
	free(*line);
	*line = NULL;
}

void	make_map_str(char **map, char **line)
{
	char *nw;
	char *tmp;

	if ((nw = ft_strjoin(*line, "\n")) == NULL)
		error_str("memory allocation failure\n");
	free(*line);
	*line = NULL;
	if (*map == NULL)
		*map = nw;
	else
	{
		if ((tmp = ft_strjoin(*map, nw)) == NULL)
			error_str("memory allocation failure\n");
		free(*map);
		free(nw);
		nw = NULL;
		*map = tmp;
	}
}

void	extract_and_map(int fd, char **map, char **line, t_info *inf)
{
	int rv;

	while (1)
	{
		rv = get_next_line(fd, line);
		if (rv < 0)
			error_str("file: could not read the file\n");
		if (inf->flag != ALL)
			extract(line, inf);
		else
			make_map_str(map, line);
		if (rv == 0)
			break ;
	}
	free(*line);
	*line = NULL;
}

void	init_info(char *str, t_info *inf)
{
	int		fd;
	char	*line;
	char	*map;

	inf->flag = 0;
	if ((fd = open(str, O_RDONLY)) < 0)
		error_str("cannot open the file\n");
	map = NULL;
	extract_and_map(fd, &map, &line, inf);
	make_map(map, inf);
	close(fd);
}

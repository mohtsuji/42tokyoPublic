/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:59:55 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/30 21:19:46 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_map(char *map, t_info *inf)
{
	char **ans;

	if (map == NULL)
		error_str("file: map error\n");
	if ((ans = ft_split(map, '\n')) == NULL)
		error_str("memory allocation failure\n");
	inf->map = ans;
	inf->map_str = map;
}

void	set_resol(t_info *inf, char ***ext)
{
	int x;

	x = 0;
	while ((*ext)[x] != NULL)
		++x;
	if (x != 3 || inf->flag & RESOL)
		error_str("file: error in resolution\n");
	inf->rw = new_atoi((*ext)[1]);
	inf->rh = new_atoi((*ext)[2]);
	if (inf->rw == 0 || inf->rh == 0)
		error_str("file: error in resolution\n");
	inf->flag |= RESOL;
}

void	set_texture(t_info *inf, char ***ext, int n, int flag)
{
	int		x;
	char	*path;

	x = 0;
	while ((*ext)[x] != NULL)
		++x;
	if (x != 2 || inf->flag & flag)
		error_str("file: error in textures\n");
	if ((path = ft_strdup((*ext)[1])) == NULL)
		error_str("memory allocation failure\n");
	inf->texture[n] = path;
	inf->flag |= flag;
}

void	set_color(t_info *inf, int flag, char **line)
{
	int			color_num;
	char		**color;
	char		*str;
	char		*save;

	str = skip_key(*line);
	save = str;
	if ((color = ft_split(save, ',')) == NULL)
		error_str("memory allocation failure\n");
	if (inf->flag & flag || count_splits(color) != 3)
		error_str("file: error in color info\n");
	free_multi(&color);
	comm_to_space(&str);
	if ((color = ft_split(save, ' ')) == NULL)
		error_str("memory allocation failure\n");
	check_color(color);
	color_num = get_color(color);
	free_multi(&color);
	if (flag == FLOOR)
		inf->floor_color = (unsigned int)color_num;
	else
		inf->ceilling_color = (unsigned int)color_num;
	inf->flag |= flag;
}

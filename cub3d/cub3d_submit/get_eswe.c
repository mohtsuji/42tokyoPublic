/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_eswe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:40:38 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 00:00:49 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_r(char *tmp, t_info *info)
{
	char	**s;
	int		i;

	if (tmp[0] == '\0')
		put_error("Error\ninvalid number in R");
	if ((s = ft_split(tmp, ' ')) == NULL)
		put_error("Error\nerror in split");
	i = 0;
	while (s[i] != NULL)
		i++;
	if (info->flag & (1 << 0))
		put_error("Error\ndouble R");
	if (i != 2)
	{
		free_rcf(s, i);
		put_error("Error\ninvalid number in R");
	}
	info->width = ft_newatoi(s[0]);
	info->height = ft_newatoi(s[1]);
	free_rcf(s, i);
	if (info->width == -1 || info->height == -1 ||
	info->width == 0 || info->height == 0)
		put_error("Error\ninvalid number in R");
	info->flag |= RESOL;
}

void		get_no(char *tmp, t_info *info)
{
	if (tmp[0] == '\0')
		put_error("Error\ninvalid number in NO");
	if (info->flag & (1 << 1))
		put_error("Error\ndouble NO");
	load_image(info, info->texture[0], tmp);
	info->flag |= NORTH;
}

void		get_so(char *tmp, t_info *info)
{
	if (tmp[0] == '\0')
		put_error("Error\ninvalid number in SO");
	if (info->flag & (1 << 2))
		put_error("Error\ndouble SO");
	load_image(info, info->texture[1], tmp);
	info->flag |= SOUTH;
}

void		get_we(char *tmp, t_info *info)
{
	if (tmp[0] == '\0')
		put_error("Error\ninvalid number in WE");
	if (info->flag & (1 << 3))
		put_error("Error\ndouble WE");
	load_image(info, info->texture[2], tmp);
	info->flag |= WEST;
}

void		get_ea(char *tmp, t_info *info)
{
	if (tmp[0] == '\0')
		put_error("Error\ninvalid number in EA");
	if (info->flag & (1 << 4))
		put_error("Error\ndouble EA");
	load_image(info, info->texture[3], tmp);
	info->flag |= EAST;
}

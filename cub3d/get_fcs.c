/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:48:29 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 00:43:01 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_s(char *tmp, t_info *info)
{
	if (tmp[0] == '\0')
		put_error("Error\ninvalid number in S");
	if (info->flag & (1 << 5))
		put_error("Error\ndouble S");
	load_image(info, info->texture[4], tmp);
	info->flag |= SPRITE;
}

void		put_color(char ***color, t_info *info, int i, int flag)
{
	int		r;
	int		g;
	int		b;

	r = ft_newatoi((*color)[0]);
	g = ft_newatoi((*color)[1]);
	b = ft_newatoi((*color)[2]);
	free_rcf(*color, i);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		put_error("Error\ninvalid number in C or F");
	if (flag == 1)
	{
		info->ccolor = (0xFF & r) << 16;
		info->ccolor |= (0xFF & g) << 8;
		info->ccolor |= (0xFF & b);
	}
	else
	{
		info->fcolor = (0xFF & r) << 16;
		info->fcolor |= (0xFF & g) << 8;
		info->fcolor |= (0xFF & b);
	}
}

void		get_c(char *tmp, t_info *info)
{
	char	**color;
	int		i;

	if (tmp[0] == '\0')
		put_error("Error\ninvalid number in C");
	if (info->flag & (1 << 7))
		put_error("Error\ndouble C");
	if ((color = ft_split(tmp, ',')) == NULL)
		put_error("Error\nerror in split");
	i = 0;
	while (color[i] != NULL)
		i++;
	if (i != 3)
	{
		free_rcf(color, i);
		put_error("Error\ninvalid number in C");
	}
	put_color(&color, info, i, 1);
	info->flag |= CEIL;
}

void		get_f(char *tmp, t_info *info)
{
	char	**color;
	int		i;

	if (tmp[0] == '\0')
		put_error("Error\ninvalid number in F");
	if (info->flag & (1 << 6))
		put_error("Error\ndouble F");
	if ((color = ft_split(tmp, ',')) == NULL)
		put_error("Error\nerror in split");
	i = 0;
	while (color[i] != NULL)
		i++;
	if (i != 3)
	{
		free_rcf(color, i);
		put_error("Error\ninvalid number in F");
	}
	put_color(&color, info, i, 0);
	info->flag |= FLOOR;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_utls2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:06:43 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/30 15:22:26 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			count_splits(char **s)
{
	int i;

	i = 0;
	while (s[i] != NULL)
		++i;
	return (i);
}

static int	create_trgb(int t, int r, int g, int b)
{
	if (t >= 0 && t <= 255 && r >= 0 && r <= 255 \
	&& g >= 0 && g <= 255 && b >= 0 && b <= 255)
		return (t << 24 | r << 16 | g << 8 | b);
	return (-1);
}

int			get_color(char **color)
{
	int		retcolor;

	retcolor = create_trgb(0, (int)new_atoi(color[0]), \
	(int)new_atoi(color[1]), (int)new_atoi(color[2]));
	return (retcolor);
}

int			check_resol(t_params *param)
{
	int w;
	int h;

	mlx_get_screen_size(param->mlx->mlx_ptr, &w, &h);
	if (param->info->rw > (long)w || param->info->rw < 0)
		param->info->rw = (long)w;
	if (param->info->rh > (long)h || param->info->rh < 0)
		param->info->rh = (long)h;
	return (1);
}

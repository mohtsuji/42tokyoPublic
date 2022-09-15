/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_else.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:56:16 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/30 17:11:15 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_spr(t_params *param, int x, int y)
{
	t_sprite	*spr;
	t_list		*new;

	param->lst = NULL;
	while (param->info->map[x] != NULL)
	{
		y = 0;
		while (param->info->map[x][y] != '\0')
		{
			if (param->info->map[x][y] == '2')
			{
				if ((spr = (t_sprite *)malloc(sizeof(t_sprite))) == NULL)
					error_str("memory allocation failure\n");
				spr->x = (double)x;
				spr->y = (double)y;
				if ((new = ft_lstnew(spr)) == NULL)
					error_str("memory allocation failure\n");
				ft_lstadd_front(&param->lst, new);
			}
			++y;
		}
		++x;
	}
}

void		init_tex(t_params *param)
{
	int		i;
	int		tw;
	int		th;
	void	*adr;

	i = 0;
	while (i < 5)
	{
		if ((adr = mlx_xpm_file_to_image(param->mlx->mlx_ptr, \
		param->info->texture[i], &tw, &th)) == NULL)
			error_str("path: image file path is not valid\n");
		param->tex[i] = adr;
		param->tw[i] = tw;
		param->th[i] = th;
		++i;
	}
}

void		init_mlx(t_params *param, int screenshot)
{
	if ((param->mlx->mlx_ptr = mlx_init()) == NULL)
		error_str("mlx: mlx could not start\n");
	check_resol(param);
	if (screenshot != 0)
		param->mlx->window_ptr = mlx_new_window(param->mlx->mlx_ptr, \
	param->info->rw, param->info->rh, "cub3D");
	param->mlx->w = param->info->rw;
	param->mlx->h = param->info->rh;
	param->mlx->img = \
	mlx_new_image(param->mlx->mlx_ptr, param->mlx->w, param->mlx->h);
	param->mlx->d_img = mlx_get_data_addr(param->mlx->img, \
	&(param->mlx->bit), &(param->mlx->sl), &(param->mlx->end));
}

void		init_param(t_params *param)
{
	double *buf;

	buf = (double *)malloc(sizeof(double) * param->info->rw);
	if (buf == NULL)
		error_str("memory allocation failure\n");
	param->zbuffer = buf;
}

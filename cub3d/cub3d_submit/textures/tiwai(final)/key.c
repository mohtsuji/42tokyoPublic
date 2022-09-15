/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 21:24:13 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/28 18:38:17 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press_event(int key, t_params *param)
{
	if (key == KEY_W)
		param->player->fwd = 1;
	else if (key == KEY_S)
		param->player->back = 1;
	else if (key == KEY_A)
		param->player->left = 1;
	else if (key == KEY_D)
		param->player->right = 1;
	else if (key == KEY_LEFT)
		param->player->rot_left = 1;
	else if (key == KEY_RIGHT)
		param->player->rot_right = 1;
	else if (key == KEY_ESC)
	{
		mlx_destroy_window(param->mlx->mlx_ptr, param->mlx->window_ptr);
		close_game(param);
	}
	return (0);
}

int		key_release_event(int key, t_params *param)
{
	if (key == KEY_W)
		param->player->fwd = 0;
	else if (key == KEY_S)
		param->player->back = 0;
	else if (key == KEY_A)
		param->player->left = 0;
	else if (key == KEY_D)
		param->player->right = 0;
	else if (key == KEY_LEFT)
		param->player->rot_left = 0;
	else if (key == KEY_RIGHT)
		param->player->rot_right = 0;
	return (0);
}

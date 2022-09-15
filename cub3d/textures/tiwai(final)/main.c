/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:25:50 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/30 20:57:51 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	loop(t_params *param)
{
	move_player(param);
	raycast(param);
	sprite(param);
	mlx_put_image_to_window(param->mlx->mlx_ptr, \
	param->mlx->window_ptr, param->mlx->img, 0, 0);
	mlx_do_sync(param->mlx->mlx_ptr);
	return (0);
}

int			close_game(t_params *param)
{
	const char *s = "Thanks!!\n";

	(void)param;
	write(1, s, ft_strlen(s));
	exit(0);
}

static void	start_game(t_params *param)
{
	mlx_hook(param->mlx->window_ptr, 2, (1L << 0), key_press_event, param);
	mlx_key_hook(param->mlx->window_ptr, key_release_event, param);
	mlx_hook(param->mlx->window_ptr, 17, (1L << 17), &close_game, param);
	mlx_loop_hook(param->mlx->mlx_ptr, &loop, param);
	mlx_loop(param->mlx->mlx_ptr);
}

void		initialize(char *filename, t_params *p, int screenshot)
{
	init_info(filename, p->info);
	error_char(p->info->map_str);
	init_player(p);
	check_map(p);
	init_mlx(p, screenshot);
	init_tex(p);
	init_spr(p, 0, 0);
	init_param(p);
}

int			main(int argc, char **argv)
{
	t_params	param;
	t_player	player;
	t_mlx		mlx;
	t_info		inf;
	int			ss;

	init_mlxstr(&mlx);
	init_prmstr(&param);
	init_plyrstr(&player);
	param.player = &player;
	param.info = &inf;
	param.mlx = &mlx;
	if ((argc != 2 && argc != 3) || \
	(argc == 3 && (ss = ft_strcmp(argv[2], "--save")) != 0))
		error_str("wrong argument\n");
	check_filename(argv[1]);
	if (argc == 3)
	{
		initialize(argv[1], &param, ss);
		return (screenshot(&param));
	}
	initialize(argv[1], &param, 1);
	start_game(&param);
	return (0);
}

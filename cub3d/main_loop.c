/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:24:14 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 00:44:42 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main_loop(t_info *info)
{
	calc(info);
	calc_sprite(info);
	if (info->save == 1)
	{
		get_bit(info);
		exit(0);
	}
	draw(info);
	return (0);
}

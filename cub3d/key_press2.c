/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 01:03:07 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/01/31 01:45:12 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_info *info)
{
	double	olddirx;
	double	oldpx;

	olddirx = info->dirx;
	info->dirx = info->dirx * cos(info->rspeed) - info->diry *
	sin(info->rspeed);
	info->diry = olddirx * sin(info->rspeed) + info->diry *
	cos(info->rspeed);
	oldpx = info->px;
	info->px = info->px * cos(info->rspeed) -
	info->py * sin(info->rspeed);
	info->py = oldpx * sin(info->rspeed) + info->py *
	cos(info->rspeed);
}

void	rotate_right(t_info *info)
{
	double	olddirx;
	double	oldpx;

	olddirx = info->dirx;
	info->dirx = info->dirx * cos(-info->rspeed) -
	info->diry * sin(-info->rspeed);
	info->diry = olddirx * sin(-info->rspeed) +
	info->diry * cos(-info->rspeed);
	oldpx = info->px;
	info->px = info->px * cos(-info->rspeed) -
	info->py * sin(-info->rspeed);
	info->py = oldpx * sin(-info->rspeed) +
	info->py * cos(-info->rspeed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeeee.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 21:48:26 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 00:19:25 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_line(char ***line, int count)
{
	int		i;

	i = 0;
	while (i <= count)
		free((*line)[i++]);
	i = 0;
	while (i <= count)
		(*line)[i++] = NULL;
}

void	free_buf(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->height)
	{
		free(info->buf[i]);
		i++;
	}
	i = 0;
	while (i < info->height)
	{
		info->buf[i] = NULL;
		i++;
	}
}

void	free_rcf(char **str, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
}

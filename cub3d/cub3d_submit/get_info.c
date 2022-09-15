/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:23:31 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/01/31 22:16:56 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	search_map(t_info *info, char ***line, int *count, int i)
{
	int		n;

	n = 0;
	i += 1;
	if (!(info->worldmap = (char **)malloc(sizeof(char *) * (*count - i + 1))))
		put_error("Error\nerror malloc");
	if (!(info->map.c_map = (char **)malloc(sizeof(char *) * (*count - i + 1))))
		put_error("Error\nerror malloc");
	while (i < *count)
	{
		if ((info->worldmap[n] = ft_strdup((*line)[i])) == NULL)
			put_error("Error\nerror in strdup");
		if ((info->map.c_map[n] = ft_strdup((*line)[i])) == NULL)
			put_error("Error\nerror in strdup");
		i++;
		n++;
	}
	info->worldmap[n] = NULL;
	info->map.c_map[n] = NULL;
}

void	sprite_malloc(t_info *info)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	info->numsprites = 0;
	while (info->worldmap[i] != NULL)
	{
		while (info->worldmap[i][j] != 0)
		{
			if (info->worldmap[i][j++] == '2')
				count++;
		}
		j = 0;
		i++;
	}
	if (!(info->sprite = (t_sprite *)malloc(sizeof(t_sprite) * count)))
		exit(1);
	if (!(info->sorder = (int *)malloc(sizeof(int) * count)))
		exit(1);
	if (!(info->sdis = (double *)malloc(sizeof(double) * count)))
		exit(1);
}

void	search_sprite(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	sprite_malloc(info);
	while (info->worldmap[i] != NULL)
	{
		while (info->worldmap[i][j] != 0)
		{
			if (info->worldmap[i][j] == '2')
			{
				info->sprite[info->numsprites].x = (i + 0.5);
				info->sprite[info->numsprites].y = (j + 0.5);
				info->numsprites += 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	search_info(char ***line, t_info *info, int *i)
{
	char	*tmp;

	tmp = NULL;
	if ((tmp = ft_strcmp((*line)[*i], "R ")) != NULL)
		get_r(tmp, info);
	else if ((tmp = ft_strcmp((*line)[*i], "NO ")) != NULL)
		get_no(tmp, info);
	else if ((tmp = ft_strcmp((*line)[*i], "SO ")))
		get_so(tmp, info);
	else if ((tmp = ft_strcmp((*line)[*i], "WE ")))
		get_we(tmp, info);
	else if ((tmp = ft_strcmp((*line)[*i], "EA ")))
		get_ea(tmp, info);
	else if ((tmp = ft_strcmp((*line)[*i], "S ")))
		get_s(tmp, info);
	else if ((tmp = ft_strcmp((*line)[*i], "F ")))
		get_f(tmp, info);
	else if ((tmp = ft_strcmp((*line)[*i], "C ")))
		get_c(tmp, info);
	else if ((*line)[*i][0] == ' ')
		check_space_only(line, i);
}

void	get_info(char ***line, t_info *info, int *count)
{
	int		i;

	i = 0;
	while (i < *count)
	{
		search_info(line, info, &i);
		if (info->flag == ALL)
		{
			search_map(info, line, count, i);
			search_pos(info);
			check_map(info);
			search_sprite(info);
			free_line(line, *count);
			return ;
		}
		i++;
	}
	if (info->flag != ALL)
		put_error("Error\ninvalid file");
}

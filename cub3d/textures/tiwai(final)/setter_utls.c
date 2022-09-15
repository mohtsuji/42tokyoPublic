/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_utls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:32:49 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/30 21:29:22 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	syntax_str(const char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			error_str("file: invalid number in resol or color\n");
		++s;
	}
}

long	new_atoi(const char *s)
{
	long		ans;

	ans = 0;
	while (*s == ' ')
		++s;
	if (*s == '-')
		error_str("file: invalid number in resol or color\n");
	syntax_str(s);
	if (ft_strlen(s) > 10)
		return (-1);
	while (*s)
	{
		ans = ans * 10 + (*s - '0');
		++s;
	}
	return (ans);
}

void	check_color(char **color)
{
	int		i;
	long	num;

	i = 0;
	if (count_splits(color) != 3)
		error_str("file: error in color code\n");
	while (i < 3)
	{
		num = new_atoi(color[i]);
		if (num < 0 || num > 255)
			error_str("file: error in color code\n");
		++i;
	}
}

void	comm_to_space(char **s)
{
	int count;

	count = 0;
	while (**s)
	{
		if (**s == ',')
		{
			++count;
			**s = ' ';
		}
		(*s)++;
	}
	if (count != 2)
		error_str("file: error in color info\n");
}

char	*skip_key(char *str)
{
	while (*str)
	{
		if (*str == 'F' || *str == 'C')
			return (str + 1);
		++str;
	}
	return (str);
}

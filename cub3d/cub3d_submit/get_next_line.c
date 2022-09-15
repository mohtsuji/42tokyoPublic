/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:18:38 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/01/30 00:56:39 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_in_line(char **line, char **stay)
{
	char	*tmp;
	char	*hozon;

	tmp = ft_strchr(*stay, '\n');
	tmp[0] = '\0';
	if (!(*line = ft_strdup(*stay)))
	{
		printf("*line=%s\n", *line);
		free(*stay);
		*stay = NULL;
		return (-1);
	}
	hozon = *stay;
	if (!(*stay = ft_strdup(tmp + 1)))
	{
		free(hozon);
		hozon = NULL;
		return (-1);
	}
	free(hozon);
	hozon = NULL;
	return (1);
}

static int	ft_saigo(char **line, char **stay)
{
	if (!(*line = ft_strdup(*stay)))
	{
		free(*stay);
		return (-1);
	}
	free(*stay);
	*stay = NULL;
	return (0);
}

static int	ft_join(char **stay, char *buf)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(*stay, buf)))
	{
		free(*stay);
		*stay = NULL;
		free(buf);
		buf = NULL;
		return (-1);
	}
	free(*stay);
	*stay = NULL;
	free(buf);
	buf = NULL;
	*stay = tmp;
	return (1);
}

int			get_next_line_main(int fd, char **line, int result, char **stay)
{
	char		*buf;
	ssize_t		size;

	while (ft_strchr(stay[fd], '\n') == 0)
	{
		if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) ||
				(size = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free(stay[fd]);
			return (-1);
		}
		buf[size] = '\0';
		result = ft_join(&stay[fd], buf);
		if (size == 0)
		{
			result = ft_saigo(line, &stay[fd]);
			return (result);
		}
	}
	if (result == -1)
		return (-1);
	result = set_in_line(line, &stay[fd]);
	return (result);
}

int			get_next_line(int fd, char **line)
{
	int			result;
	static char	*stay[FOPEN_MAX];

	result = 0;
	if (fd > FOPEN_MAX || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (stay[fd] == NULL)
	{
		if (!(stay[fd] = ft_strdup("")))
			return (-1);
	}
	result = get_next_line_main(fd, line, result, stay);
	return (result);
}

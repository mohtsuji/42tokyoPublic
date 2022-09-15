/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:17:36 by tiwai             #+#    #+#             */
/*   Updated: 2020/11/26 19:35:31 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	safe_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

int		join(char **store, char **buf)
{
	char *tmp;

	if ((tmp = ft_strjoin(*store, *buf)) == NULL)
	{
		safe_free(store);
		safe_free(buf);
		return (-1);
	}
	free(*store);
	safe_free(buf);
	*store = tmp;
	return (1);
}

int		last(char **line, char **store)
{
	if ((*line = ft_strdup(*store)) == NULL)
	{
		safe_free(store);
		return (-1);
	}
	safe_free(store);
	return (0);
}

int		set_line(char **line, char **store)
{
	char *tmp;
	char *save;

	tmp = ft_strchr(*store, '\n');
	*tmp = '\0';
	if ((*line = ft_strdup(*store)) == NULL)
	{
		safe_free(store);
		return (-1);
	}
	if ((save = ft_strdup(tmp + 1)) == NULL)
	{
		safe_free(store);
		return (-1);
	}
	safe_free(store);
	*store = save;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*store;
	char			*buf;
	int				result;
	ssize_t			rv;

	result = 0;
	if (fd < 0 || fd == 1 || fd == 2)
		return (-1);
	if (store == NULL && ((store = ft_strdup("")) == NULL))
		return (-1);
	while (ft_strchr(store, '\n') == NULL)
	{
		if (!((buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))) ||
		(rv = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			safe_free(&store);
			return (-1);
		}
		buf[rv] = '\0';
		if ((result = join(&store, &buf)) < 0)
			return (-1);
		if (rv == 0)
			return (result = last(line, &store));
	}
	return (result = set_line(line, &store));
}

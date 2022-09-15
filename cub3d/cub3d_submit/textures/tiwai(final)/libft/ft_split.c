/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:02:43 by tiwai             #+#    #+#             */
/*   Updated: 2020/07/13 21:32:09 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_arr(char **array, size_t col)
{
	size_t i;

	i = 0;
	while (i < col)
	{
		free(array[i]);
		++i;
	}
	free(array);
}

static size_t	how_many(char *search, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;

	len = ft_strlen(search);
	i = 0;
	count = 0;
	while (i < len)
	{
		if (search[i] == c)
			search[i] = '\0';
		++i;
	}
	i = 0;
	while (i < len)
	{
		if (search[i] != '\0' && search[i + 1] == '\0')
			++count;
		++i;
	}
	return (count);
}

static char		**fill_array(char **array, char *cpy, size_t colm, size_t strm)
{
	size_t	i;
	size_t	col;
	char	*line;

	col = 0;
	i = 0;
	while (col < colm)
	{
		while (cpy[i] == '\0' && i < strm)
			++i;
		if (!(line = (char *)ft_calloc(ft_strlen(cpy + i) + 1, sizeof(char))))
		{
			free(cpy);
			free_arr(array, col);
			return (0);
		}
		array[col++] = (char *)ft_memcpy(line, cpy + i, ft_strlen(cpy + i));
		while (cpy[i] != '\0' && i < strm)
			++i;
	}
	array[col] = NULL;
	free(cpy);
	return (array);
}

char			**ft_split(char const *s, char c)
{
	char	*cpy;
	char	**array;
	size_t	colm;
	size_t	strm;

	if (!s)
		return (0);
	if (!(cpy = ft_strdup(s)))
		return (0);
	strm = ft_strlen(cpy);
	colm = how_many(cpy, c);
	if (!(array = (char **)malloc((colm + 1) * sizeof(char *))))
		return (0);
	return (fill_array(array, cpy, colm, strm));
}

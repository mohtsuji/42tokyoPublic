/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 21:21:16 by tiwai             #+#    #+#             */
/*   Updated: 2020/12/01 00:18:51 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strcmp(char *s, char *f)
{
	unsigned char *fst;
	unsigned char *scd;

	fst = (unsigned char *)s;
	scd = (unsigned char *)f;
	while (*fst == *scd)
	{
		if (*fst == '\0')
			return (*fst - *scd);
		++fst;
		++scd;
	}
	return (*fst - *scd);
}

int		error_str(const char *str)
{
	write(1, "Error\n", 7);
	write(1, str, ft_strlen(str));
	exit(1);
	return (0);
}

void	free_multi(char ***arr)
{
	int x;

	x = 0;
	if (*arr == NULL)
		return ;
	while ((*arr)[x] != NULL)
	{
		free((*arr)[x]);
		(*arr)[x] = NULL;
		++x;
	}
	free(*arr);
	*arr = NULL;
}

void	count_newline(char *s)
{
	char *srch;

	if (s == NULL)
		error_str("file:map error\n");
	if ((srch = ft_strtrim(s, "\n")) == NULL)
		error_str("memory allocation failure\n");
	if (ft_strnstr(srch, "\n\n", ft_strlen(srch)) != NULL)
		error_str("file:map error\n");
	free(srch);
}

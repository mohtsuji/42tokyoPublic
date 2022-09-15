/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 07:59:03 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/15 07:59:43 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim(char *str, char const *set)
{
	char	check[130];
	int		i;
	int		j;
	int		h;

	i = 0;
	h = 0;
	while (i < 128)
		check[i++] = 0;
	while (set[h] != 0)
	{
		j = set[h];
		check[j] = 1;
		h++;
	}
	i = 0;
	while (*str != 0)
	{
		j = *str;
		if (check[j] == 0)
			break ;
		str++;
	}
	return (str);
}

static char	*re_trim(char *str, char const *set)
{
	char	check[300];
	int		i;
	int		j;
	int		h;
	int		len;

	len = ft_strlen(str);
	i = 0;
	h = 0;
	while (i < 128)
		check[i++] = 0;
	while (set[h] != 0)
	{
		j = set[h++];
		check[j] = 1;
	}
	i = 0;
	while (str[len - 1] != 0)
	{
		j = str[len - 1];
		if (check[j] == 0)
			break ;
		len--;
	}
	return (&str[len - 1]);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*re;
	char	*start;
	char	*end;
	int		i;

	if (s1 == NULL || set == NULL)
		return (0);
	if (*s1 == '\0' || *set == '\0')
		return (ft_strdup(s1));
	i = ft_strlen(s1);
	start = trim((char *)s1, set);
	if (*start == 0)
		return (ft_strdup(""));
	end = re_trim((char *)s1, set);
	i = end - start;
	if (!(re = malloc(i + 2)))
		return (0);
	ft_strlcpy(re, start, i + 2);
	return (re);
}

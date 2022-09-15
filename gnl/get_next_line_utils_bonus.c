/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:15:30 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/13 21:15:40 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*p;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(p = (char *)malloc(s1_len + s2_len + 1)))
		return (0);
	i = 0;
	while (s1_len + s2_len > i)
	{
		p[i] = (i < s1_len) ? s1[i] : s2[i - s1_len];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		n;
	int		i;

	i = 0;
	n = 0;
	n = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

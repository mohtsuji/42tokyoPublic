/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 07:37:50 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/18 23:52:36 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_free(char **result, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_main(char const *s, char c, char **hako)
{
	int		i;
	int		j;
	int		h;
	char	**result;

	result = hako;
	i = 0;
	h = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			result[h] = ft_substr((char *)s + j, 0, i - j);
			h++;
		}
		if (h > 0 && result[h - 1] == NULL)
			return (ft_free(result, h));
	}
	result[h] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**hako;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_count(s, c);
	if (!(hako = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	return (ft_main(s, c, hako));
}

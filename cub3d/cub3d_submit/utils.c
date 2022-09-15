/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:03:12 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/01/31 01:47:54 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strcmp(char *big, char *little)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return (NULL);
	while (big[i] != 0)
	{
		while (big[i + j] == little[j] && big[i + j] != 0)
			j++;
		if (little[j] == '\0')
			return ((char *)big + i + j);
		i++;
		j = 0;
	}
	return (NULL);
}

int		ft_match(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
		i++;
	if (s1[i] == 0 && s2[i] == 0)
		return (1);
	return (0);
}

int		ft_cub(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		while (s1[i + j] == s2[j] && s1[i + j] != 0 && s2[j] != 0)
			j++;
		if (s1[i + j] != 0 && s2[j] == 0)
			return (0);
		if (s2[j] == 0 && s1[i + j] == 0)
			return (1);
		i++;
	}
	return (0);
}

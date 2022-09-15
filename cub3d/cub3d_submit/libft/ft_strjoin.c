/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 21:42:43 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/15 08:02:56 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		total;
	int		j;
	int		h;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	h = 0;
	if (!(result = malloc(total + 1)))
		return (NULL);
	while (s1[i] != 0)
		result[h++] = s1[i++];
	while (s2[j] != 0)
		result[h++] = s2[j++];
	result[h] = '\0';
	return (result);
}

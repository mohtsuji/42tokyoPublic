/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:00:11 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/06 18:02:22 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;
	size_t	total;

	total = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	j = 0;
	if ((size_t)ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	while (dst[i] != 0)
	{
		i++;
		dstsize--;
	}
	while (dstsize - 1 != 0 && src[j] != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
		dstsize--;
	}
	dst[i] = '\0';
	return (total);
}

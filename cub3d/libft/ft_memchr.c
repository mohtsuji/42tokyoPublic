/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:29:34 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/05 22:55:16 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	unsigned char	*dest;
	unsigned char	c;
	int				i;

	dest = (unsigned char *)buf;
	c = (unsigned char)ch;
	i = 0;
	while (n != 0)
	{
		if (dest[i] == c)
			return ((void *)dest + i);
		i++;
		n--;
	}
	return (NULL);
}

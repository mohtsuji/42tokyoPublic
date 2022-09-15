/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 14:07:14 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/05 19:52:41 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;
	unsigned char		d;
	int					i;

	dest2 = dest;
	src2 = src;
	d = c;
	i = 0;
	while (n != 0)
	{
		dest2[i] = src2[i];
		if (dest2[i] == d)
			return (dest + i + 1);
		i++;
		n--;
	}
	return (NULL);
}

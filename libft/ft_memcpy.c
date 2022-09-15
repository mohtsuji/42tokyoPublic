/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 11:29:09 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/05 19:53:05 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	int					i;
	unsigned char		*dest;
	const unsigned char	*src;

	i = 0;
	dest = buf1;
	src = buf2;
	if (buf1 == 0 && buf2 == 0)
		return (0);
	while (n != 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	return (buf1);
}

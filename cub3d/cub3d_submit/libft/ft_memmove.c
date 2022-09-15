/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:08:04 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/05 23:20:10 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = buf1;
	src = (unsigned char *)buf2;
	if (buf1 == NULL && buf2 == NULL)
		return (NULL);
	if (dest < src)
		ft_memcpy(buf1, buf2, n);
	else
	{
		while (n != 0)
		{
			*(dest + n - 1) = *(src + n - 1);
			n--;
		}
	}
	return (buf1);
}

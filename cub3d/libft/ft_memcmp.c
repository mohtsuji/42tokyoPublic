/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:25:32 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/05 19:58:25 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	const unsigned char	*dest;
	const unsigned char	*src;
	int					i;

	i = 0;
	dest = buf1;
	src = buf2;
	while (n != 0)
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		i++;
		n--;
	}
	return (0);
}

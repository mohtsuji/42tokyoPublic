/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:50:02 by tiwai             #+#    #+#             */
/*   Updated: 2020/06/27 20:19:26 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p;
	const char	*s;

	p = (char *)dst;
	s = (const char *)src;
	if (p == s)
		return (dst);
	if (dst < src)
	{
		while (len--)
			*p++ = *s++;
	}
	else
	{
		p += len;
		s += len;
		while (len--)
			*--p = *--s;
	}
	return (dst);
}

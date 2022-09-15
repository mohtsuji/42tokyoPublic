/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:24:52 by tiwai             #+#    #+#             */
/*   Updated: 2020/06/27 17:31:57 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*p;
	const unsigned char	*s;
	unsigned char		cr;

	p = (unsigned char *)dst;
	s = (const unsigned char *)src;
	cr = (unsigned char)c;
	while (n--)
	{
		*p = *s;
		p++;
		if (*s == cr)
			return ((void *)p);
		s++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:53:57 by tiwai             #+#    #+#             */
/*   Updated: 2020/06/26 16:26:21 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		uc;
	const unsigned char	*sr;

	uc = (unsigned char)c;
	sr = (const unsigned char *)s;
	while (n--)
	{
		if (*sr == uc)
			return ((void *)sr);
		++sr;
	}
	return (0);
}

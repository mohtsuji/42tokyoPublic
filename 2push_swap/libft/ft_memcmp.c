/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:17:26 by tiwai             #+#    #+#             */
/*   Updated: 2021/04/18 10:44:57 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sf;
	const unsigned char	*sc;

	sf = (const unsigned char *)s1;
	sc = (const unsigned char *)s2;
	while (n--)
	{
		if (*sf != *sc)
			return (*sf - *sc);
		++sf;
		++sc;
	}
	return (0);
}

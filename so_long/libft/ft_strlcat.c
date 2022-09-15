/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:19:13 by tiwai             #+#    #+#             */
/*   Updated: 2020/06/26 16:30:20 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		o_dsize;
	int			atmost;
	char		*p;
	const char	*s;

	o_dsize = ft_strlen(dst);
	p = dst + o_dsize;
	s = src;
	atmost = dstsize - o_dsize - 1;
	if (o_dsize >= dstsize)
		return (dstsize + ft_strlen(src));
	while (atmost-- > 0 && *s)
	{
		*p = *s;
		++p;
		++s;
	}
	*p = '\0';
	return (o_dsize + ft_strlen(src));
}

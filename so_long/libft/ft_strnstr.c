/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:10:42 by tiwai             #+#    #+#             */
/*   Updated: 2021/04/18 10:40:07 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;
	const char	*ans;

	h = haystack;
	if (!ft_strlen(needle))
		return ((char *)h);
	while (*h && h < haystack + len)
	{
		ans = h;
		n = needle;
		while (*h == *n && *h && *n && h < haystack + len)
		{
			++h;
			++n;
		}
		if (!*n)
			return ((char *)ans);
		h = ans;
		++h;
	}
	return (0);
}

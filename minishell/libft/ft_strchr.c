/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 20:35:26 by tiwai             #+#    #+#             */
/*   Updated: 2020/06/26 16:29:09 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		cc;
	const char	*ss;

	ss = s;
	cc = (char)c;
	while (*ss)
	{
		if (*ss == cc)
			return ((char *)ss);
		++ss;
	}
	if (cc == '\0')
		return ((char *)ss);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 20:55:29 by tiwai             #+#    #+#             */
/*   Updated: 2020/06/26 16:32:16 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		cc;
	const char	*ss;
	const char	*find;

	ss = s;
	cc = (char)c;
	find = 0;
	while (*ss)
	{
		if (*ss == cc && find < ss)
			find = ss;
		++ss;
	}
	if (c == '\0')
		return ((char *)ss);
	if (find)
		return ((char *)find);
	return (0);
}

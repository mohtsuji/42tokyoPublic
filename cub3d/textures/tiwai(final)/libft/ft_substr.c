/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 14:31:20 by tiwai             #+#    #+#             */
/*   Updated: 2020/07/16 16:58:15 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*new;
	unsigned int		i;

	if (!s)
		return (0);
	if (ft_strlen(s) - 1 < start)
	{
		if (!(new = (char *)ft_calloc(1, sizeof(char))))
			return (0);
		return (new);
	}
	if (!(new = (char *)ft_calloc(len + 1, sizeof(char))))
		return (0);
	i = 0;
	while (len--)
	{
		if (s[start] == '\0')
			break ;
		new[i] = s[start];
		++i;
		++start;
	}
	return (new);
}

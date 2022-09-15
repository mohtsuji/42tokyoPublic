/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:57:57 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/06 19:30:41 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	if (c == '\0')
		return ((char *)s + len);
	while (len - 1 != -1)
	{
		if (s[len - 1] == c)
		{
			return ((char *)s + len - 1);
		}
		len--;
	}
	return (NULL);
}

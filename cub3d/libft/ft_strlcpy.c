/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:10:26 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/05 14:48:08 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	int		i;
	size_t	result;

	if (dest == NULL || src == NULL)
		return (0);
	i = 0;
	if (n != 0)
	{
		while (n - 1 != 0 && src[i] != 0)
		{
			dest[i] = src[i];
			i++;
			n--;
		}
		dest[i] = 0;
	}
	result = ft_strlen(src);
	return (result);
}

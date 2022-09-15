/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:36:38 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/05 22:39:16 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*dest;
	size_t			total;
	int				i;

	i = 0;
	total = n * size;
	dest = malloc(total);
	if (dest == NULL)
		return (NULL);
	while (total--)
	{
		dest[i] = 0;
		i++;
	}
	return ((void *)dest);
}

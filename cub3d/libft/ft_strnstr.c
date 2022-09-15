/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:10:33 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/06 23:40:51 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while ((int)len-- && big[i] != 0)
	{
		while (big[i + j] == little[j]
				&& ((int)len - (n - 1)) && big[i + j] != 0)
		{
			j++;
			n++;
		}
		if (little[j] == 0)
			return ((char *)big + i);
		i++;
		j = 0;
		n = 0;
	}
	return (NULL);
}

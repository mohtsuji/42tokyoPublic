/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 10:41:52 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/04 19:44:01 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *buf, int ch, size_t n)
{
	int				i;
	unsigned char	j;
	unsigned char	*result;

	i = 0;
	j = ch;
	result = buf;
	while (n != 0)
	{
		result[i] = j;
		i++;
		n--;
	}
	return (buf);
}

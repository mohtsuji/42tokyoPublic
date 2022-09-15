/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:38:25 by tiwai             #+#    #+#             */
/*   Updated: 2021/04/18 14:28:54 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*first;
	const unsigned char	*second;

	first = (const unsigned char *)s1;
	second = (const unsigned char *)s2;
	while (n--)
	{
		if (*first != *second)
			return ((int)(*first - *second));
		if (*first == '\0')
			break ;
		++first;
		++second;
	}
	return (0);
}

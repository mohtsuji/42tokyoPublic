/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 14:13:55 by tiwai             #+#    #+#             */
/*   Updated: 2020/07/02 10:13:18 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;
	size_t	count;

	count = ft_strlen(s1) + 1;
	if (!(new = (char *)ft_calloc(count, sizeof(char))))
		return (0);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		++i;
	}
	return (new);
}

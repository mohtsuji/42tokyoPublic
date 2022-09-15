/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 15:16:04 by tiwai             #+#    #+#             */
/*   Updated: 2020/09/03 15:48:24 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	fullsize;
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	fullsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new = (char *)ft_calloc(fullsize, sizeof(char))))
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	return (new);
}

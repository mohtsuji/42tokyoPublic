/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:32:16 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/04 00:57:28 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_main(char const *s, unsigned int start, size_t len, int h)
{
	char	*hako;
	int		i;

	i = start;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	else if (ft_strlen(s) - start + 1 < len)
		len = ft_strlen(s) - start;
	if (!(hako = malloc(len + 1)))
		return (NULL);
	while (s[i] != 0 && len-- != 0)
		hako[h++] = s[i++];
	hako[h] = 0;
	return (hako);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int	h;

	h = 0;
	return (ft_substr_main(s, start, len, h));
}

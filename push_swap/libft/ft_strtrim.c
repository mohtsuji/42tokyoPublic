/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 15:35:46 by tiwai             #+#    #+#             */
/*   Updated: 2021/04/18 14:29:49 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1)
		return (0);
	start = 0;
	end = (int)ft_strlen(s1) - 1;
	if (start > end)
		return ((char *)s1);
	while (ft_strchr(set, s1[start]))
		++start;
	while (ft_strchr(set, s1[end]) && start <= end)
		--end;
	return (ft_substr(s1, start, end - start + 1));
}

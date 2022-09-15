/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:57:31 by tiwai             #+#    #+#             */
/*   Updated: 2021/04/18 14:31:26 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	const char	*s;
	int			ans;
	int			sign;

	s = str;
	ans = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
	*s == '\v' || *s == '\f' || *s == '\r')
		++s;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	while (*s)
	{
		if (*s < '0' || *s > '9')
			break ;
		ans = ans * 10 + (*s - '0');
		++s;
	}
	return (sign * ans);
}

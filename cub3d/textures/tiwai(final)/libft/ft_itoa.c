/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:43:44 by tiwai             #+#    #+#             */
/*   Updated: 2020/06/28 15:22:26 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long long num)
{
	int ans;

	if (num == 0)
		return (1);
	ans = 0;
	while (num != 0)
	{
		num /= 10;
		++ans;
	}
	return (ans);
}

static char	*make_str(long long num, int len, int sign)
{
	char	*str;
	int		i;

	if (!(str = (char *)ft_calloc(len, sizeof(char))))
		return (0);
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	i = len - 2;
	while (num != 0)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
		--i;
	}
	if (sign < 0)
		str[i] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	long long	num;
	int			len;
	int			sign;

	sign = 1;
	num = n;
	if (n < 0)
	{
		sign = -1;
		num *= -1;
		len = count_digits(num) + 2;
	}
	else
		len = count_digits(num) + 1;
	return (make_str(num, len, sign));
}

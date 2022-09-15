/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 07:35:32 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/15 07:37:02 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_reverse(char *str)
{
	int		len;
	int		count;
	int		i;
	char	c;

	i = 0;
	len = ft_strlen(str);
	count = len;
	while (i < (len / 2))
	{
		c = str[i];
		str[i] = str[count - 1];
		str[count - 1] = c;
		i++;
		count--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		i;
	long	nb;
	int		len;

	nb = n;
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	len = ft_count(n);
	i = 0;
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n < 0)
	{
		result[len - 1] = '-';
		nb = (nb * -1);
	}
	while (nb != 0)
	{
		result[i++] = (nb % 10) + 48;
		nb = nb / 10;
	}
	result[len] = '\0';
	ft_reverse(result);
	return (result);
}

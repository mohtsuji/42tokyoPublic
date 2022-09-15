/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:16:01 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/02/01 13:35:17 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_newatoi(char *str)
{
	int		i;
	long	nb;
	int		count;

	count = 0;
	i = 0;
	nb = 0;
	while (str[i] == ' ')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
		count++;
	}
	if (count > 10)
		return (-2);
	if (count == 10 && nb > 2147483647)
		return (-2);
	while (str[i] == ' ')
		i++;
	if (str[i] != 0)
		return (-1);
	return (nb);
}

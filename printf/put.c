/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 05:25:28 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/19 19:40:41 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_sign	*ft_clean(t_sign *sign)
{
	sign->zero = 0;
	sign->mi = 0;
	sign->pre = 0;
	sign->p = 0;
	sign->width = 0;
	sign->w = 0;
	sign->x = 0;
	sign->neg = 0;
	return (sign);
}

void	put_zero(t_sign *sign)
{
	char	c;

	c = '0';
	while (sign->pre > 0)
	{
		write(1, &c, 1);
		sign->pre--;
		sign->count++;
	}
}

void	put_space(t_sign *sign)
{
	char	c;

	if (sign->zero == 0)
		c = ' ';
	else
		c = '0';
	while (sign->width > 0)
	{
		write(1, &c, 1);
		sign->width--;
		sign->count++;
	}
}

void	put_char(t_sign *sign, char **tmp)
{
	write(1, *tmp, 1);
	(*tmp)++;
	sign->count++;
}

void	put_mi(t_sign *sign, char **tmp)
{
	char	c;

	c = '-';
	write(1, &c, 1);
	sign->count++;
	(*tmp)++;
}

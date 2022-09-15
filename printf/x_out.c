/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_out.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 01:53:14 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/19 05:33:23 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_change(int henka, char *tmp, int size, t_sign *sign)
{
	if (0 <= henka && henka <= 9)
		tmp[size] = henka + 48;
	if (sign->x == 0)
	{
		if (10 <= henka && henka <= 15)
			tmp[size] = henka + 87;
	}
	if (sign->x == 1)
	{
		if (10 <= henka && henka <= 15)
			tmp[size] = henka + 55;
	}
}

static int		get_len(unsigned int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

static t_sign	*nullsyori(t_sign *sign)
{
	if (sign->w == 0)
		return (sign);
	else
	{
		put_space(sign);
		return (sign);
	}
}

static void		henkan(t_sign *sign, int *size, unsigned int *n, char *tmp)
{
	int	henka;

	henka = *n % 16;
	*n = *n / 16;
	(*size)--;
	ft_change(henka, tmp, *size, sign);
}

t_sign			*x_out(t_sign *sign, va_list ap)
{
	unsigned int	n;
	char			tmp[20];
	int				size;
	int				size2;

	if (sign->p == 1)
		sign->zero = 0;
	size = 0;
	n = va_arg(ap, unsigned int);
	if (sign->p == 1 && sign->pre == 0 && n == 0)
		return (nullsyori(sign));
	while (size < 20)
		tmp[size++] = '\0';
	if (n == 0)
	{
		tmp[0] = '0';
		return (x_hontai(sign, tmp, 1));
	}
	size = get_len(n);
	size2 = size;
	while (n > 0)
		henkan(sign, &size, &n, tmp);
	return (x_hontai(sign, tmp, size2));
}

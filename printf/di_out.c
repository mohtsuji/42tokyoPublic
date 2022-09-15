/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 05:34:42 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/19 20:10:10 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_len(long n, t_sign *sign)
{
	int	size;

	size = 0;
	if (sign->neg == 1)
		size++;
	while (n > 0)
	{
		n = n / 10;
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

static void		henkan(int *size, long *n, char *tmp)
{
	int	henka;

	henka = *n % 10;
	*n = *n / 10;
	(*size)--;
	tmp[*size] = henka + '0';
}

static void		negasyori(t_sign *sign, long *n)
{
	sign->neg = 1;
	*n = *n * -1;
}

t_sign			*di_out(t_sign *sign, va_list ap)
{
	long	num;
	char	tmp[15];
	int		size;
	int		size2;

	size = 0;
	num = (long)va_arg(ap, int);
	if (sign->p == 1 && sign->pre == 0 && num == 0)
		return (nullsyori(sign));
	while (size < 15)
		tmp[size++] = '\0';
	if (num == 0)
	{
		tmp[0] = '0';
		return (di_hontai(sign, tmp, 1));
	}
	if (num < 0)
		negasyori(sign, &num);
	size = get_len(num, sign);
	size2 = size;
	if (sign->neg == 1)
		tmp[0] = '-';
	while (num > 0)
		henkan(&size, &num, tmp);
	return (di_hontai(sign, tmp, size2));
}

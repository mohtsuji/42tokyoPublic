/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_out.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 23:51:14 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/19 19:19:52 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int		get_len(unsigned int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void		henkan(int *size, unsigned int *n, char *tmp)
{
	int	henka;

	henka = *n % 10;
	*n = *n / 10;
	(*size)--;
	tmp[*size] = henka + '0';
}

t_sign			*u_out(t_sign *sign, va_list ap)
{
	unsigned int	num;
	char			tmp[15];
	int				size;
	int				size2;

	size = 0;
	num = va_arg(ap, unsigned int);
	if (sign->p == 1 && sign->pre == 0 && num == 0)
		return (nullsyori(sign));
	while (size < 15)
		tmp[size++] = '\0';
	if (num == 0)
	{
		tmp[0] = '0';
		return (u_hontai(sign, tmp, 1));
	}
	size = get_len(num);
	size2 = size;
	while (num > 0)
		henkan(&size, &num, tmp);
	return (u_hontai(sign, tmp, size2));
}

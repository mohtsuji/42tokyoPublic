/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_out.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 05:13:00 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/19 05:43:23 by mohtsuji         ###   ########.fr       */
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

static int		get_len(unsigned long n)
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

static void		henkan(t_sign *sign, int *size, unsigned long *n, char *tmp)
{
	int	henka;

	henka = *n % 16;
	*n = *n / 16;
	(*size)--;
	ft_change(henka, tmp, *size, sign);
}

t_sign			*p_out(t_sign *sign, va_list ap)
{
	unsigned long	n;
	int				size;
	int				size2;
	char			tmp[20];

	if (sign->mi == 1)
		sign->zero = 0;
	n = (unsigned long)va_arg(ap, void*);
	size = 0;
	while (size < 20)
		tmp[size++] = '\0';
	if (sign->p == 1 && sign->pre == 0 && n == 0)
		return (p_hontai(sign, tmp, 0));
	if (n == 0)
	{
		tmp[0] = '0';
		return (p_hontai(sign, tmp, 1));
	}
	size = get_len(n);
	size2 = size;
	while (n > 0)
		henkan(sign, &size, &n, tmp);
	return (p_hontai(sign, tmp, size2));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hontai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 04:16:44 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/19 05:36:25 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_sign	*no_p(t_sign *sign, char *tmp, int size)
{
	if (sign->mi == 0)
	{
		sign->width -= size;
		put_space(sign);
		while (*tmp)
			put_char(sign, &tmp);
	}
	else
	{
		sign->zero = 0;
		while (*tmp)
		{
			put_char(sign, &tmp);
			sign->width--;
		}
		put_space(sign);
	}
	return (sign);
}

static t_sign	*yes_wp(t_sign *sign, char *tmp, int size)
{
	if (sign->pre > size)
		sign->width -= sign->pre;
	else
		sign->width -= size;
	sign->pre -= size;
	if (sign->mi == 0)
	{
		put_space(sign);
		put_zero(sign);
		while (*tmp)
			put_char(sign, &tmp);
	}
	else
	{
		sign->zero = 0;
		put_zero(sign);
		while (*tmp)
			put_char(sign, &tmp);
		put_space(sign);
	}
	return (sign);
}

static t_sign	*no_w(t_sign *sign, char *tmp, int size)
{
	sign->pre -= size;
	put_zero(sign);
	while (*tmp)
		put_char(sign, &tmp);
	return (sign);
}

t_sign			*x_hontai(t_sign *sign, char *tmp, int size)
{
	if (sign->w == 0)
		return (no_w(sign, tmp, size));
	else if (sign->p == 0)
		return (no_p(sign, tmp, size));
	else
		return (yes_wp(sign, tmp, size));
}

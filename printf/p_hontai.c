/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hontai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:57:14 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/19 06:00:40 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_0x(char *str, t_sign *sign)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	sign->count += 2;
}

static t_sign	*no_w(t_sign *sign, char *tmp)
{
	put_0x("0x", sign);
	if (sign->pre > 0)
		put_zero(sign);
	while (*tmp)
		put_char(sign, &tmp);
	return (sign);
}

static t_sign	*no_p(t_sign *sign, char *tmp)
{
	if (sign->mi == 0)
	{
		if (sign->zero == 1)
			put_0x("0x", sign);
		put_space(sign);
		if (sign->zero == 0)
			put_0x("0x", sign);
		while (*tmp)
			put_char(sign, &tmp);
	}
	else
	{
		put_0x("0x", sign);
		while (*tmp)
			put_char(sign, &tmp);
		put_space(sign);
	}
	return (sign);
}

static t_sign	*yes_wp(t_sign *sign, char *tmp)
{
	if (sign->pre > 0)
		sign->width -= sign->pre;
	if (sign->mi == 0)
	{
		if (sign->zero == 1)
			put_0x("0x", sign);
		put_space(sign);
		if (sign->zero == 0)
			put_0x("0x", sign);
		put_zero(sign);
		while (*tmp)
			put_char(sign, &tmp);
	}
	else
	{
		put_0x("0x", sign);
		put_zero(sign);
		while (*tmp)
			put_char(sign, &tmp);
		put_space(sign);
	}
	return (sign);
}

t_sign			*p_hontai(t_sign *sign, char *tmp, int size)
{
	sign->width = sign->width - size - 2;
	sign->pre = sign->pre - size;
	if (sign->w == 0)
		return (no_w(sign, tmp));
	else if (sign->p == 0)
		return (no_p(sign, tmp));
	else if (sign->w == 1)
		return (yes_wp(sign, tmp));
	return (sign);
}

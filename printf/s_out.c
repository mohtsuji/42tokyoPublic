/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_out.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 01:18:19 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/19 03:59:00 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_sign	*no_w(t_sign *sign, char **tmp)
{
	if (sign->p == 0)
	{
		while (**tmp)
			put_char(sign, tmp);
	}
	else if (sign->p == 1)
	{
		while (**tmp && sign->pre > 0)
		{
			put_char(sign, tmp);
			sign->pre--;
		}
	}
	return (sign);
}

static t_sign	*no_p(t_sign *sign, char **tmp, int size)
{
	if (sign->mi == 1)
	{
		sign->zero = 0;
		while (**tmp && sign->width > 0)
		{
			put_char(sign, tmp);
			sign->width--;
		}
		while (**tmp)
			put_char(sign, tmp);
		put_space(sign);
	}
	else
	{
		sign->width -= size;
		put_space(sign);
		while (**tmp)
			put_char(sign, tmp);
	}
	return (sign);
}

static t_sign	*yes_wp(t_sign *sign, char **tmp, int size)
{
	if (size > sign->pre)
		size = sign->pre;
	sign->width -= size;
	if (sign->mi == 0)
	{
		put_space(sign);
		while (size > 0)
		{
			put_char(sign, tmp);
			size--;
		}
	}
	else
	{
		sign->zero = 0;
		while (size > 0)
		{
			put_char(sign, tmp);
			size--;
		}
		put_space(sign);
	}
	return (sign);
}

t_sign			*s_out(t_sign *sign, va_list ap)
{
	char	*tmp;
	int		size;

	tmp = va_arg(ap, char *);
	if (tmp == NULL)
		tmp = "(null)";
	size = ft_strlen(tmp);
	if (sign->pre < 0)
		sign->p = 0;
	if (sign->w == 0)
		return (no_w(sign, &tmp));
	else if (sign->p == 0)
		return (no_p(sign, &tmp, size));
	else
		return (yes_wp(sign, &tmp, size));
	return (sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:42:48 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/11/15 21:33:00 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_sign	*ft_flag2(t_sign *sign, va_list ap)
{
	if (ft_strchr("123456789", *sign->str))
	{
		sign->w = 1;
		sign->width = ft_atoi(&sign->str);
	}
	if (*sign->str == '.')
	{
		sign->p = 1;
		sign->str++;
		if (*sign->str == '*')
		{
			sign->pre = va_arg(ap, int);
			sign->str++;
		}
		if (ft_strchr("0123456789", *sign->str))
			sign->pre = ft_atoi(&sign->str);
	}
	return (sign);
}

static t_sign	*ft_flag(t_sign *sign, va_list ap)
{
	while (*sign->str == '-' || *sign->str == '0')
	{
		if (*sign->str == '-')
			sign->mi = 1;
		if (*sign->str == '0')
			sign->zero = 1;
		sign->str++;
	}
	if (*sign->str == '*')
	{
		sign->w = 1;
		sign->width = va_arg(ap, int);
		if (sign->width < 0)
		{
			sign->mi = 1;
			sign->width = sign->width * -1;
		}
		sign->str++;
	}
	ft_flag2(sign, ap);
	return (sign);
}

static t_sign	*henkan(t_sign *sign, va_list ap)
{
	sign->str++;
	if (ft_strchr("-0123456789*.", *sign->str))
		sign = ft_flag(sign, ap);
	if (*sign->str == 'c')
		c_out(sign, ap);
	if (*sign->str == 's')
		s_out(sign, ap);
	if (*sign->str == 'd' || *sign->str == 'i')
		di_out(sign, ap);
	if (*sign->str == 'u')
		u_out(sign, ap);
	if (*sign->str == '%')
		pa_out(sign);
	if (*sign->str == 'x' || *sign->str == 'X')
	{
		if (*sign->str == 'X')
			sign->x = 1;
		x_out(sign, ap);
	}
	if (*sign->str == 'p')
		p_out(sign, ap);
	(*sign->str) ? sign->str++ : 0;
	return (sign);
}

static void		loop(t_sign *sign, va_list ap)
{
	if (*sign->str == '%')
	{
		ft_clean(sign);
		sign = henkan(sign, ap);
	}
	if (*sign->str != '\0' && *sign->str != '%')
	{
		write(1, sign->str, 1);
		sign->count++;
		sign->str++;
	}
}

int				ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_sign	*sign;
	int		cnt;

	if (!(sign = malloc(sizeof(t_sign))))
		return (-1);
	va_start(ap, fmt);
	sign->str = (char *)fmt;
	sign->count = 0;
	while (*sign->str)
		loop(sign, ap);
	va_end(ap);
	cnt = sign->count;
	free(sign);
	return (cnt);
}

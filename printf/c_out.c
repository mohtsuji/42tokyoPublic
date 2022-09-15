/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_out.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:52:06 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/17 23:27:43 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_sign	*c_out(t_sign *sign, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	if (sign->p == 1 && c == 0 && sign->pre == 0)
	{
		write(1, &c, 1);
		sign->count++;
		return (sign);
	}
	if (sign->width > 0)
		sign->width -= 1;
	if (sign->mi == 1)
	{
		sign->zero = 0;
		write(1, &c, 1);
		sign->count++;
		put_space(sign);
	}
	else
	{
		put_space(sign);
		write(1, &c, 1);
		sign->count++;
	}
	return (sign);
}

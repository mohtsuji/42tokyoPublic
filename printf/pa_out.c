/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 01:40:02 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/18 01:46:46 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_sign	*pa_out(t_sign *sign)
{
	char	c;

	c = '%';
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

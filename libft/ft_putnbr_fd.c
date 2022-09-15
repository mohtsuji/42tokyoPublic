/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 08:00:29 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/07/15 08:04:00 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	i;

	c = '-';
	if (n < 0)
	{
		write(fd, &c, 1);
		i = (unsigned int)(n * -1);
	}
	else
		i = (unsigned int)n;
	if (i >= 10)
	{
		c = (i % 10) + 48;
		i = i / 10;
		ft_putnbr_fd(i, fd);
		write(fd, &c, 1);
	}
	else if (i < 10)
	{
		c = (i + 48);
		write(fd, &c, 1);
	}
}

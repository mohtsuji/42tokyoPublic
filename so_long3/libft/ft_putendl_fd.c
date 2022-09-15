/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:49:34 by tiwai             #+#    #+#             */
/*   Updated: 2021/04/18 10:51:31 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*str;

	if (!s)
		return ;
	str = s;
	while (*str)
	{
		write(fd, str, sizeof(*str));
		++str;
	}
	write(fd, "\n", sizeof(char));
}

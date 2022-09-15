/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:49:51 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/17 20:34:06 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*xmalloc(size_t size)
{
	void	*ans;

	ans = malloc(size);
	if (ans == NULL)
		put_error("Error\nmalloc error in xmalloc\n");
	return (ans);
}
/*
void	*safe_calloc(size_t count, size_t size)
{
	void	*ans;

	ans = ft_calloc(count, size);
	if (ans == NULL)
		exit(EXIT_FAILURE);
	return (ans);
}*/

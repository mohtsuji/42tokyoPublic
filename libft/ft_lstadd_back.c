/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 02:09:04 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/03 23:15:11 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	tmp = (*lst);
	(*lst) = ft_lstlast((*lst));
	(*lst)->next = new;
	(*lst) = tmp;
}

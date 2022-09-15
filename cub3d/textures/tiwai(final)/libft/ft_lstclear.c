/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:49:45 by tiwai             #+#    #+#             */
/*   Updated: 2020/07/02 10:40:38 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *nextl;

	if (!lst || !*lst || !del)
		return ;
	while (*lst != NULL)
	{
		nextl = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nextl;
	}
	lst = NULL;
}

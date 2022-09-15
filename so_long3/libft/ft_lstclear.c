/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:49:45 by tiwai             #+#    #+#             */
/*   Updated: 2021/04/18 10:45:42 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextl;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:19:25 by tiwai             #+#    #+#             */
/*   Updated: 2020/07/02 11:26:29 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *current;
	t_list *head;
	t_list *new;

	if (!lst || !f)
		return (0);
	if (!(head = ft_lstnew(f(lst->content))))
		return (0);
	current = lst->next;
	while (current != NULL)
	{
		if (!(new = ft_lstnew(f(current->content))))
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, new);
		current = current->next;
	}
	return (head);
}

#include "utls.h"

int	dlist_size(t_dlist *lst)
{
	int	size;

	size = 0;
	if (lst == NULL)
		return (0);
	while (lst->prev != NULL)
		lst = lst->prev;
	while (lst != NULL)
	{
		++size;
		lst = lst->next;
	}
	return (size);
}

t_dlist	*dlstlast(t_dlist *lst)
{
	t_dlist	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

void	dlstdelone(t_dlist *lst)
{
	if (!lst)
		return ;
	else
	{
		free(lst->data);
		lst->next = NULL;
		lst->prev = NULL;
		free(lst);
		lst = NULL;
		return ;
	}
}

void	dlstclear(t_dlist **lst)
{
	t_dlist	*nextl;

	if (!lst || !*lst)
		return ;
	while (*lst != NULL)
	{
		nextl = (*lst)->next;
		dlstdelone(*lst);
		*lst = nextl;
	}
	lst = NULL;
}

char	**list_to_array(t_dlist *lst)
{
	int		size;
	char	**arr;
	int		i;

	if (lst == NULL)
		return (NULL);
	i = 0;
	size = dlist_size(lst);
	arr = (char **)xmalloc((size + 1) * sizeof(char *));
	while (lst != NULL)
	{
		arr[i] = safe_dup((char *)lst->data);
		i++;
		lst = lst->next;
	}
	arr[i] = NULL;
	return (arr);
}

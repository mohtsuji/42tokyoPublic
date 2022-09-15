#include "../push_swap.h"
#include "../libft/libft.h"

t_str	*str_lstnew(long num)
{
	t_str	*new;

	new = (t_str *)xmalloc(sizeof(t_str));
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_str	*str_getlast(t_str *init_a)
{
	t_str	*current;

	current = init_a;
	while (1)
	{
		if (current->next == NULL)
			return (init_a);
		current = current->next;
		if (current == init_a)
			return (current);
	}
}

t_str	*str_lstlast(t_str *lst)
{
	t_str	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	str_lstadd_back(t_str **lst, t_str *n)
{
	t_str	*last;

	last = str_lstlast(*lst);
	if (last)
	{
		last->next = n;
		n->prev = last;
	}
	else
		*lst = n;
}

void	str_lstclear(t_str **head)
{
	t_str	*now;
	t_str	*nxt;
	t_str	*last;

	exit(1);
	last = str_getlast(*head);
	now = *head;
	while (now != last)
	{
		nxt = now->next;
		now->next = NULL;
		now->prev = NULL;
		free(now);
		now = NULL;
		now = nxt;
	}
	free(last);
}

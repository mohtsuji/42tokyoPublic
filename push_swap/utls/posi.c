#include "../push_swap.h"
#include "../libft/libft.h"

t_posi	*posi_lstpre(t_posi *posi)
{
	t_posi	*current;
	t_posi	*pre;

	if (!posi)
		return (NULL);
	current = posi;
	while (current->next != NULL)
	{
		pre = current;
		current = current->next;
	}
	return (pre);
}

void	posi_lastclear(t_posi **posi)
{
	t_posi	*last;
	t_posi	*first;
	t_posi	*last_pre;

	first = *posi;
	last = posi_lstlast(*posi);
	if (first == last)
	{
		free(last);
		*posi = NULL;
	}
	else
	{
		last_pre = posi_lstpre(*posi);
		free(last);
		last_pre->next = NULL;
	}
}

t_posi	*posi_lstnew(int size)
{
	t_posi	*new;

	new = (t_posi *)xmalloc(sizeof(t_posi));
	new->size = size;
	new->next = NULL;
	return (new);
}

t_posi	*posi_lstlast(t_posi *posi)
{
	t_posi	*current;

	if (!posi)
		return (NULL);
	current = posi;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	posi_lstadd_back(t_posi **posi, int size)
{
	t_posi	*last;
	t_posi	*new;

	new = posi_lstnew(size);
	last = posi_lstlast(*posi);
	if (last)
		last->next = new;
	else
		*posi = new;
}

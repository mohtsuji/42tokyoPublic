#include "../push_swap.h"
#include "../libft/libft.h"

t_ope	*ope_lstnew(char *ope)
{
	t_ope	*new;

	new = (t_ope *)xmalloc(sizeof(t_ope));
	new->ope = ope;
	new->next = NULL;
	return (new);
}

t_ope	*tool_lstlast(t_ope *ope)
{
	t_ope	*current;

	if (!ope)
		return (NULL);
	current = ope;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	tool_lstadd_back(t_tool *tool, char *ope)
{
	t_ope	*last;
	t_ope	*new;

	new = ope_lstnew(ope);
	last = tool_lstlast(tool->ope);
	if (last)
		last->next = new;
	else
		tool->ope = new;
}

void	ope_lstclear(t_ope **head)
{
	t_ope	*now;
	t_ope	*nxt;

	now = *head;
	while (now != NULL)
	{
		nxt = now->next;
		now->next = NULL;
		free(now);
		now = nxt;
	}
}

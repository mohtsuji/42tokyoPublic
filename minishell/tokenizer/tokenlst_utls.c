#include "tokenizer.h"

t_token	*token_lstnew(size_t len)
{
	t_token	*new;

	new = (t_token *)xmalloc(sizeof(t_token));
	new->str = (char *)ft_calloc((len + 1), sizeof(char));
	if (new->str == NULL)
		return (0);
	new->next = NULL;
	new->prev = NULL;
	new->type = -1;
	return (new);
}

t_token	*token_lstlast(t_token *lst)
{
	t_token	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	token_lstadd_back(t_token **lst, t_token *newlst)
{
	t_token	*last;

	last = token_lstlast(*lst);
	if (last)
		last->next = newlst;
	else
		*lst = newlst;
}

int	token_lstsize(t_token *lst)
{
	t_token	*current;
	int		size;

	current = lst;
	size = 0;
	while (current != NULL)
	{
		++size;
		current = current->next;
	}
	return (size);
}

void	token_lstclear(t_token **head)
{
	t_token	*now;
	t_token	*nxt;

	now = *head;
	while (now != NULL)
	{
		nxt = now->next;
		free(now->str);
		now->str = NULL;
		now->next = NULL;
		now->prev = NULL;
		free(now);
		now = NULL;
		now = nxt;
	}
}

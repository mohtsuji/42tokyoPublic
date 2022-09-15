#include "../includes/minishell.h"

t_env	*env_lstnew(char *str, int flag)
{
	t_env	*new;

	new = (t_env *)xmalloc(sizeof(t_env));
	get_key_value(str, &(new->key), &(new->value), flag);
	new->equal = 0;
	if (ft_strchr(str, '=') != NULL)
		new->equal = 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_env	*env_lstlast(t_env *lst)
{
	t_env	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	env_lstadd_back(t_env **lst, t_env *n)
{
	t_env	*last;

	last = env_lstlast(*lst);
	if (last)
	{
		last->next = n;
		n->prev = last;
	}
	else
		*lst = n;
}

int	env_lstsize(t_env *lst)
{
	t_env	*current;
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

void	env_lstclear(t_env **head)
{
	t_env	*now;
	t_env	*nxt;

	now = *head;
	while (now != NULL)
	{
		nxt = now->next;
		free(now->key);
		free(now->value);
		now->key = NULL;
		now->value = NULL;
		now->next = NULL;
		now->prev = NULL;
		free(now);
		now = NULL;
		now = nxt;
	}
}

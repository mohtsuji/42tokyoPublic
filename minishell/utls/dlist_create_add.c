#include "utls.h"

void	dlstadd_back(t_dlist **lst, t_dlist *n)
{
	t_dlist	*last;

	if (*lst == NULL)
	{
		*lst = n;
		return ;
	}
	last = dlstlast(*lst);
	if (last)
	{
		last->next = n;
		n->prev = last;
	}
}

void	addback_elm_with_data(t_dlist **head, char *s1, char *s2)
{
	t_dlist	*elm;
	char	*str;

	str = safe_join(s1, s2);
	elm = create_elm(str);
	dlstadd_back(head, elm);
}

t_dlist	*create_elm(void *d)
{
	t_dlist	*elm;

	elm = (t_dlist *)xmalloc(sizeof(t_dlist));
	elm->data = d;
	elm->next = NULL;
	elm->prev = NULL;
	return (elm);
}

t_dlist	*create_elm_strdup(char *d)
{
	t_dlist	*elm;

	elm = (t_dlist *)xmalloc(sizeof(t_dlist));
	elm->data = (void *)safe_dup(d);
	elm->next = NULL;
	elm->prev = NULL;
	return (elm);
}

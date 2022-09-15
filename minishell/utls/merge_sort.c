#include "utls.h"

static int	ft_strcmp(char *s, char *f)
{
	unsigned char	*fst;
	unsigned char	*scd;

	fst = (unsigned char *)s;
	scd = (unsigned char *)f;
	while (*fst == *scd)
	{
		if (*fst == '\0')
			return (*fst - *scd);
		++fst;
		++scd;
	}
	return (*fst - *scd);
}

static void	split(t_env **a, t_env **b)
{
	int		total;
	int		count;
	t_env	*half;

	total = env_lstsize(*a);
	count = 1;
	half = *a;
	while (count < total / 2)
	{	
		half = half->next;
		++count;
	}
	*b = half->next;
	half->next = NULL;
}

static t_env	*merge(t_env *a, t_env *b)
{
	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	if (ft_strcmp(a->key, b->key) > 0)
	{
		b->next = merge(a, b->next);
		b->next->prev = b;
		b->prev = NULL;
		return (b);
	}
	else
	{
		a->next = merge(a->next, b);
		a->next->prev = a;
		a->prev = NULL;
		return (a);
	}
}

void	list_mergesort(t_env **head)
{
	t_env	*a;
	t_env	*b;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	a = *head;
	b = NULL;
	split(&a, &b);
	list_mergesort(&a);
	list_mergesort(&b);
	*head = merge(a, b);
}

void	sort_if_needed(t_env **head, t_env *list)
{
	_Bool	need;

	need = false;
	while (list->next != NULL)
	{
		if (ft_strcmp(list->key, list->next->key) > 0)
		{
			need = true;
			break ;
		}
		list = list->next;
	}
	if (need)
		list_mergesort(head);
}

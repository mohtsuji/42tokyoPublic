#include "parcer.h"

t_ast	*list_semicolon(t_token **lst)
{
	t_ast	*node;
	t_ast	*first;
	t_ast	*second;

	first = pipeline(lst);
	if (first == NULL)
		return (NULL);
	if ((*lst)->type != SEMICOLON)
	{
		ast_clear(&first);
		return (NULL);
	}
	*lst = (*lst)->next;
	second = list(lst);
	if (second == NULL)
	{
		ast_clear((&first));
		return (NULL);
	}
	node = make_node(";", SEMICOLON);
	node_add(node, first, second);
	return (node);
}

t_ast	*list(t_token **lst)
{
	t_token	*save;
	t_ast	*node;

	save = *lst;
	node = list_semicolon(lst);
	if (node != NULL)
		return (node);
	*lst = save;
	node = pipeline(lst);
	if (node != NULL)
		return (node);
	return (NULL);
}

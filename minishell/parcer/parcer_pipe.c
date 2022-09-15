#include "parcer.h"

t_ast	*pipe_inbetween(t_token **lst)
{
	t_ast	*node;
	t_ast	*first;
	t_ast	*second;

	first = command(lst);
	if (first == NULL)
		return (NULL);
	if ((*lst) != NULL && (*lst)->type != PIPE)
	{
		ast_clear(&first);
		return (NULL);
	}
	*lst = (*lst)->next;
	second = pipeline(lst);
	if (second == NULL)
	{
		ast_clear(&first);
		return (NULL);
	}
	node = make_node("|", PIPE);
	node_add(node, first, second);
	return (node);
}

t_ast	*pipeline(t_token **lst)
{
	t_ast	*node;
	t_token	*save;

	save = *lst;
	node = pipe_inbetween(lst);
	if (node != NULL)
		return (node);
	*lst = save;
	node = command(lst);
	if (node != NULL)
		return (node);
	return (NULL);
}

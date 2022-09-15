#include "parcer.h"

t_ast	*cmmd_line_endsemicolon(t_token **lst)
{
	t_ast	*node;
	t_ast	*list_node;

	list_node = list(lst);
	if (!list_node)
		return (NULL);
	if ((*lst) == NULL || (*lst)->type != SEMICOLON || \
	((*lst)->next != NULL && (*lst)->next->type != -1))
	{
		ast_clear(&list_node);
		return (NULL);
	}
	node = make_node(";", SEMICOLON);
	node_add(node, list_node, NULL);
	return (node);
}

t_ast	*cmmd_line_simple(t_token **lst)
{
	t_ast	*node;

	node = list(lst);
	if ((*lst) != NULL && (*lst)->type != -1)
	{
		ast_clear(&node);
		return (NULL);
	}
	return (node);
}

t_ast	*cmmd_line(t_token **lst)
{
	t_token	*save;
	t_ast	*node;

	save = *lst;
	node = cmmd_line_endsemicolon(lst);
	if (node != NULL)
		return (node);
	*lst = save;
	node = cmmd_line_simple(lst);
	if (node == NULL || (*lst) == NULL || \
	((*lst)->next != NULL && (*lst)->next->type != -1))
	{
		ast_clear(&node);
		put_error(lst);
		return (NULL);
	}
	return (node);
}

_Bool	parcer(t_token *token_list, t_ast **ast)
{
	t_token	*now;

	if (token_lstsize(token_list) == 0)
		return (false);
	now = token_list;
	*ast = cmmd_line(&now);
	if (*ast == NULL)
		return (false);
	return (true);
}

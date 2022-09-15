#include "parcer.h"

t_ast	*word_command(t_token **lst)
{
	t_ast	*first;
	t_ast	*second;
	t_ast	*node;

	first = simple_word(lst);
	if (first == NULL)
		return (NULL);
	second = command(lst);
	if (second == NULL)
	{
		ast_clear(&first);
		return (NULL);
	}
	node = make_node("\0", CMD);
	node_add(node, first, second);
	return (node);
}

t_ast	*rd_command(t_token **lst)
{
	t_ast	*first;
	t_ast	*second;
	t_ast	*node;

	first = simple_rd(lst);
	if (first == NULL)
		return (NULL);
	if (*lst == NULL)
		return (NULL);
	second = command(lst);
	if (second == NULL)
	{
		ast_clear(&first);
		return (NULL);
	}
	node = make_node("\0", CMD);
	node_add(node, first, second);
	return (node);
}

t_ast	*command(t_token **lst)
{
	t_token	*save;
	t_ast	*node;

	save = *lst;
	node = rd_command(lst);
	if (node != NULL)
		return (node);
	*lst = save;
	node = word_command(lst);
	if (node != NULL)
		return (node);
	*lst = save;
	node = simple_rd(lst);
	if (node != NULL)
		return (node);
	*lst = save;
	node = simple_word_cmmd(lst);
	if (node != NULL)
		return (node);
	return (NULL);
}

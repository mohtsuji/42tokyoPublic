#include "parcer.h"

t_ast	*simple_word(t_token **lst)
{
	t_ast	*node;

	if (*lst == NULL)
		return (NULL);
	if ((*lst)->type <= PIPE)
		return (NULL);
	node = make_node((*lst)->str, CMD);
	*lst = (*lst)->next;
	node_add(node, NULL, NULL);
	return (node);
}

t_ast	*simple_word_cmmd(t_token **lst)
{
	t_ast	*node;

	node = simple_word(lst);
	if (!node)
		return (NULL);
	if ((*lst)->type != PIPE && (*lst)->type != SEMICOLON && (*lst)->type != -1)
	{
		ast_clear(&node);
		return (NULL);
	}
	return (node);
}

t_ast	*simple_rd(t_token **lst)
{
	t_token	*save;
	t_ast	*file;
	t_ast	*node;

	save = *lst;
	if (*lst == NULL)
		return (NULL);
	if ((*lst)->type > N_SMALLER)
		return (NULL);
	*lst = (*lst)->next;
	file = simple_word(lst);
	if (!file)
		return (NULL);
	node = make_node(save->str, save->type);
	file->type = save->type;
	node_add(node, file, NULL);
	return (node);
}

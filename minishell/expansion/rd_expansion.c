#include "expansion.h"

static _Bool	rd_expand_list(t_dlist **head, char *str, t_env *env)
{
	t_expand	exp;
	_Bool		ans;

	init_expand(&exp, str, env);
	ans = rd_expand_str(head, &exp);
	delete_expand(&exp);
	return (ans);
}

_Bool	expand_the_rdnode(t_cmd *cmd, t_env *env)
{
	t_dlist	*expanded;
	t_dlist	*list;
	_Bool	rv;

	expanded = NULL;
	list = cmd->rdlist;
	rv = true;
	while (list != NULL)
	{
		rv = rd_expand_list(&expanded, (char *)list->data, env);
		if (rv == false)
			break ;
		list = list->next;
	}
	if (rv)
		cmd->rd = list_to_array(expanded);
	dlstclear(&expanded);
	return (rv);
}

_Bool	rd_expansion_from_node(t_ast *node, t_env *env)
{
	if (node == NULL)
		return (true);
	if (node->type == CMD)
	{
		if (!expand_the_rdnode(node->command, env))
			return (false);
	}
	return (rd_expansion_from_node(node->left, env) && \
	rd_expansion_from_node(node->right, env));
}

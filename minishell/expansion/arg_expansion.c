#include "expansion.h"

static void	arg_expand_list(t_dlist **head, char *str, t_env *env)
{
	t_expand	exp;

	init_expand(&exp, str, env);
	arg_expand_str(head, &exp);
	delete_expand(&exp);
}

void	expand_the_argnode(t_cmd *cmd, t_env *env)
{
	t_dlist	*expanded;
	t_dlist	*list;

	expanded = NULL;
	list = cmd->arglist;
	while (list != NULL)
	{
		arg_expand_list(&expanded, (char *)list->data, env);
		list = list->next;
	}
	cmd->arg = list_to_array(expanded);
	dlstclear(&expanded);
}

void	arg_expansion_from_node(t_ast *node, t_env *env)
{
	if (node == NULL)
		return ;
	if (node->type == CMD)
		expand_the_argnode(node->command, env);
	arg_expansion_from_node(node->left, env);
	arg_expansion_from_node(node->right, env);
}

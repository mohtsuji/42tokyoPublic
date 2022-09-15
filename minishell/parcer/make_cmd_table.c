#include "parcer.h"

static void	fill_table(t_ast *node, t_cmd *table)
{
	if (node->type >= GREATER && node->type <= N_SMALLER)
		addback_elm_with_data(&(table->rdlist), node->data, NULL);
	else
		addback_elm_with_data(&(table->arglist), node->data, NULL);
}

static void	get_all_node(t_ast *root, t_ast **node, t_cmd *table)
{
	if (*node == NULL)
		return ;
	if ((*node)->type == CMD && ft_strlen((*node)->data) == 0)
		ignore();
	else
		fill_table(*node, table);
	get_all_node(root, &((*node)->left), table);
	get_all_node(root, &((*node)->right), table);
	if (*node != root)
		delete_node(node);
}

void	make_cmd_table(t_ast *node, int tokensize)
{
	t_cmd	*table;

	if (node == NULL)
		return ;
	if ((node->type == CMD) || \
	(node->type >= GREATER && node->type <= N_SMALLER))
	{
		table = (t_cmd *)xmalloc(sizeof(t_cmd));
		table->arg = NULL;
		table->rd = NULL;
		table->arglist = NULL;
		table->rdlist = NULL;
		get_all_node(node, &node, table);
		node->command = table;
		node->type = CMD;
	}
	else
	{
		make_cmd_table(node->left, tokensize);
		make_cmd_table(node->right, tokensize);
	}
}

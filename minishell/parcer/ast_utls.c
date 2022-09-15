#include "parcer.h"

t_ast	*make_node(char *str, int typ)
{
	t_ast	*new;

	new = (t_ast *)xmalloc(sizeof(t_ast));
	new->data = ft_strdup(str);
	if (new->data == NULL)
		return (0);
	new->type = typ;
	new->right = NULL;
	new->left = NULL;
	new->command = NULL;
	return (new);
}

void	node_add(t_ast *root, t_ast *l, t_ast *r)
{
	root->left = l;
	root->right = r;
}

void	delete_node(t_ast **node)
{
	free((*node)->data);
	(*node)->data = NULL;
	(*node)->left = NULL;
	(*node)->right = NULL;
	free(*node);
	*node = NULL;
}

void	cmmd_clear(t_cmd *command)
{
	if (command == NULL)
		return ;
	free_multi(&(command->arg));
	free_multi(&(command->rd));
	dlstclear(&(command->arglist));
	dlstclear(&(command->rdlist));
	free(command);
}

void	ast_clear(t_ast **root)
{
	t_ast	*r;
	t_ast	*l;

	if (*root == NULL)
		return ;
	r = (*root)->right;
	l = (*root)->left;
	free((*root)->data);
	if ((*root)->type == CMD)
		cmmd_clear((*root)->command);
	(*root)->data = NULL;
	(*root)->right = NULL;
	(*root)->left = NULL;
	free(*root);
	*root = NULL;
	ast_clear(&l);
	ast_clear(&r);
}

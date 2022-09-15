#include "executer.h"

static _Bool	exit_countained(t_ast *node)
{
	if (node->left != NULL && node->left->command != NULL && \
	node->left->command->arg != NULL)
	{
		if (ft_strmatch(node->left->command->arg[0], "exit"))
			return (true);
	}
	return (false);
}

int	executer(t_ast *node, t_shell *shell)
{
	int	status;

	if (node == NULL)
		return (LOOP);
	signal(SIGINT, ft_sig_ign);
	if (node->type == CMD)
		return (exec_simple_cmd(node, shell));
	else if (node->type == PIPE)
		return (exec_pipe(node, shell));
	else if (node->type == SEMICOLON)
	{
		status = executer(node->left, shell);
		if (status == STOP_LOOP)
			return (STOP_LOOP);
		if (!exit_countained(node))
		{
			status = executer(node->right, shell);
			if (status == STOP_LOOP)
				return (STOP_LOOP);
		}
	}
	return (LOOP);
}

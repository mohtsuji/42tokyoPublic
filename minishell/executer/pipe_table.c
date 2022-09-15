#include "executer.h"

static void	count_cmd(t_ast *node, int *count)
{
	if (node == NULL)
		return ;
	if (node->type == CMD)
		(*count)++;
	count_cmd(node->left, count);
	count_cmd(node->right, count);
}

static void	fill_pipe_table(t_ast *node, t_cmd **table, int *i)
{
	if (node == NULL)
	{
		table[*i] = NULL;
		return ;
	}	
	if (node->type == CMD)
	{
		table[*i] = node->command;
		(*i)++;
	}
	fill_pipe_table(node->left, table, i);
	fill_pipe_table(node->right, table, i);
}

t_cmd	**make_pipe_table(t_ast *node)
{
	int		cmd_count;
	int		index;
	t_cmd	**pipe_table;

	cmd_count = 0;
	index = 0;
	count_cmd(node, &cmd_count);
	pipe_table = (t_cmd **)xmalloc((cmd_count + 1) * sizeof(t_cmd *));
	fill_pipe_table(node, pipe_table, &index);
	return (pipe_table);
}

void	free_pipe_table(t_cmd **table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (table[i] != NULL)
	{
		while (table[i]->arg[j] != NULL)
		{
			free(table[i]->arg[j]);
			j++;
		}
		i++;
	}
}

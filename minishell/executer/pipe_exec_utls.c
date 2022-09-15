#include "executer.h"

void	run_pipe_cmd(t_cmd *cmd, t_shell *shell)
{
	char	*path;
	int		res;

	path = NULL;
	expand_the_argnode(cmd, shell->envlist);
	if (!expand_the_rdnode(cmd, shell->envlist) || \
	!set_redirection(cmd->rd, shell))
		exit(1);
	if (cmd->arg == NULL || cmd->arg[0] == NULL)
		exit(0);
	if (is_builtin(cmd->arg[0]))
		rd_and_run_builtin(cmd, shell, 1);
	res = search_cmd(cmd->arg[0], shell, &path);
	if (res != FOUND)
		put_msg_and_exit(res, shell, cmd->arg[0], path);
	execve(path, cmd->arg, shell->env_arr);
	exit(check_permission(path, shell, cmd->arg[0]));
}

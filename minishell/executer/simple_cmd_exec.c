#include "executer.h"

void	run_cmd(t_cmd *cmd, t_shell *shell)
{
	pid_t	pid;
	int		status;
	char	*cmdpath;
	int		res;

	status = 0;
	cmdpath = NULL;
	pid = fork();
	if (pid < 0)
		exit_with_msg("run_cmd: fork error");
	else if (pid == 0)
	{
		if (!set_redirection(cmd->rd, shell))
			exit(1);
		res = search_cmd(cmd->arg[0], shell, &cmdpath);
		if (res != FOUND)
			put_msg_and_exit(res, shell, cmd->arg[0], cmdpath);
		execve(cmdpath, cmd->arg, shell->env_arr);
		exit(check_permission(cmdpath, shell, cmd->arg[0]));
	}
	if (wait(&status) < 0)
		exit_with_msg("wait error");
	check_status(status);
}

_Bool	is_builtin(char *cmd)
{
	const char	*buildins[] = {"cd", "pwd", "env", "unset", \
	"export", "echo", "exit"};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (ft_strmatch(cmd, (char *)buildins[i]))
			return (true);
		++i;
	}
	return (false);
}

int	exec_simple_cmd(t_ast *node, t_shell *shell)
{
	expand_the_argnode(node->command, shell->envlist);
	if (!expand_the_rdnode(node->command, shell->envlist))
	{
		g_status = 1;
		return (LOOP);
	}
	if (node->command->arg == NULL || node->command->arg[0] == NULL)
		return (rd_and_run_builtin(node->command, shell, 0));
	if (is_builtin(node->command->arg[0]))
		return (rd_and_run_builtin(node->command, shell, 1));
	shell->env_arr = env_trunc(shell->envlist);
	run_cmd(node->command, shell);
	free_multi(&(shell->env_arr));
	return (LOOP);
}

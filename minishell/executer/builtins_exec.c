#include "executer.h"

static int	run_exit(t_cmd *cmd, t_shell *shell)
{
	int	exit_value;
	int	status;

	exit_value = our_exit(cmd, &status);
	if (shell->pipe)
		exit(status);
	g_status = status;
	return (exit_value);
}

int	run_builtin(t_cmd *cmd, t_shell *shell)
{
	int	status;

	if (ft_strmatch(cmd->arg[0], "exit"))
		return (run_exit(cmd, shell));
	if (ft_strmatch(cmd->arg[0], "cd"))
		status = our_cd(cmd, shell);
	else if (ft_strmatch(cmd->arg[0], "pwd"))
		status = our_pwd(cmd, shell);
	else if (ft_strmatch(cmd->arg[0], "env"))
		status = our_env(cmd, shell);
	else if (ft_strmatch(cmd->arg[0], "unset"))
		status = our_unset(cmd, shell);
	else if (ft_strmatch(cmd->arg[0], "export"))
		status = our_export(cmd, shell);
	else if (ft_strmatch(cmd->arg[0], "echo"))
		status = our_echo(cmd);
	if (shell->pipe)
		exit(status);
	g_status = status;
	return (LOOP);
}

int	rd_and_run_builtin(t_cmd *cmd, t_shell *shell, int cmdexist)
{
	int	loop;

	if (!set_redirection(cmd->rd, shell))
	{
		undo_redirection(shell);
		if (shell->pipe)
			exit(1);
		return (LOOP);
	}
	if (cmdexist)
		loop = run_builtin(cmd, shell);
	else
		loop = LOOP;
	undo_redirection(shell);
	return (loop);
}

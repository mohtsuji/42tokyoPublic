#include "executer.h"

static void	wait_for_brothers(t_cmd **pipe_table, pid_t p)
{
	int	status;
	int	i;

	i = 0;
	waitpid(p, &status, 0);
	check_status(status);
	while (pipe_table[i + 1] != NULL)
	{
		if (wait(&status) < 0)
			exit_with_msg("wait error");
		signal_handler_pipe(status);
		++i;
	}
}

static void	parent_pipe(t_cmd **pipe_table, int i)
{
	if (i > 0)
	{
		close(pipe_table[i - 1]->pipe_fd[0]);
		close(pipe_table[i - 1]->pipe_fd[1]);
	}
}

static void	child_pipe(t_cmd **pipe_table, int i)
{
	if (i == 0)
	{
		close(pipe_table[i]->pipe_fd[0]);
		dup2(pipe_table[i]->pipe_fd[1], STDOUT_FILENO);
		close(pipe_table[i]->pipe_fd[1]);
	}
	else if (pipe_table[i + 1] == NULL)
	{
		dup2(pipe_table[i - 1]->pipe_fd[0], STDIN_FILENO);
		close(pipe_table[i - 1]->pipe_fd[0]);
		close(pipe_table[i - 1]->pipe_fd[1]);
	}
	else
	{
		dup2(pipe_table[i - 1]->pipe_fd[0], STDIN_FILENO);
		dup2(pipe_table[i]->pipe_fd[1], STDOUT_FILENO);
		close(pipe_table[i - 1]->pipe_fd[0]);
		close(pipe_table[i - 1]->pipe_fd[1]);
		close(pipe_table[i]->pipe_fd[1]);
		close(pipe_table[i]->pipe_fd[0]);
	}
}

static void	start_pipe(t_cmd **pipe_table, t_shell *shell)
{
	int		i;
	pid_t	p;

	i = 0;
	while (pipe_table[i] != NULL)
	{
		if (pipe_table[i + 1] != NULL)
		{
			if (pipe(pipe_table[i]->pipe_fd) < 0)
				exit_with_msg("pipe error");
		}
		p = fork();
		if (p < 0)
			exit_with_msg("fork error");
		else if (p == 0)
		{
			child_pipe(pipe_table, i);
			run_pipe_cmd(pipe_table[i], shell);
			exit(0);
		}
		parent_pipe(pipe_table, i);
		++i;
	}
	wait_for_brothers(pipe_table, p);
}

int	exec_pipe(t_ast *node, t_shell *shell)
{
	t_cmd	**pipe_table;

	shell->stdout_origin = dup(STDOUT_FILENO);
	shell->stdin_origin = dup(STDIN_FILENO);
	pipe_table = make_pipe_table(node);
	shell->env_arr = env_trunc(shell->envlist);
	shell->pipe = true;
	start_pipe(pipe_table, shell);
	dup2(shell->stdout_origin, STDOUT_FILENO);
	dup2(shell->stdin_origin, STDIN_FILENO);
	close(shell->stdout_origin);
	close(shell->stdin_origin);
	free_multi(&(shell->env_arr));
	free(pipe_table);
	shell->pipe = false;
	return (LOOP);
}

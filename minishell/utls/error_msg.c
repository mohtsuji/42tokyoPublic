#include "utls.h"
/*
void	command_not_found(char *cmd, t_shell *shell)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	if (!shell->pipe)
		g_status = 127;
}

void	no_such_file_or_dir(char *file, t_shell *shell)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	if (!shell->pipe)
		g_status = 1;
}

void	permission_denied(char *file, t_shell *shell)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
	if (!shell->pipe)
		g_status = 1;
}

void	it_is_dir(char *file, t_shell *shell)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
	if (!shell->pipe)
		g_status = 1;
}
*/
void	errmsg_with_status(char *file, t_shell *shell, char *msg, int status)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (!shell->pipe)
		g_status = status;
}

_Bool	over_intmax(char *fd)
{
	int			i;
	long long	num;

	i = 0;
	num = 0;
	while (fd[i] && ft_isdigit(fd[i]))
	{
		num = num * 10 + (fd[i] - '0');
		++i;
		if (num > (long long)INT32_MAX)
		{
			ft_putstr_fd("file descriptor out of range", STDERR_FILENO);
			return (true);
		}
	}
	return (false);
}

void	bad_fd(char *fd, t_shell *shell)
{
	_Bool		over;

	over = false;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	over = over_intmax(fd);
	while (!over && ft_isdigit(*fd) && *fd)
	{
		ft_putchar_fd(*fd, STDERR_FILENO);
		fd++;
	}
	ft_putstr_fd(": Bad file descriptor\n", STDERR_FILENO);
	if (!shell->pipe)
		g_status = 1;
}

#include "../includes/minishell.h"

int	check_dir_exist(char *path)
{
	struct stat	buf;
	char		*now;

	if ((lstat(path, &buf)) == 0)
	{
		if ((buf.st_mode & S_IFMT) == S_IFDIR)
			return (true);
		else if ((buf.st_mode & S_IFMT) == S_IFLNK)
			return (true);
	}
	now = getcwd(NULL, 0);
	if (now == NULL)
	{
		safe_free(&now);
		return (true);
	}
	safe_free(&now);
	return (false);
}

void	true_end_process(t_shell *shell, char **position)
{
	free_dup(&(shell->oldpwd), shell->pwd);
	free_dup(&(shell->pwd), *position);
	rewrite_pwd(shell);
	rewrite_oldpwd(shell);
}

void	bad_end_process(int errno_tmp)
{
	errno = errno_tmp;
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	write(2, "\n", 1);
}

int	end_process(t_cmd *cmd, char **position, t_shell *shell, int fail)
{
	struct stat	buf;
	int			errno_tmp;

	if (fail)
	{
		errno_tmp = errno;
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(cmd->arg[1], STDERR_FILENO);
		write(2, ": ", 2);
		if ((lstat(*position, &buf)) == 0)
		{
			if ((buf.st_mode & S_IFMT) != S_IFDIR && \
			(buf.st_mode & S_IFMT) != S_IFLNK)
				ft_putstr_fd("Not a directory\n", STDERR_FILENO);
			else
				bad_end_process(errno_tmp);
		}
		else
			bad_end_process(errno_tmp);
	}
	else
		true_end_process(shell, position);
	safe_free(position);
	shell->on_pwd = true;
	return (fail);
}

void	join_path(char **new, char **tmp, char ***path, int i)
{
	if (ft_strmatch(*tmp, "/") == 1 || ft_strmatch(*tmp, "//") == 1)
		safe_strjoin(new, *tmp, (*path)[i]);
	else
		safe_trijoin(new, *tmp, "/", (*path)[i]);
	free_dup(tmp, *new);
	safe_free(new);
}

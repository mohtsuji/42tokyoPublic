#include "executer.h"

static _Bool	dir_exists(char *file, t_shell *shell)
{
	char		*dir;
	char		*dirname;
	struct stat	buf;

	dirname = NULL;
	dir = ft_strrchr(file, '/');
	if (dir != NULL)
	{
		dirname = safe_substr(file, 0, (size_t)(dir - file + 1));
		if ((lstat(dirname, &buf)) != 0)
		{
			free(dirname);
			dirname = NULL;
			errmsg_with_status(file, shell, NOSUCHFILE, 1);
			return (false);
		}
	}
	free(dirname);
	return (true);
}

static _Bool	check_file(char *file, t_shell *shell)
{
	struct stat	buf;

	if ((lstat(file, &buf)) == 0)
	{
		if ((buf.st_mode & S_IFMT) == S_IFDIR)
		{
			errmsg_with_status(file, shell, ITISDIR, 1);
			return (false);
		}
	}
	return (dir_exists(file, shell));
}

static int	open_and_check(char *rd_sign, char *file, t_shell *shell)
{
	int	to_fd;

	if (*rd_sign == '>' && *(rd_sign + 1) == '>')
		to_fd = open(file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else
		to_fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (to_fd < 0)
		errmsg_with_status(file, shell, PERMISSTION, 1);
	return (to_fd);
}

static _Bool	right_num_rd(char *rd_sign, char *file, t_shell *shell)
{
	int		from_fd;
	int		to_fd;
	char	*save;

	save = rd_sign;
	from_fd = get_num(rd_sign);
	skip_digit(&rd_sign);
	to_fd = open_and_check(rd_sign, file, shell);
	if (to_fd < 0)
		return (false);
	if (from_fd < 0)
	{
		close(to_fd);
		bad_fd(save, shell);
		return (false);
	}
	if (to_fd == from_fd)
		to_fd = save_and_dup(to_fd);
	if (shell->usedfd[from_fd] != -1)
		dup2(shell->usedfd[from_fd], from_fd);
	shell->usedfd[from_fd] = dup(from_fd);
	dup2(to_fd, from_fd);
	close(to_fd);
	return (true);
}

_Bool	right_rd(char *rd_sign, char *file, t_shell *shell)
{
	int	to_fd;

	if (!check_file(file, shell))
		return (false);
	if (ft_isdigit((*rd_sign)))
		return (right_num_rd(rd_sign, file, shell));
	to_fd = open_and_check(rd_sign, file, shell);
	if (to_fd < 0)
		return (false);
	if (shell->usedfd[STDOUT_FILENO] != -1)
		dup2(shell->usedfd[STDOUT_FILENO], STDOUT_FILENO);
	shell->usedfd[STDOUT_FILENO] = dup(STDOUT_FILENO);
	dup2(to_fd, STDOUT_FILENO);
	close(to_fd);
	return (true);
}

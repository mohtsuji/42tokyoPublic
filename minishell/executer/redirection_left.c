#include "executer.h"

static _Bool	check_file(char *file, t_shell *shell)
{
	struct stat	buf;

	if (lstat(file, &buf) != 0)
	{
		errmsg_with_status(file, shell, NOSUCHFILE, 1);
		return (false);
	}
	if (!(buf.st_mode & S_IRUSR))
		errmsg_with_status(file, shell, PERMISSTION, 1);
	return (false);
}

_Bool	left_rd(char *rd_sign, char *file, t_shell *shell)
{
	int	from_fd;
	int	to_fd;

	to_fd = STDIN_FILENO;
	from_fd = open(file, O_RDONLY);
	if (from_fd < 0)
		return (check_file(file, shell));
	if (ft_isdigit((*rd_sign)))
		to_fd = get_num(rd_sign);
	if (to_fd < 0)
	{
		close(from_fd);
		bad_fd(rd_sign, shell);
		return (false);
	}
	if (to_fd == from_fd)
		from_fd = save_and_dup(from_fd);
	if (shell->usedfd[to_fd] != -1)
		dup2(shell->usedfd[to_fd], to_fd);
	shell->usedfd[to_fd] = dup(to_fd);
	dup2(from_fd, to_fd);
	close(from_fd);
	return (true);
}

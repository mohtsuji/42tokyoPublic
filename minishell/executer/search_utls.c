#include "executer.h"

void	output_errmsg(int res, t_shell *shell, char *file)
{
	if (res == NOTFOUND_FILE)
		errmsg_with_status(file, shell, NOSUCHFILE, 127);
	else if (res == NOTFOUND_DIR)
		errmsg_with_status(file, shell, ITISDIR, 126);
	else if (res == NOTFOUND_CMD)
		errmsg_with_status(file, shell, CMDNOTFOUND, 127);
	else if (res == NOTFOUND_NOTDIR)
		errmsg_with_status(file, shell, NOTDIR, 126);
	else if (res == NOTFOUND_PERM)
		errmsg_with_status(file, shell, PERMISSTION, 126);
}

int	check_permission(char *file, t_shell *shell, char *file_name)
{
	struct stat	buf;

	if ((lstat(file, &buf)) == 0 && buf.st_mode & S_IXUSR && \
	buf.st_mode & S_IRUSR)
		return (0);
	errmsg_with_status(file_name, shell, PERMISSTION, 126);
	return (126);
}

void	put_msg_and_exit(int res, t_shell *shell, char *file, char *cmdpath)
{
	int	status;

	if (res == NOTFOUND_PERM)
		output_errmsg(res, shell, cmdpath);
	else
		output_errmsg(res, shell, file);
	if (res == NOTFOUND_CMD || res == NOTFOUND_FILE)
		status = 127;
	else
		status = 126;
	exit(status);
}

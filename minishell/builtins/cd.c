#include "../includes/minishell.h"

void	back(char **tmp)
{
	int		i;
	int		count;
	int		slush_of_top;

	i = 0;
	count = count_slush(*tmp);
	slush_of_top = top_slush(*tmp);
	if (count == 1)
	{
		if (slush_of_top == 2)
			free_dup(tmp, "//");
		else
			free_dup(tmp, "/");
		return ;
	}
	while (count > 0)
	{
		if ((*tmp)[i] == '/')
			count--;
		if (count == 0)
			(*tmp)[i] = '\0';
		i++;
	}
	return ;
}

char	*replace(int i, char ***path, int slush_count, _Bool *flag_lstat)
{
	char	*new;
	char	*tmp;

	*flag_lstat = true;
	if (slush_count == 2)
		safe_strjoin(&tmp, "//", "\0");
	else
		safe_strjoin(&tmp, "/", "\0");
	while ((*path)[i])
	{
		if ((*path)[i][0] == '.' && (*path)[i][1] == '.' &&
		 (*path)[i][2] == '\0')
			back(&tmp);
		else if ((*path)[i][0] == '.' && (*path)[i][1] == '\0')
		{
		}
		else
			join_path(&new, &tmp, path, i);
		if (check_dir_exist(tmp) == false)
			*flag_lstat = false;
		i++;
	}
	free_multi(path);
	return (tmp);
}

int	tryagain_chdir(t_cmd *cmd, char **position, t_shell *shell)
{
	char	*now;

	if (chdir(cmd->arg[1]) == 0)
	{
		now = getcwd(NULL, 0);
		if (now == NULL)
		{
			ft_putstr_fd("cd: error retrieving current directory: \
getcwd: cannot access parent directories: \
No such file or directory\n", STDERR_FILENO);
			safe_free(position);
			pwd_join(position, shell, cmd);
		}
		else
			free_dup(position, now);
		safe_free(&now);
		return (0);
	}
	return (1);
}

char	*make_absolute(t_shell *shell, t_cmd *cmd, int *slush_count)
{
	char	*now;
	char	*position;

	now = getcwd(NULL, 0);
	if (shell->pwd[1] == '/')
		*slush_count = 2;
	if (now == NULL)
		now = safe_dup(shell->pwd);
	if (cmd->arg[1][0] == '/')
		position = absolute_pwd(cmd->arg[1], slush_count);
	else
		safe_trijoin(&position, now, "/", cmd->arg[1]);
	safe_free(&now);
	return (position);
}

int	our_cd(t_cmd *cmd, t_shell *shell)
{
	char	*position;
	char	**path;
	int		slush_count;
	_Bool	flag_lstat;

	if (cmd->arg[1] == NULL)
		return (0);
	slush_count = 0;
	position = make_absolute(shell, cmd, &slush_count);
	path = safe_split(position, '/');
	safe_free(&position);
	position = replace(0, &path, slush_count, &flag_lstat);
	if (cmd->arg[1][0] != '.' && cmd->arg[1][0] != '/' \
	&& (check_cdpath(cmd, shell, &position) == true))
		return (end_process(cmd, &position, shell, 0));
	if (flag_lstat == true)
	{
		errno = 0;
		if (chdir(position) == 0)
			return (end_process(cmd, &position, shell, 0));
		else if (tryagain_chdir(cmd, &position, shell) == 0)
			return (end_process(cmd, &position, shell, 0));
	}
	return (end_process(cmd, &position, shell, 1));
}

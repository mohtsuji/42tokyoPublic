#include "../includes/minishell.h"

void	get_cdpath(int i, t_cd *cd)
{
	char	*tmp;

	if ((i - cd->start) == 0)
	{
		cd->target_path = safe_dup("./");
		cd->empty = true;
	}
	else
	{
		tmp = ft_substr(cd->cdpath, cd->start, (i - cd->start));
		if (tmp[ft_strlen(tmp) - 1] != '/')
			cd->target_path = safe_join(tmp, "/");
		else
			cd->target_path = safe_dup(tmp);
		safe_free(&tmp);
	}
}

_Bool	success_chdir(char *target_path, char **position, _Bool empty)
{
	errno = 0;
	if (chdir(target_path) == 0)
	{
		safe_free(position);
		*position = safe_dup(target_path);
		if (empty == false)
		{
			ft_putstr_fd(*position, STDOUT_FILENO);
			write(1, "\n", 1);
		}
		return (true);
	}
	return (false);
}

void	join_pwd_cdpath(t_shell *shell, t_cmd *cmd, t_cd *cd)
{
	char	*tmp;
	char	**split_path;

	if (cd->target_path[0] != '/')
	{
		safe_trijoin(&tmp, shell->pwd, "/", cd->target_path);
		free_dup(&(cd->target_path), tmp);
		safe_free(&tmp);
		tmp = safe_join(cd->target_path, cmd->arg[1]);
	}
	else
		tmp = safe_join(cd->target_path, cmd->arg[1]);
	split_path = safe_split(tmp, '/');
	safe_free(&(cd->target_path));
	cd->target_path = replace(0, &split_path, top_slush(tmp), \
								&(cd->flag_lstat));
	safe_free(&tmp);
}

_Bool	try_chdir(char **position, t_cd *cd)
{
	if (cd->flag_lstat == true)
	{
		if (success_chdir(cd->target_path, position, cd->empty) == true)
		{
			safe_free(&(cd->cdpath));
			safe_free(&(cd->target_path));
			return (true);
		}
	}
	return (false);
}

_Bool	check_cdpath(t_cmd *cmd, t_shell *shell, char **position)
{
	int		i;
	t_cd	cd;

	i = 0;
	if (init_cdpath(&cd, shell) == false)
		return (false);
	while (1)
	{
		if (cd.cdpath[i] == ':' || cd.cdpath[i] == '\0')
		{
			get_cdpath(i, &cd);
			join_pwd_cdpath(shell, cmd, &cd);
			if (try_chdir(position, &cd) == true)
				return (true);
			safe_free(&(cd.target_path));
			cd.start = i + 1;
		}
		if (cd.cdpath[i] == '\0')
		{
			safe_free(&(cd.cdpath));
			return (false);
		}
		cd.empty = false;
		i++;
	}
}

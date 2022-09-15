#include "../includes/minishell.h"

char	*absolute_pwd(char *path, int *slush_count)
{
	char	*ans;

	*slush_count = 0;
	while (path[*slush_count] == '/')
		(*slush_count)++;
	ans = ft_strdup(path);
	if (ans == NULL)
		exit(1);
	return (ans);
}

_Bool	init_cdpath(t_cd *cd, t_shell *shell)
{
	t_env	*env;

	cd->start = 0;
	cd->empty = false;
	cd->flag_lstat = false;
	cd->cdpath = NULL;
	cd->target_path = NULL;
	env = ft_getenv("CDPATH", shell->envlist);
	if (env == NULL)
		return (false);
	cd->cdpath = safe_dup(env->value);
	return (true);
}

int	top_slush(char *path)
{
	int	ans;
	int	i;

	ans = 0;
	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
			ans++;
		else
			break ;
		i++;
	}
	return (ans);
}

#include "../includes/minishell.h"

void	rewrite_pwd(t_shell *shell)
{
	char	*now_path;
	t_env	*env;

	now_path = shell->pwd;
	env = shell->envlist;
	while (env != 0)
	{
		if (ft_strmatch(env->key, "PWD") == 1)
		{
			safe_free(&(env->value));
			env->value = ft_strdup(now_path);
			if (env->value == NULL)
				exit_with_msg("cd: malloc error\n");
		}
		env = env->next;
	}
}

void	rewrite_oldpwd(t_shell *shell)
{
	t_env	*env;

	env = shell->envlist;
	while (env != 0)
	{
		if (ft_strmatch(env->key, "OLDPWD") == 1)
		{
			safe_free(&(env->value));
			env->equal = 1;
			if (shell->on_pwd == false)
				env->value = safe_dup("\0");
			else
				env->value = safe_dup(shell->oldpwd);
		}
		env = env->next;
	}
}

int	count_slush(char *tmp)
{
	int		ans;
	int		i;
	_Bool	prev;

	ans = 0;
	i = 0;
	prev = false;
	while (tmp[i])
	{
		if (tmp[i] == '/' && prev == false)
		{
			ans++;
			prev = true;
		}
		else
			prev = false;
		i++;
	}
	return (ans);
}

void	pwd_join(char **position, t_shell *shell, t_cmd *cmd)
{
	int	size;

	size = ft_strlen(shell->pwd);
	if (shell->pwd[size - 1] == '/')
		safe_strjoin(position, shell->pwd, cmd->arg[1]);
	else
		safe_trijoin(position, shell->pwd, "/", cmd->arg[1]);
}

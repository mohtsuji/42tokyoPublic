#include "../includes/minishell.h"

void	put_value(char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] == '\"' || value[i] == '$' || value[i] == '\\' || \
			value[i] == '`' || value[i] == '\n')
			write(1, "\\", 1);
		write(1, &(value[i]), 1);
		i++;
	}
}

void	put_export(t_shell *shell)
{
	t_env	*env;

	sort_if_needed(&(shell->envlist), shell->envlist);
	env = shell->envlist;
	while (env != NULL)
	{
		if (ft_strmatch(env->key, "_") == 1)
		{
			env = env->next;
			continue ;
		}
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(env->key, STDOUT_FILENO);
		if (env->equal == 0)
		{
			write(1, "\n", 1);
			env = env->next;
			continue ;
		}
		write(1, "=\"", 2);
		put_value(env->value);
		write(1, "\"\n", 2);
		env = env->next;
	}
}

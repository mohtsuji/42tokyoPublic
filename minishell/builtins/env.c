#include "../includes/minishell.h"

void	put_env(t_env *env, int fd)
{
	while (env != NULL)
	{
		if (env->equal == 0)
		{
			env = env->next;
			continue ;
		}
		ft_putstr_fd(env->key, fd);
		write(fd, "=", 1);
		ft_putstr_fd(env->value, fd);
		write(fd, "\n", 1);
		env = env->next;
	}
}

int	our_env(t_cmd *cmd, t_shell *shell)
{
	if (cmd->arg[1] != NULL)
	{
		ft_putstr_fd("env takes no arguments and no options\n", 2);
		return (2);
	}
	put_env(shell->envlist, STDOUT_FILENO);
	return (0);
}

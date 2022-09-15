#include "buildin.h"

int	our_pwd(t_cmd *cmd, t_shell *shell)
{
	t_env	*env;

	env = shell->envlist;
	(void)cmd;
	while (env != 0)
	{
		if (ft_strmatch(env->key, "PWD") == 1)
		{
			ft_putstr_fd(env->value, STDOUT_FILENO);
			write(1, "\n", 1);
			return (0);
		}
		env = env->next;
	}
	ft_putstr_fd(shell->pwd, STDOUT_FILENO);
	write(1, "\n", 1);
	return (0);
}

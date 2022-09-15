#include "../includes/minishell.h"

int	check_arg(char **arg)
{
	int	i;
	int	value;
	int	j;

	i = 0;
	value = 0;
	while (arg[i] != NULL)
	{
		j = 0;
		while (arg[i][j])
		{
			if (ft_isdigit(arg[i][0]) || is_env_variable(arg[i][j]) == false)
			{
				ft_putstr_fd("minishell: unset: `", 2);
				ft_putstr_fd(arg[i], 2);
				ft_putstr_fd("': not a valid identifier\n", 2);
				value = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (value);
}

t_env	*env_first(t_env *elm)
{
	t_env	*current;

	if (!elm)
		return (NULL);
	current = elm;
	while (current->prev != NULL)
		current = current->prev;
	return (current);
}

void	delete_one_env(t_env **del)
{
	t_env	*now;
	t_env	*nex;
	t_env	*pre;

	now = *del;
	nex = now->next;
	pre = now->prev;
	if (nex != NULL)
		nex->prev = pre;
	if (pre != NULL)
		pre->next = nex;
	safe_free(&(now->key));
	safe_free(&(now->value));
	now->next = NULL;
	now->prev = NULL;
	free(*del);
	*del = NULL;
}

void	exec_unset(char **arg, t_shell *shell)
{
	int		i;
	t_env	*del;

	i = 1;
	while (arg[i])
	{
		if (ft_strmatch(arg[i], "PWD"))
			shell->on_pwd = false;
		del = ft_getenv(arg[i], shell->envlist);
		if (del)
		{
			if (del == shell->envlist)
				shell->envlist = del->next;
			delete_one_env(&del);
		}
		i++;
	}
}

int	our_unset(t_cmd *cmd, t_shell *shell)
{
	int	value;

	value = 0;
	if (check_arg(cmd->arg) == 1)
		value = 1;
	exec_unset(cmd->arg, shell);
	return (value);
}

#include "../includes/minishell.h"

static int	check_key(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (is_env_variable(str[i]) == false)
		{
			if (str[i] == '+')
			{
				if (str[i + 1] == '=')
					return (2);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_arg(char *str)
{
	if (str[0] == '=' || str[0] == '+' || \
	ft_isdigit(str[0]) || check_key(str) == 1)
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	else if (check_key(str) == 2)
		return (2);
	return (0);
}

_Bool	is_same_key(t_env **env, int flag, char *str)
{
	char	*key_tmp;
	char	*value_tmp;

	get_key_value(str, &key_tmp, &value_tmp, flag);
	while (*env)
	{
		if (ft_strmatch((*env)->key, key_tmp) == 1)
		{
			replace_value(str, env, value_tmp, flag);
			safe_free(&key_tmp);
			safe_free(&value_tmp);
			return (true);
		}
		*env = (*env)->next;
	}
	safe_free(&key_tmp);
	safe_free(&value_tmp);
	return (false);
}

void	add_export(char *str, t_shell *shell, int flag)
{
	t_env	*new;
	char	*key_tmp;
	char	*value_tmp;
	t_env	*env;

	env = shell->envlist;
	get_key_value(str, &key_tmp, &value_tmp, flag);
	if (flag == 1)
	{
	}
	else if (is_same_key(&env, flag, str) == true)
	{
	}
	else
	{
		new = env_lstnew(str, flag);
		if ((ft_strmatch(key_tmp, "OLDPWD") || \
	ft_strmatch(key_tmp, "PWD")) && value_tmp[0] == '\0')
			set_pwd_or_oldpwd(new, shell, key_tmp);
		env_lstadd_back(&(shell->envlist), new);
	}
	safe_free(&key_tmp);
	safe_free(&value_tmp);
}

int	our_export(t_cmd *cmd, t_shell *shell)
{
	int		flag;
	int		i;
	int		result;

	i = 1;
	result = 0;
	flag = 0;
	if (cmd->arg[1] == NULL)
	{
		put_export(shell);
		return (0);
	}
	while (cmd->arg[i])
	{
		flag = check_arg(cmd->arg[i]);
		if (flag == 1)
			result = 1;
		add_export(cmd->arg[i], shell, flag);
		i++;
	}
	return (result);
}

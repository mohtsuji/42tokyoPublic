#include "../includes/minishell.h"

int	check_oldpwd(char *str)
{
	char	*key;
	char	*value;

	get_key_value(str, &key, &value, 0);
	if (ft_strmatch(key, "OLDPWD") == 1)
	{
		safe_free(&key);
		safe_free(&value);
		return (1);
	}
	safe_free(&key);
	safe_free(&value);
	return (0);
}

void	set_oldpwd(t_env **new)
{
	(*new)->equal = 0;
	safe_free(&((*new)->value));
	(*new)->value = (char *)xmalloc(sizeof(char) * 1);
	(*new)->value[0] = '\0';
}

void	env_copy(t_env **env, char *envv[])
{
	int			i;
	t_env		*new;
	int			flag;

	flag = 0;
	i = 0;
	while (envv[i])
	{
		new = env_lstnew(envv[i], 0);
		if (check_oldpwd(envv[i]) == 1)
			set_oldpwd(&new);
		if (flag == 1)
			env_lstadd_back(env, new);
		else
		{
			*env = new;
			flag = 1;
		}
		i++;
	}
	return ;
}

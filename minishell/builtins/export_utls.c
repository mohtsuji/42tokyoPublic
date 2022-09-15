#include "../includes/minishell.h"

void	replace_value(char *str, t_env **env, char *value_tmp, int flag)
{
	char	*tmp;

	if (flag == 2)
	{
		safe_strjoin(&tmp, (*env)->value, value_tmp);
		(*env)->equal = 1;
		free_dup(&((*env)->value), tmp);
		safe_free(&tmp);
	}
	else if (ft_strchr(str, '=') == NULL)
	{
	}
	else
	{
		free_dup(&((*env)->value), value_tmp);
		(*env)->equal = 1;
	}
}

void	set_pwd_or_oldpwd(t_env *new, t_shell *shell, char *key_tmp)
{
	new->equal = 1;
	if (ft_strmatch(key_tmp, "OLDPWD"))
		free_dup(&(new->value), shell->oldpwd);
	if (ft_strmatch(key_tmp, "PWD"))
		free_dup(&(new->value), shell->pwd);
}

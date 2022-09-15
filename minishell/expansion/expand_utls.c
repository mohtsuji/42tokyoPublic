#include "expansion.h"

char	*expand_env(t_expand *exp, char *str)
{
	char	*key;
	t_env	*find;
	size_t	i;

	i = 0;
	if (str[i] == '?')
		return (ft_itoa(g_status));
	if (!is_env_variable(str[i]))
		return (safe_dup("$"));
	else
	{
		while (str[i] != '\0' && is_env_variable(str[i]))
			i++;
		key = safe_substr(str, 0, i);
		find = ft_getenv(key, exp->env);
		free(key);
		if (find == NULL)
			return (NULL);
	}
	return (safe_dup(find->value));
}

_Bool	escaped(int escape_count)
{
	if (escape_count % 2 == 0)
		return (false);
	return (true);
}

void	substitute_doller(char **ans, t_expand *exp, int i)
{
	char	*envstr;
	char	*done;

	envstr = expand_env(exp, exp->str + i + 1);
	if (*ans == NULL)
		*ans = (char *)safe_calloc(1, sizeof(char));
	if (envstr == NULL)
		return ;
	done = *ans;
	*ans = safe_join(*ans, envstr);
	free(done);
	free(envstr);
}

void	copy_one_letter(char **ans, t_expand *exp, int i)
{
	char	*done;

	if (*ans == NULL)
		*ans = safe_dup("");
	done = *ans;
	*ans = ft_charjoin(*ans, exp->str[i]);
	free(done);
	done = NULL;
}

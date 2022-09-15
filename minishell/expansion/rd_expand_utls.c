#include "expansion.h"

static char	*ambiguous_rd(char **key)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("$", STDERR_FILENO);
	ft_putstr_fd(*key, STDERR_FILENO);
	ft_putstr_fd(": ambiguous redirect\n", STDERR_FILENO);
	free(*key);
	*key = NULL;
	return (NULL);
}

static _Bool	stop_if_ambiguous(char **ans, t_expand *exp, int i)
{
	char	*envstr;
	char	*done;
	char	*key;
	int		j;

	envstr = expand_env(exp, exp->str + i + 1);
	if (envstr == NULL || ft_strlen(envstr) == 0 || ft_strchr(envstr, ' '))
	{
		j = i + 1;
		while (exp->str[j] != '\0' && is_env_variable(exp->str[j]))
			j++;
		key = safe_substr(exp->str, i + 1, j);
		ambiguous_rd(&key);
		free(*ans);
		free(envstr);
		return (true);
	}
	if (*ans == NULL)
		*ans = safe_dup("");
	done = *ans;
	*ans = safe_join(*ans, envstr);
	free(done);
	free(envstr);
	return (false);
}

_Bool	rd_expand_doller(t_expand *exp, char **ans, int *i)
{
	if (exp->quote_table[*i] == 'd')
		substitute_doller(ans, exp, *i);
	else if (stop_if_ambiguous(ans, exp, *i))
		return (false);
	(*i)++;
	if (exp->str[*i] == '?')
		(*i)++;
	else
	{
		while (is_env_variable(exp->str[*i]))
			(*i)++;
	}
	return (true);
}

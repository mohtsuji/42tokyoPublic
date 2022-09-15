#include "../includes/minishell.h"

static int	get_size(t_env *env)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (env->key[i] != 0)
	{
		i++;
		size++;
	}
	if (env->equal == 1)
		size++;
	i = 0;
	if (env->value == NULL)
		return (size);
	while (env->value[i] != 0)
	{
		i++;
		size++;
	}
	return (size);
}

void	exec_trunc(char **result, t_env *env, int *j, int *k)
{
	*result = (char *)xmalloc(sizeof(char) * (get_size(env) + 1));
	*k = 0;
	*j = 0;
	while (env->key[(*k)] != 0)
	{
		(*result)[(*j)] = env->key[(*k)++];
		(*j)++;
	}
	*k = 0;
	if (env->equal == 1)
	{
		(*result)[(*j)] = '=';
		(*j)++;
	}
	if (env->value == NULL)
	{
		(*result)[*j] = '\0';
		return ;
	}
	while (env->value[*k] != 0)
	{
		(*result)[*j] = env->value[(*k)++];
		(*j)++;
	}
	(*result)[*j] = '\0';
}

char	**env_trunc(t_env *env)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	result = NULL;
	result = (char **)xmalloc(sizeof(char *) * (env_lstsize(env) + 1));
	i = 0;
	while (env != NULL)
	{
		j = 0;
		k = 0;
		exec_trunc(&(result[i]), env, &j, &k);
		i++;
		env = env->next;
	}
	result[i] = NULL;
	return (result);
}

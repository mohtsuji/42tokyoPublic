#include "expansion.h"

static int	count_split(char **arr)
{
	int	count;

	count = 0;
	while (arr[count] != NULL)
		++count;
	return (count);
}

static void	split_and_addback(t_dlist **head, char **ans, char *env_str)
{
	int		count;
	int		j;
	char	**split;

	split = safe_split(env_str, ' ');
	count = count_split(split);
	j = 0;
	if (env_str[0] == ' ')
		addback_elm_with_data(head, *ans, NULL);
	else
	{
		addback_elm_with_data(head, *ans, split[0]);
		j = 1;
	}
	while (j < count - 1)
	{
		addback_elm_with_data(head, split[j], NULL);
		++j;
	}
	free(*ans);
	if (count == 0)
		*ans = (char *)safe_calloc(1, sizeof(char));
	else
		*ans = safe_dup(split[count - 1]);
	free_multi(&split);
}

void	split_if_needed(t_dlist **head, t_expand *exp, char **ans, int i)
{
	char	*env_str;
	char	*done;

	env_str = expand_env(exp, exp->str + i + 1);
	if (*ans == NULL && env_str == NULL)
		return ;
	if (*ans == NULL)
		*ans = (char *)safe_calloc(1, sizeof(char));
	if (env_str != NULL && ft_strchr(env_str, ' '))
		split_and_addback(head, ans, env_str);
	else
	{
		done = *ans;
		*ans = safe_join(*ans, env_str);
		free(done);
	}
	free(env_str);
}

#include "expansion.h"

int	*make_dp_table(char *str)
{
	int	*dp_table;
	int	i;

	dp_table = (int *)xmalloc(sizeof(int) * (ft_strlen(str) + 1));
	dp_table[0] = 0;
	i = 1;
	while (str[i])
	{
		if (str[i - 1] == '\\')
			dp_table[i] = dp_table[i - 1] + 1;
		else
			dp_table[i] = 0;
		i++;
	}
	return (dp_table);
}

char	*init_quote_table(int size)
{
	char	*ans;
	int		i;

	ans = (char *)safe_calloc(size + 1, sizeof(char));
	i = 0;
	while (i < size)
	{
		ans[i] = 'n';
		++i;
	}
	return (ans);
}

static void	fill_single(char *str, t_expand *exp, int *i)
{
	int	j;

	j = *i + 1;
	while (str[j] && str[j] != '\'')
	{
		exp->quote_table[j] = 's';
		j++;
	}
	if (str[j] == '\'')
		++j;
	*i = j;
}

static void	fill_double(char *str, t_expand *exp, int *i)
{
	int	j;

	j = *i + 1;
	while (str[j])
	{
		if (str[j] == '\"' && !escaped(exp->escape_table[j]))
			break ;
		exp->quote_table[j] = 'd';
		j++;
	}
	if (str[j] == '\"')
		++j;
	*i = j;
}

void	make_quote_table(char *str, t_expand *exp)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !escaped(exp->escape_table[i]))
		{
			fill_single(str, exp, &i);
			continue ;
		}
		if (str[i] == '\"' && !escaped(exp->escape_table[i]))
		{
			fill_double(str, exp, &i);
			continue ;
		}
		++i;
	}
}

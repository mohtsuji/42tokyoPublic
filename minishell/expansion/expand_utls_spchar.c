#include "expansion.h"

void	deal_with_single(t_expand *exp, char **ans, int *i)
{
	int	j;

	j = *i + 1;
	while (exp->str[j] != '\0' && exp->str[j] != '\'')
	{
		copy_one_letter(ans, exp, j);
		++j;
	}
	if (exp->str[j] =='\'')
		++j;
	*i = j;
}

_Bool	skip_back_slash(t_expand *exp, int *i)
{
	if (exp->str[*i] == '\\' && !escaped(exp->escape_table[*i]) && \
	(exp->str[*i + 1] == '$' || exp->str[*i + 1] == '~' || \
	exp->str[*i + 1] == '\"' || exp->str[*i + 1] == '\\' || \
	exp->str[*i + 1] =='`'))
	{
		*i = *i + 1;
		return (true);
	}
	return (false);
}

_Bool	is_special(t_expand *exp, int i)
{
	char	c;

	c = exp->str[i];
	if (!escaped(exp->escape_table[i]) && \
	(c == '\\' || c == '\'' || c == '$' || c == '\"'))
		return (true);
	return (false);
}

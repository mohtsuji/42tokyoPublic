#include "expansion.h"

void	rd_deal_with_double(t_expand *exp, char **ans, int *i)
{
	int	j;

	j = *i + 1;
	while (exp->str[j] != '\0')
	{
		if (exp->str[j] == '\"' && !escaped(exp->escape_table[j]))
		{
			if (*ans == NULL)
				*ans = safe_dup("");
			break ;
		}
		if (exp->str[j] == '$' && !escaped(exp->escape_table[j]))
		{
			rd_expand_doller(exp, ans, &j);
			continue ;
		}
		if (skip_back_slash(exp, &j))
			continue ;
		else
			copy_one_letter(ans, exp, j);
		++j;
	}
	if (exp->str[j] == '\"')
		++j;
	*i = j;
}

_Bool	rd_deal_with_specialchar(t_expand *exp, char **ans, int *i)
{
	_Bool	rv;

	rv = true;
	if (exp->str[*i] == '\'' && !escaped(exp->escape_table[*i]))
		deal_with_single(exp, ans, i);
	else if (exp->str[*i] == '\"' && !escaped(exp->escape_table[*i]))
		rd_deal_with_double(exp, ans, i);
	else if (exp->str[*i] == '$' && !escaped(exp->escape_table[*i]))
		rv = rd_expand_doller(exp, ans, i);
	else if (exp->str[*i] == '\\' && !escaped(exp->escape_table[*i]))
		*i += 1;
	return (rv);
}

_Bool	rd_expand_str(t_dlist **head, t_expand *exp)
{
	int		i;
	char	*ans;

	i = 0;
	ans = NULL;
	while (exp->str[i])
	{
		if (is_special(exp, i))
		{
			if (rd_deal_with_specialchar(exp, &ans, &i) == false)
				return (false);
			continue ;
		}
		else
			copy_one_letter(&ans, exp, i);
		++i;
	}
	if (ans != NULL)
		addback_elm_with_data(head, ans, NULL);
	free(ans);
	ans = NULL;
	return (true);
}

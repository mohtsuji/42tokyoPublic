#include "expansion.h"

static void	arg_expand_doller(t_dlist **head, t_expand *exp, char **ans, int *i)
{
	if (exp->quote_table[*i] == 'd')
		substitute_doller(ans, exp, *i);
	else
		split_if_needed(head, exp, ans, *i);
	(*i)++;
	if (exp->str[*i] == '?')
		(*i)++;
	else
	{
		while (is_env_variable(exp->str[*i]))
			(*i)++;
	}
}

void	arg_deal_with_double(t_dlist **head, t_expand *exp, char **ans, int *i)
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
			arg_expand_doller(head, exp, ans, &j);
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

void	arg_deal_with_special(t_dlist **head, t_expand *exp, char **ans, int *i)
{
	if (exp->str[*i] == '\'' && !escaped(exp->escape_table[*i]))
		deal_with_single(exp, ans, i);
	else if (exp->str[*i] == '\"' && !escaped(exp->escape_table[*i]))
		arg_deal_with_double(head, exp, ans, i);
	else if (exp->str[*i] == '$' && !escaped(exp->escape_table[*i]))
		arg_expand_doller(head, exp, ans, i);
	else if (exp->str[*i] == '\\' && !escaped(exp->escape_table[*i]))
		*i += 1;
}

void	arg_expand_str(t_dlist **head, t_expand *exp)
{
	int		i;
	char	*ans;

	i = 0;
	ans = NULL;
	while (exp->str[i])
	{
		if (is_special(exp, i))
		{
			arg_deal_with_special(head, exp, &ans, &i);
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
}

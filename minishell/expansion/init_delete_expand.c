#include "expansion.h"

void	init_expand(t_expand *exp, char *s, t_env *env)
{
	exp->escape_table = make_dp_table(s);
	exp->quote_table = init_quote_table((int)ft_strlen(s) + 1);
	make_quote_table(s, exp);
	exp->str = s;
	exp->env = env;
}

void	delete_expand(t_expand *exp)
{
	free(exp->escape_table);
	free(exp->quote_table);
	exp->escape_table = NULL;
	exp->quote_table = NULL;
}

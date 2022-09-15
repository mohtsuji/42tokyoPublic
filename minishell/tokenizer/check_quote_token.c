#include "tokenizer.h"

static _Bool	unmatched_quotes(char *token, int *escape_table, int *i)
{
	char	quote;
	int		j;

	quote = token[*i];
	j = *i + 1;
	while (1)
	{
		if (token[j] == '\0')
		{
			ft_putstr_fd("minishell: unexpected EOF while looking for matching `", \
			STDERR_FILENO);
			ft_putchar_fd(quote, STDERR_FILENO);
			ft_putstr_fd("'\n", STDERR_FILENO);
			g_status = 2;
			return (true);
		}
		if (quote == '\'' && token[j] == '\'')
			break ;
		if (quote == '\"' && token[j] == quote && !escaped(escape_table[j]))
			break ;
		++j;
	}
	*i = j;
	return (false);
}

_Bool	check_quote_token(t_token *list)
{
	t_token	*last;
	char	*token;
	int		i;
	int		*escape_table;

	last = token_lstlast(list);
	last = last->prev;
	token = last->str;
	escape_table = make_dp_table(token);
	i = 0;
	while (token[i])
	{
		if (!escaped(escape_table[i]) && (token[i] == '\"' || token[i] == '\''))
		{
			if (unmatched_quotes(token, escape_table, &i))
			{
				free(escape_table);
				return (false);
			}
		}
		++i;
	}
	free(escape_table);
	return (true);
}

_Bool	token_empty(t_token **token_list)
{
	int	size;

	size = token_lstsize(*token_list);
	if (size == 0 || (size == 1 && (*token_list)->type == -1))
	{
		token_lstclear(token_list);
		return (true);
	}
	return (false);
}

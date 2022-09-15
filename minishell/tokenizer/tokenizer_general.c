#include "tokenizer.h"

static void	in_single_quotes(t_token **now, char *line, int *i, int *j)
{
	while (line[*i] != '\0')
	{
		(*now)->str[*j] = line[*i];
		if (line[(*i)] == '\'')
			break ;
		*i += 1;
		*j += 1;
	}
}

static void	in_quotes(t_token **now, char *line, int *i, int *j)
{
	char	quotes;
	int		quote_pos;

	quote_pos = *i;
	quotes = line[*i];
	(*now)->str[*j] = line[*i];
	*j += 1;
	*i += 1;
	if (count_escape(line, line + quote_pos - 1))
		return ;
	if (quotes == '\'')
	{
		in_single_quotes(now, line, i, j);
		return ;
	}
	if (count_escape(line, line + quote_pos - 1))
		return ;
	while (line[*i] != '\0')
	{
		(*now)->str[*j] = line[*i];
		if (line[(*i)] == quotes && !count_escape(line, line + *i - 1))
			break ;
		*i += 1;
		*j += 1;
	}
}

_Bool	end_of_a_token(char *line, int *i)
{
	int	token_type;

	token_type = check_type(line[*i], 0);
	if (token_type == SPACE && count_escape(line, line + *i - 1) != 0)
		return (false);
	if (token_type == GENERAL)
		return (false);
	return (true);
}

void	set_generaltoken(t_token **now, size_t len, char *line, int *i)
{
	int		j;
	t_token	*nxt;

	j = 0;
	while (line[*i] != '\0')
	{
		if (line[*i] == '\"' || line[*i] == '\'')
			in_quotes(now, line, i, &j);
		if (end_of_a_token(line, i))
			break ;
		(*now)->str[j++] = line[(*i)++];
	}
	(*now)->type = GENERAL;
	nxt = token_lstnew(len);
	(*now)->next = nxt;
	nxt->prev = *now;
	*now = nxt;
	--(*i);
}

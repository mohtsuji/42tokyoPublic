#include "tokenizer.h"

int	check_type(char c, char d)
{
	if (c == '>' && d == '>')
		return (DOUBLEGRT);
	if (c == '>')
		return (GREATER);
	if (c == '<')
		return (SMALLER);
	if (c == ';')
		return (SEMICOLON);
	if (c == '|')
		return (PIPE);
	if (c == '\n')
		return (NEWLINE);
	if (c == '\"')
		return (GENERAL);
	if (c == '\'')
		return (GENERAL);
	if (c == ' ')
		return (SPACE);
	if (c == '\t')
		return (TAB);
	return (GENERAL);
}

static _Bool	is_num_rd(char *line, int i)
{
	while (ft_isdigit(line[i]))
		++i;
	if (line[i] == '>' || line[i] == '<')
		return (true);
	return (false);
}

static void	type_setter(t_token **now, size_t len, char c)
{
	t_token	*nxt;

	nxt = token_lstnew(len);
	(*now)->str[0] = c;
	(*now)->type = check_type(c, 0);
	(*now)->next = nxt;
	nxt->prev = *now;
	*now = nxt;
}

void	start_tokenizer(char *line, t_token **list, size_t len)
{
	int		i;
	t_token	*now;

	i = 0;
	*list = token_lstnew(len);
	now = *list;
	while (line[i] != '\0')
	{
		if (is_num_rd(line, i))
			greatersmaller_n(&now, &i, line);
		else if (line[i] == '>' && line[i + 1] == '>')
			double_greater(&now, len, &i);
		else if (line[i] == '<' && line[i + 1] == '<')
			double_smaller(&now, len, &i);
		else if (line[i] == '>' || line[i] == '<' || \
		line[i] == ';' || line[i] == '|')
			type_setter(&now, len, line[i]);
		else if ((line[i] == '\t' || line[i] == ' ' || line[i] == '\n') && \
		count_escape(line, line + i - 1) == 0)
			ignore();
		else
			set_generaltoken(&now, len, line, &i);
		++i;
	}
}

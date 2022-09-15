#include "tokenizer.h"

void	double_greater(t_token **now, size_t len, int *i)
{
	t_token	*nxt;

	nxt = token_lstnew(len);
	(*now)->str[0] = '>';
	(*now)->str[1] = '>';
	(*now)->type = DOUBLEGRT;
	(*now)->next = nxt;
	nxt->prev = *now;
	*now = nxt;
	*i += 1;
}

void	double_smaller(t_token **now, size_t len, int *i)
{
	t_token	*nxt;

	nxt = token_lstnew(len);
	(*now)->str[0] = '<';
	(*now)->str[1] = '<';
	(*now)->type = SMALLER;
	(*now)->next = nxt;
	nxt->prev = *now;
	*now = nxt;
	*i += 1;
}

void	num_double_greater(t_token **now, char *line, int start, int end)
{
	t_token	*nxt;
	int		i;

	i = 0;
	nxt = token_lstnew(ft_strlen(line));
	while (start + i <= end)
	{
		(*now)->str[i] = line[start + i];
		++i;
	}
	(*now)->type = N_DOUBLEGRT;
	(*now)->next = nxt;
	nxt->prev = *now;
	*now = nxt;
}

void	num_greater_smaller(t_token **now, char *line, int start, int end)
{
	t_token	*nxt;
	int		i;

	i = 0;
	nxt = token_lstnew(ft_strlen(line));
	while (start + i <= end)
	{
		(*now)->str[i] = line[start + i];
		++i;
	}
	if (line[end] == '>')
		(*now)->type = N_GREATER;
	else
		(*now)->type = N_SMALLER;
	(*now)->next = nxt;
	nxt->prev = *now;
	*now = nxt;
}

void	greatersmaller_n(t_token **now, int *i, char *line)
{
	int	j;
	int	save;

	save = *i;
	j = *i;
	while (ft_isdigit(line[j]))
		j++;
	if (line[j] == '>' && line[j + 1] == '>')
	{
		*i = j + 1;
		num_double_greater(now, line, save, j + 1);
	}
	else if (line[j] == '>' || line[j] == '<')
	{
		*i = j;
		num_greater_smaller(now, line, save, j);
	}
}

#include "my_term.h"

static void	delete_string(t_termnl *term)
{
	char	*done;
	char	*head;
	char	*tail;
	int		index;
	int		len;

	done = term->line;
	index = cursor_to_index(term);
	head = safe_substr(term->line, 0, index);
	tail = safe_substr(term->line, index + 1, \
	ft_strlen(term->line) - index + 1);
	term->line = safe_join(head, tail);
	len = term->cursor_start + (int)ft_strlen(term->line);
	tputs(term->line, 1, ft_putchar);
	term->margin_count = len / term->col;
	term->endcol = len % term->col;
	if (term->endcol == 0)
	{
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		tputs(tgetstr("cr", NULL), 1, ft_putchar);
	}
	safe_free(&done);
	safe_free(&head);
	safe_free(&tail);
}

static int	left_margin(t_termnl *term)
{
	reset_screen(term);
	if (term->current_col == 0 && term->current_line > 0)
	{
		delete_string(term);
		term->current_col = term->col - 1;
		term->current_line--;
		adjust_line(term->current_line, term->margin_count);
		adjust_col(term->current_col, term->endcol);
	}
	else
	{
		delete_string(term);
		term->current_col--;
		if (term->current_line > 0 && term->current_col < 0)
			term->current_col = 0;
		else if (term->current_line == 0 && \
		term->current_col < term->cursor_start)
			term->current_col = term->cursor_start;
		adjust_line(term->current_line, term->margin_count);
		adjust_col(term->current_col, term->endcol);
	}
	return (READ_CONT);
}

int	delete_char(t_termnl *term)
{
	if (term->current_line == 0 && term->current_col == term->cursor_start)
		return (READ_CONT);
	if (term->margin_count > 0)
		return (left_margin(term));
	if (term->current_col > term->cursor_start)
	{
		reset_screen(term);
		delete_string(term);
		term->current_col--;
		if (term->current_col < term->cursor_start)
			term->current_col = term->cursor_start;
		adjust_col(term->current_col, term->endcol);
	}
	return (READ_CONT);
}

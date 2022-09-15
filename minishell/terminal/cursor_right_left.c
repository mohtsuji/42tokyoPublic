#include "my_term.h"

static _Bool	cannot_move(t_termnl *term)
{
	int	cur;
	int	end;

	if (term->current_line < term->margin_count)
		return (false);
	cur = term->current_line * (term->col - 1) + \
	term->current_col + term->current_line;
	end = term->margin_count * (term->col - 1) + \
	term->endcol + term->margin_count;
	if (cur < end)
		return (false);
	return (true);
}

int	move_left(t_termnl *term)
{
	if (term->current_line > 0)
	{
		if (term->current_col == 0)
		{
			tputs(tgetstr("up", NULL), 1, ft_putchar);
			adjust_col(term->col -1, term->current_col);
			term->current_col = term->col - 1;
			term->current_line--;
			return (READ_CONT);
		}
		tputs(tgetstr("le", NULL), 1, ft_putchar);
		term->current_col--;
		return (READ_CONT);
	}
	if (term->current_col <= term->cursor_start)
		return (READ_CONT);
	tputs(tgetstr("le", NULL), 1, ft_putchar);
	term->current_col--;
	return (READ_CONT);
}

int	move_right(t_termnl *term)
{
	if (cannot_move(term))
		return (READ_CONT);
	if (term->current_col == term->col - 1 && \
	term->current_line < term->margin_count)
	{
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		term->current_line++;
		term->current_col = 0;
		return (READ_CONT);
	}
	tputs(tgetstr("nd", NULL), 1, ft_putchar);
	term->current_col++;
	return (READ_CONT);
}

#include "my_term.h"

static int	at_end(t_termnl *term)
{
	int	cur;
	int	end;

	cur = term->current_line * (term->col - 1) + \
	term->current_col + term->current_line;
	end = term->margin_count * (term->col - 1) + \
	term->endcol + term->margin_count;
	return (cur == end);
}

static int	join_input(t_termnl *term, char *buf)
{
	char	*done;
	int		len;

	done = term->line;
	term->line = safe_join(term->line, buf);
	safe_free(&done);
	len = term->cursor_start + ft_strlen(term->line);
	term->endcol = len % term->col;
	term->current_col = term->endcol;
	term->margin_count = len / term->col;
	term->current_line = term->margin_count;
	tputs(buf, 1, ft_putchar);
	if (term->endcol == 0)
	{
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		tputs(tgetstr("cr", NULL), 1, ft_putchar);
	}
	return (READ_CONT);
}

int	edit_line(t_termnl *term, char *buf)
{
	if (buf[0] == '\t')
	{
		if (term->current_col == term->endcol)
			return (join_input(term, TAB_SPACE));
		return (insert_input(term, TAB_SPACE));
	}
	if (!ft_isprint((int)buf[0]))
		return (READ_CONT);
	if (at_end(term))
		return (join_input(term, buf));
	return (insert_input(term, buf));
}

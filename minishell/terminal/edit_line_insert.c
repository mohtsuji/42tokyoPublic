#include "my_term.h"

static void	adjust_display(int len, t_termnl *term)
{
	tputs(term->line, 1, ft_putchar);
	if (len % term->col == 0)
	{
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		tputs(tgetstr("cr", NULL), 1, ft_putchar);
	}
	adjust_line(term->current_line, term->margin_count);
	adjust_col(term->current_col, \
	(term->cursor_start + ft_strlen(term->line)) % term->col);
}

static void	append_char(t_termnl *term, char *buf)
{
	char	*head;
	char	*tail;
	char	*done;
	int		len;

	head = safe_dup("");
	tail = safe_join(buf, term->line);
	done = term->line;
	term->line = safe_join(head, tail);
	safe_free(&done);
	len = term->cursor_start + ft_strlen(term->line);
	term->endcol = len % term->col;
	term->current_line = \
	(term->cursor_start + (int)ft_strlen(head)) / term->col;
	term->current_col = (term->current_col + (int)ft_strlen(buf)) % term->col;
	term->margin_count = len / term->col;
	adjust_display(len, term);
	safe_free(&head);
	safe_free(&tail);
}

static void	insert_string(t_termnl *term, char *buf)
{
	char	*done;
	char	*head;
	char	*tail;
	int		index;
	int		len;

	index = cursor_to_index(term);
	head = safe_substr(term->line, 0, index + 1);
	tail = safe_substr(term->line, index + 1, \
	(int)ft_strlen(term->line) - index - 1);
	done = head;
	head = safe_join(head, buf);
	safe_free(&done);
	done = term->line;
	term->line = safe_join(head, tail);
	safe_free(&done);
	len = term->cursor_start + ft_strlen(term->line);
	term->endcol = len % term->col;
	term->current_line = \
	(term->cursor_start + (int)ft_strlen(head)) / term->col;
	term->current_col = (term->current_col + (int)ft_strlen(buf)) % term->col;
	term->margin_count = len / term->col;
	adjust_display(len, term);
	safe_free(&head);
	safe_free(&tail);
}

int	insert_input(t_termnl *term, char *buf)
{
	reset_screen(term);
	if (term->current_col == term->cursor_start && term->current_line == 0)
		append_char(term, buf);
	else
		insert_string(term, buf);
	return (READ_CONT);
}

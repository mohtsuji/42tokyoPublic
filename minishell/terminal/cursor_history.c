#include "my_term.h"

static void	latest_history(t_termnl *term)
{
	safe_free(&(term->line));
	term->line = ft_strdup("");
	if (term->line == NULL)
		exit_with_msg("lastes_history: malloc error\n");
}

static void	update_cusor(t_termnl *term)
{
	int	len;

	len = term->cursor_start + ft_strlen(term->line);
	term->margin_count = len / term->col;
	term->current_col = len % term->col;
	term->endcol = term->current_col;
	term->current_line = term->margin_count;
	if (len % term->col == 0)
	{
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		tputs(tgetstr("cr", NULL), 1, ft_putchar);
	}
}

int	up_history(t_termnl *term)
{
	if (term->hist_size == 0)
		return (READ_CONT);
	reset_screen(term);
	if (term->current_hist > 0)
		term->current_hist--;
	tputs(term->history[term->current_hist], 1, ft_putchar);
	safe_free(&(term->line));
	term->line = safe_dup(term->history[term->current_hist]);
	update_cusor(term);
	return (READ_CONT);
}

int	down_history(t_termnl *term)
{
	if (term->hist_size == 0)
		return (READ_CONT);
	reset_screen(term);
	if (term->history[term->current_hist] != NULL)
		term->current_hist++;
	if (term->history[term->current_hist] == NULL)
		latest_history(term);
	else
	{
		tputs(term->history[term->current_hist], 1, ft_putchar);
		safe_free(&(term->line));
		term->line = safe_dup(term->history[term->current_hist]);
	}
	update_cusor(term);
	return (READ_CONT);
}

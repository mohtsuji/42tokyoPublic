#include "my_term.h"

int	cursor_to_index(t_termnl *term)
{
	int	ans;

	ans = term->current_line * (term->col - 1) + \
	term->current_col + term->current_line - term->cursor_start - 1;
	if (ans < 0)
		return (0);
	return (ans);
}

void	adjust_col(int wanted_col, int now_col)
{
	while (wanted_col < now_col)
	{
		tputs(tgetstr("le", NULL), 1, ft_putchar);
		now_col--;
	}
	while (wanted_col > now_col)
	{
		tputs(tgetstr("nd", NULL), 1, ft_putchar);
		now_col++;
	}
}

void	adjust_line(int wanted_line, int now_line)
{
	while (wanted_line < now_line)
	{
		tputs(tgetstr("up", NULL), 1, ft_putchar);
		now_line--;
	}
}

void	reset_screen(t_termnl *term)
{
	int	count;

	count = term->current_line;
	while (count > 0)
	{
		tputs(tgetstr("up", NULL), 1, ft_putchar);
		count--;
	}
	tputs(tgetstr("cr", NULL), 1, ft_putchar);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	tputs(term->prompt, 1, ft_putchar);
}

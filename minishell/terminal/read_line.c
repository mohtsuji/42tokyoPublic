#include "my_term.h"

static int	input_newline(t_termnl *term)
{
	char	*ptr;

	ptr = term->line;
	while (*ptr)
		++ptr;
	--ptr;
	if (count_escape(term->line, ptr) == 0)
	{
		tputs("\n", 1, ft_putchar);
		return (READ_STOP);
	}
	*ptr = '\0';
	update_struct_term(term, "> ");
	tputs("\n", 1, ft_putchar);
	tputs("> ", 1, ft_putchar);
	return (READ_CONT);
}

int	clear_line(t_termnl *term)
{
	g_status = 1;
	safe_free(&(term->line));
	safe_free(&(term->prev_line));
	safe_free(&(term->prompt));
	term->current_col = term->cursor_start;
	term->current_line = 0;
	term->margin_count = 0;
	term->endcol = term->cursor_start;
	term->current_hist = term->hist_size - 1;
	term->line = ft_strdup("");
	term->prompt = ft_strdup(PROMPT);
	if (term->line == NULL || term->prompt == NULL)
		exit_with_msg_terminal(term->original, \
		"clear line: malloc error\n");
	tputs("\n", 1, ft_putchar);
	tputs(term->prompt, 1, ft_putchar);
	return (READ_CONT);
}

static int	key_manage(char *buf, t_termnl *term)
{
	if (ft_strlen(buf) == 0)
		return (READ_CONT);
	if (buf[0] == '\n')
		return (input_newline(term));
	if ((int)buf[0] == EOT)
	{
		if (ft_strlen(term->line) == 0)
			return (CTLD);
		return (READ_CONT);
	}
	if (buf[0] == DEL)
		return (delete_char(term));
	if ((int)buf[0] == ETX)
		return (clear_line(term));
	if (ft_strmatch(buf, LEFT))
		return (move_left(term));
	if (ft_strmatch(buf, RIGHT))
		return (move_right(term));
	if (ft_strmatch(buf, UP))
		return (up_history(term));
	if (ft_strmatch(buf, DOWN))
		return (down_history(term));
	return (edit_line(term, buf));
}

static char	*read_edit_line(int read_loop, \
struct termios *origin, char *hist_path)
{
	t_termnl	*term;
	char		*buf;
	char		*ans;
	ssize_t		r;

	term = init_struct_term(origin, hist_path);
	read_loop = READ_CONT;
	ft_putstr_fd(PROMPT, STDOUT_FILENO);
	while (read_loop == READ_CONT)
	{
		buf = (char *)malloc(READBUF_SIZE * sizeof(char));
		r = read(STDIN_FILENO, buf, READBUF_SIZE - 1);
		buf[r] = '\0';
		read_loop = key_manage(buf, term);
		free(buf);
	}
	if (read_loop == CTLD)
		return (return_null_exit());
	ans = safe_join_no_exit(term->prev_line, term->line);
	if (ans == NULL)
		exit_with_msg_terminal(origin, "read_edit_line: malloc error\n");
	add_history(ans, origin, hist_path);
	free_term(&term);
	return (ans);
}

char	*start_reading(char *hist_path)
{
	struct termios	new_terminal;
	struct termios	original_terminal;
	char			*term_name;
	char			*line;

	if (isatty(STDIN_FILENO) == 0)
	{
		ft_putstr_fd("isatty error\n", STDERR_FILENO);
		return (NULL);
	}
	term_name = getenv("TERM");
	tgetent(NULL, term_name);
	tcgetattr(STDIN_FILENO, &original_terminal);
	new_terminal = original_terminal;
	new_terminal.c_lflag &= ~(ICANON);
	new_terminal.c_lflag &= ~(ECHO);
	new_terminal.c_lflag &= ~(ISIG);
	new_terminal.c_cc[VMIN] = 1;
	new_terminal.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_terminal);
	line = read_edit_line(0, &original_terminal, hist_path);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_terminal);
	return (line);
}

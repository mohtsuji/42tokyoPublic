#include "my_term.h"

t_termnl	*init_struct_term(struct termios *origin, char *hist_path)
{
	t_termnl	*term;

	term = (t_termnl *)malloc(sizeof(t_termnl));
	if (term == NULL)
		exit_with_msg_terminal(origin, "init_struct_term: malloc error\n");
	term->prev_line = NULL;
	term->prompt = ft_strdup(PROMPT);
	term->col = tgetnum("co");
	term->cursor_start = ft_strlen(PROMPT);
	term->current_col = term->cursor_start;
	term->current_line = 0;
	term->margin_count = 0;
	term->endcol = term->cursor_start;
	term->current_hist = 0;
	term->line = ft_strdup("");
	if (term->line == NULL || term->prompt == NULL)
		exit_with_msg_terminal(origin, "init_struct_term2: malloc error\n");
	term->original = origin;
	open_history(term, hist_path);
	return (term);
}

t_termnl	*update_struct_term(t_termnl *term, char *newprompt)
{
	char	*done;

	term->col = tgetnum("co");
	term->cursor_start = ft_strlen(newprompt);
	term->current_col = term->cursor_start;
	term->current_line = 0;
	term->margin_count = 0;
	term->endcol = term->cursor_start;
	done = term->prev_line;
	term->prev_line = safe_join_no_exit(term->prev_line, term->line);
	free(done);
	free(term->prompt);
	term->prompt = ft_strdup(newprompt);
	if (term->prev_line == NULL || term->prompt == NULL)
		exit_with_msg_terminal(term->original, \
		"init_struct_term2: malloc error\n");
	done = term->line;
	term->line = ft_strdup("");
	free(done);
	if (term->line == NULL)
		exit_with_msg_terminal(term->original, \
		"init_struct_term2: malloc error\n");
	return (term);
}

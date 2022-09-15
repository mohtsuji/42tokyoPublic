#include "my_term.h"

static char	*read_file(char *hist_path)
{
	char	*line;
	char	*join;
	char	*done;
	int		fd;

	join = safe_dup("");
	fd = open(hist_path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		done = join;
		join = safe_join(join, "\n");
		safe_free(&done);
		done = join;
		join = safe_join(join, line);
		safe_free(&done);
		safe_free(&line);
	}
	safe_free(&line);
	close(fd);
	return (join);
}

void	open_history(t_termnl *term, char *hist_path)
{
	struct stat	buf;
	char		*total;
	int			count;
	int			fd;

	if (lstat(hist_path, &buf) < 0)
	{
		fd = open(hist_path, O_CREAT, 0644);
		if (fd < 0)
			exit_with_msg_terminal(term->original, "open_history: open error\n");
		close(fd);
	}
	total = read_file(hist_path);
	term->history = safe_split(total, '\n');
	safe_free(&total);
	count = 0;
	while (term->history[count] != NULL)
		++count;
	term->hist_size = count;
	term->current_hist = count;
}

void	add_history(char *line, struct termios *origin, char *hist_path)
{
	int		fd;
	char	*new;

	if (ft_strlen(line) == 0)
		return ;
	fd = open(hist_path, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd < 0)
		exit_with_msg_terminal(origin, "add_history: open error\n");
	new = ft_strjoin(line, "\n");
	if (new == NULL)
		exit_with_msg_terminal(origin, "add_history: malloc error\n");
	ft_putstr_fd(new, fd);
	safe_free(&new);
	close(fd);
}

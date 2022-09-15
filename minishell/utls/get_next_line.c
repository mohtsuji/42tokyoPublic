#include "utls.h"

static int	safe_free_withnum(char **ptr, int num)
{
	free(*ptr);
	*ptr = NULL;
	return (num);
}

static int	join(char **store, char **buf)
{
	char	*tmp;

	tmp = ft_strjoin(*store, *buf);
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	free(*store);
	safe_free(buf);
	*store = tmp;
	return (1);
}

static int	last(char **line, char **store)
{
	*line = ft_strdup(*store);
	if (*line == NULL)
		exit(EXIT_FAILURE);
	safe_free(store);
	return (0);
}

static int	set_line(char **line, char **store)
{
	char	*tmp;
	char	*save;

	tmp = ft_strchr(*store, '\n');
	*tmp = '\0';
	*line = ft_strdup(*store);
	if (*line == NULL)
		exit(EXIT_FAILURE);
	save = ft_strdup(tmp + 1);
	if (save == NULL)
		exit(EXIT_FAILURE);
	safe_free(store);
	*store = save;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char		*store;
	char			*buf;
	int				result;
	ssize_t			rv;

	result = 0;
	if (fd < 0 || fd == 1 || fd == 2)
		return (-1);
	if (store == NULL)
		store = safe_dup("");
	while (ft_strchr(store, '\n') == NULL)
	{
		buf = (char *)xmalloc(sizeof(char) * (BUFFER_SIZE + 1));
		rv = read(fd, buf, BUFFER_SIZE);
		if (rv < 0)
			return (safe_free_withnum(&store, -1));
		buf[rv] = '\0';
		result = join(&store, &buf);
		if (rv == 0)
			return (result = last(line, &store));
	}
	if (result == -1)
		return (-1);
	return (result = set_line(line, &store));
}

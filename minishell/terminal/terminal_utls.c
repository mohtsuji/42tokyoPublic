#include "my_term.h"

int	ft_putchar(int c)
{
	write(STDOUT_FILENO, &c, 1);
	return (1);
}

char	*return_null_exit(void)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	return (NULL);
}

void	free_term(t_termnl **term)
{
	free((*term)->line);
	free((*term)->prev_line);
	free((*term)->prompt);
	free_multi(&((*term)->history));
	free(*term);
	*term = NULL;
}

void	exit_with_msg_terminal(struct termios *origin, char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
	tcsetattr(STDIN_FILENO, STDOUT_FILENO, origin);
	exit(EXIT_FAILURE);
}

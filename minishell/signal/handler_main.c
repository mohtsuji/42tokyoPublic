#include "signal.h"

void	sigquit_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\b\b  \b\b", STDOUT_FILENO);
}

void	sigint_handler(int sig)
{
	(void)sig;
}

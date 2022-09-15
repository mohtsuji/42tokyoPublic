#include "signal.h"

void	ft_sig_ign(int sig)
{
	(void)sig;
}

void	sig_msg(int sig)
{
	if (sig == SIGINT)
		ft_putstr_fd("\n", STDOUT_FILENO);
	else if (sig == SIGQUIT)
		ft_putstr_fd("^\\Quit: 3\n", STDOUT_FILENO);
}

void	signal_handler_pipe(int status)
{
	int	sig;

	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGINT)
			ft_putstr_fd("\n", STDOUT_FILENO);
		else if (sig == SIGQUIT)
			ft_putstr_fd("^\\", STDOUT_FILENO);
	}
}

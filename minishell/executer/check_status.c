#include "executer.h"

void	check_status(int status)
{
	int	s;

	if (WIFEXITED(status))
	{
		s = WEXITSTATUS(status);
		g_status = s;
	}
	if (WIFSIGNALED(status))
	{
		s = WTERMSIG(status);
		sig_msg(s);
		g_status = 128 + s;
	}
}

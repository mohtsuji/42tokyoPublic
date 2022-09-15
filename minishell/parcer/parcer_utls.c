#include "parcer.h"

void	put_error(t_token **lst)
{
	char	*str;

	if ((*lst)->type <= PIPE)
		str = (*lst)->str;
	else
		str = "newline";
	ft_putstr_fd("minishell: syntax error near unexpected token `", \
	STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
	g_status = 2;
}

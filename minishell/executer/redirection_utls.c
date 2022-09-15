#include "executer.h"

int	get_num(char *rd_sign)
{
	int	ans;

	ans = 0;
	while (*rd_sign && ft_isdigit((*rd_sign)))
	{
		ans = ans * 10 + (*rd_sign - '0');
		if (ans > FD_MAX)
			return (-1);
		rd_sign++;
	}
	return (ans);
}

void	undo_redirection(t_shell *shell)
{
	int	i;

	i = 0;
	while (i <= FD_MAX)
	{
		if (shell->usedfd[i] != -1)
		{
			dup2(shell->usedfd[i], i);
			shell->usedfd[i] = -1;
		}
		++i;
	}
}

int	rd_forground(t_ast *node, t_shell *shell)
{
	if (!set_redirection(node->command->rd, shell))
	{
		undo_redirection(shell);
		return (LOOP);
	}
	undo_redirection(shell);
	return (LOOP);
}

int	save_and_dup(int to_fd)
{
	int	old_fd;

	old_fd = to_fd;
	to_fd = dup(to_fd);
	close(old_fd);
	return (to_fd);
}

void	skip_digit(char **str)
{
	while (ft_isdigit(**str))
		(*str)++;
}

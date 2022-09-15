#include "../includes/minishell.h"

int	check_n(char *str)
{
	int	i;

	i = 1;
	if (ft_strlen(str) < 2)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	count_wc(t_cmd *cmd)
{
	int	wc;

	wc = 0;
	while (cmd->arg[wc] != NULL)
		wc++;
	return (wc);
}

void	check_haihun(t_cmd *cmd, int *i, int *flag)
{
	while (cmd->arg[*i] != NULL)
	{
		if (cmd->arg[*i][0] == '-')
		{
			if (check_n(cmd->arg[*i]) == 0)
				break ;
			*flag = 1;
		}
		else
			break ;
		(*i)++;
	}
}

int	our_echo(t_cmd *cmd)
{
	int		i;
	int		wc;
	int		flag;

	wc = count_wc(cmd);
	if (wc == 1)
		write(1, "\n", 1);
	else
	{
		i = 1;
		flag = 0;
		check_haihun(cmd, &i, &flag);
		while (i < wc)
		{
			ft_putstr_fd(cmd->arg[i], STDOUT_FILENO);
			i++;
			if (i != wc)
				write(1, " ", 1);
		}
		if (flag == 0)
			write(1, "\n", 1);
	}
	return (0);
}

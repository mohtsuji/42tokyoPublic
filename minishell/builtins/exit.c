#include "../includes/minishell.h"

int	count_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] != 0)
		i++;
	return (i);
}

int	too_many_arguments(int *status)
{
	ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	*status = 1;
	return (LOOP);
}

void	set_status(unsigned long long count, int *status, int mi)
{
	while (count > 255)
		count = count % 256;
	if (mi == -1)
		*status = 256 - count;
	else
		*status = count;
}

void	numeric_argument_required(int *status, char *str)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	*status = 255;
}

int	our_exit(t_cmd *cmd, int *status)
{
	unsigned long long	count;
	int					mi;
	int					arg;

	mi = 1;
	ft_putstr_fd("exit\n", 2);
	arg = count_arg(cmd->arg);
	if (arg >= 2)
	{
		if (ft_atol(cmd->arg[1], &mi, &count) == 0)
			numeric_argument_required(status, cmd->arg[1]);
		else if (arg > 2)
			return (too_many_arguments(status));
		else if ((mi == -1 && count > 9223372036854775808ULL)
			|| (mi == 1 && count > 9223372036854775807))
			numeric_argument_required(status, cmd->arg[1]);
		else
			set_status(count, status, mi);
	}
	else
		*status = 0;
	return (STOP_LOOP);
}

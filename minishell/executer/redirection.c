#include "executer.h"

_Bool	set_redirection(char **rd_list, t_shell *shell)
{
	int		i;
	_Bool	value;

	i = 0;
	value = true;
	if (rd_list == NULL)
		return (true);
	while (rd_list[i + 1] != NULL)
	{
		if (ft_strchr(rd_list[i], '>'))
			value = right_rd(rd_list[i], rd_list[i + 1], shell);
		else if (ft_strchr(rd_list[i], '<'))
			value = left_rd(rd_list[i], rd_list[i + 1], shell);
		if (!value)
			return (false);
		++i;
	}
	return (true);
}

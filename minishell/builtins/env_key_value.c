#include "../includes/minishell.h"

void	get_key_value(char *original, char **key, char **value, int flag)
{
	char	*tmp;
	char	*str;

	str = safe_dup(original);
	tmp = ft_strchr(str, '=');
	if (flag == 2)
	{
		tmp = tmp - 1;
		tmp[0] = '\0';
		tmp[1] = '\0';
	}
	else if (tmp)
		tmp[0] = '\0';
	*key = safe_dup(str);
	if (tmp == NULL)
		*value = safe_dup("\0");
	else if (flag == 2)
		*value = safe_dup(tmp + 2);
	else
		*value = safe_dup(tmp + 1);
	safe_free(&str);
}

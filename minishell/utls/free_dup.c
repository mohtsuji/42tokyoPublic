#include "../includes/minishell.h"

void	safe_trijoin(char **ans, char *s1, char *s2, char *s3)
{
	*ans = ft_trijoin(s1, s2, s3);
	if (*ans == NULL)
		exit(1);
	return ;
}

void	safe_strjoin(char **ans, char *s1, char *s2)
{
	*ans = ft_strjoin(s1, s2);
	if (*ans == NULL)
		exit(1);
	return ;
}

void	free_dup(char **ans, char *s)
{
	safe_free(ans);
	*ans = ft_strdup(s);
	if (*ans == NULL)
		exit(1);
	return ;
}

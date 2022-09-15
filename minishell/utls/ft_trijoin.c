#include "utls.h"

char	*ft_trijoin(char *s1, char *s2, char *s3)
{
	char	*new;
	char	*tmp;

	if (!s1 || !s2 || !s3)
		return (NULL);
	tmp = ft_strjoin(s1, s2);
	new = ft_strjoin(tmp, s3);
	free(tmp);
	return (new);
}

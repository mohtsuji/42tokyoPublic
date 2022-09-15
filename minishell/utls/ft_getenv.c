#include "utls.h"

t_env	*ft_getenv(char *str, t_env *env)
{
	t_env	*now;

	now = env;
	while (now != NULL)
	{
		if (ft_strmatch(now->key, str) == 1)
			return (now);
		now = now->next;
	}
	return (NULL);
}

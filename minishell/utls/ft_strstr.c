#include "utls.h"

int	ft_strstr(char *big, char *little)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little == NULL || big == NULL)
		return (0);
	while (little[i] != 0)
	{
		while (big[j] != 0)
		{
			if (big[j] == little[i])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

#include "libft.h"
#include <stdio.h>

long	ft_atoi(const char *str)
{
	const char	*s;
	long		ans;
	int			sign;

	s = str;
	ans = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (2147483648);
		ans = ans * 10 + (*s - '0');
		++s;
	}
	return (sign * ans);
}

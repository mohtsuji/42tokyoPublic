#include "utls.h"

void	plus_minus_flag(int *flag, const char **s, int *sign)
{
	*flag = 1;
	if (**s == '-')
		*sign = -1;
	++(*s);
}

void	to_num(const char **s, _Bool *yes_num, unsigned long long *ans)
{
	*yes_num = true;
	*ans = *ans * 10 + (**s - '0');
	++(*s);
}

_Bool	ft_atol(const char *str, int *sign, unsigned long long *ans)
{
	const char	*s;
	int			flag;
	_Bool		yes_num;

	s = str;
	*ans = 0;
	flag = 0;
	yes_num = false;
	while (*s == ' ')
		s++;
	if (*s == '-' || *s == '+')
		plus_minus_flag(&flag, &s, sign);
	if (flag == 1 && *s == '\0')
		return (0);
	while (*s >= '0' && *s <= '9')
		to_num(&s, &yes_num, ans);
	while (*s == ' ')
		s++;
	if (*s != '\0')
		return (0);
	if (yes_num == false)
		return (0);
	return (1);
}

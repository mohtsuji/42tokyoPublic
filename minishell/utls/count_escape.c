#include "utls.h"

int	count_escape(char *head, char *now)
{
	int	count;

	count = 0;
	while (now >= head && *now == '\\')
	{
		++count;
		now--;
	}
	return (count % 2);
}

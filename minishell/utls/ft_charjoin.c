#include "utls.h"

char	*ft_charjoin(char const *s1, char c)
{
	size_t	fullsize;
	char	*new;
	char	*itr;

	if (!s1)
		return (0);
	fullsize = ft_strlen(s1) + 2;
	new = (char *)safe_calloc(fullsize, sizeof(char));
	itr = new;
	while (*s1)
		*itr++ = *s1++;
	*itr = c;
	return (new);
}

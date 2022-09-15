#include "utls.h"

void	*xmalloc(size_t size)
{
	void	*ans;

	ans = malloc(size);
	if (ans == NULL)
	{
		ft_putstr_fd("malloc error in xmalloc\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (ans);
}

void	*safe_calloc(size_t count, size_t size)
{
	void	*ans;

	ans = ft_calloc(count, size);
	if (ans == NULL)
		exit(EXIT_FAILURE);
	return (ans);
}

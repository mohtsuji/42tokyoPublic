#include "utls.h"

void	free_multi(char ***arr)
{
	int	x;

	x = 0;
	if (*arr == NULL)
		return ;
	while ((*arr)[x] != NULL)
	{
		free((*arr)[x]);
		(*arr)[x] = NULL;
		++x;
	}
	free(*arr);
	*arr = NULL;
}

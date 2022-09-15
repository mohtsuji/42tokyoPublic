#include "utls.h"

void	safe_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

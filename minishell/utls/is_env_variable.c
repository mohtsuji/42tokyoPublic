#include "utls.h"

_Bool	is_env_variable(char c)
{
	return (ft_isalnum(c) || c == '_');
}

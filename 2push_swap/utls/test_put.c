#include "../push_swap.h"
#include "../libft/libft.h"

void	test_put(t_str *init)
{
	t_str	*current;

	current = init;
	if (current == NULL)
	{
		printf("NULL\n");
		fflush(stdout);
		return ;
	}
	while (1)
	{
		printf("num=%ld\n", current->num);
		fflush(stdout);
		if (current->next != NULL)
			current = current->next;
		if (current == init)
			break ;
	}
}

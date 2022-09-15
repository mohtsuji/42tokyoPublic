#include "../push_swap.h"
#include "../libft/libft.h"

void	s_stack(t_str **init, char name, t_tool *tool)
{
	t_str	*fir;
	t_str	*sec;

	sec = str_lstnew((*init)->num);
	fir = str_lstnew((*init)->next->num);
	(*init)->prev->next = fir;
	fir->prev = (*init)->prev;
	fir->next = sec;
	sec->prev = fir;
	sec->next = (*init)->next->next;
	(*init)->next->next->prev = sec;
	free((*init)->next);
	free(*init);
	*init = fir;
	if (name == 'a')
		tool_lstadd_back(tool, "sa\n");
	if (name == 'b')
		tool_lstadd_back(tool, "sb\n");
}

void	r_stack(t_str **init, char name, t_tool *tool)
{
	if (name == 'a')
		tool_lstadd_back(tool, "ra\n");
	else if (name == 'b')
		tool_lstadd_back(tool, "rb\n");
	if ((*init)->next == *init)
		return ;
	(*init) = (*init)->next;
}

void	rr_stack(t_str **init, char name, t_tool *tool)
{
	if (name == 'a')
		tool_lstadd_back(tool, "rra\n");
	else if (name == 'b')
		tool_lstadd_back(tool, "rrb\n");
	if ((*init)->next == *init)
		return ;
	*init = (*init)->prev;
}

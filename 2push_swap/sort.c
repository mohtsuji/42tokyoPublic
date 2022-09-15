#include "push_swap.h"
#include "./libft/libft.h"

void	two_sort(t_str **init, char name, t_tool *tool)
{
	t_str	*nex;
	long	tmp;

	nex = (*init)->next;
	if ((*init)->num > nex->num)
	{
		tmp = (*init)->num;
		(*init)->num = (*init)->next->num;
		(*init)->next->num = tmp;
		s_stack(init, name, tool);
	}
	return ;
}

void	three_sort(t_str **init, char name, t_tool *tool)
{
	long	inin;
	long	secn;
	long	thrn;

	inin = (*init)->num;
	secn = (*init)->next->num;
	thrn = (*init)->next->next->num;
	if (inin > secn && secn < thrn && inin < thrn)
		s_stack(init, name, tool);
	else if (inin > secn && secn > thrn && inin > thrn)
	{
		s_stack(init, name, tool);
		rr_stack(init, name, tool);
	}
	else if (inin > secn && secn < thrn && inin > thrn)
		r_stack(init, name, tool);
	else if (inin < secn && secn > thrn && inin < thrn)
	{
		s_stack(init, name, tool);
		r_stack(init, name, tool);
	}
	else if (inin < secn && secn > thrn && inin > thrn)
		rr_stack(init, name, tool);
}

void	under6_sort(t_str **init_a, t_str **init_b, long size, t_tool *tool)
{
	if (size == 1)
		return ;
	else if (size == 2)
		two_sort(init_a, tool->name, tool);
	else if (size == 3)
		three_sort(init_a, tool->name, tool);
	else
	{
		tool->a_size = size;
		move_until_a3(init_a, init_b, size, tool);
		three_sort(init_a, tool->name, tool);
		return_to_a(init_a, init_b, size, tool);
	}
}

void	over6_sort(t_str **init_a, t_str **init_b, t_tool *tool)
{
	int		init_size;
	t_posi	*b_last;

	init_size = tool->size;
	while (tool->size > 6)
		init_half_set(init_a, init_b, tool);
	while (tool->size != init_size)
	{
		if (tool->a != NULL)
		{
			if (tool->a->size <= 6)
				a_sort_merge(init_a, init_b, tool);
			else
				a_half_set(init_a, init_b, tool);
		}
		else
		{
			b_last = posi_lstlast(tool->b);
			if (b_last->size <= 6)
				b_sort_merge(init_a, init_b, tool);
			else
				b_half_set(init_a, init_b, tool);
		}
	}
}

void	sort_main(int size, t_str **init_a, t_tool *tool)
{
	t_str	*init_b;

	tool->a = NULL;
	tool->b = NULL;
	init_b = NULL;
	if (size <= 6)
		under6_sort(init_a, &init_b, size, tool);
	else
		over6_sort(init_a, &init_b, tool);
	put_operation(tool->ope);
	return ;
}

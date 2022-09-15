#include "../push_swap.h"
#include "../libft/libft.h"

void	init_half_set(t_str **init_a, t_str **init_b, t_tool *tool)
{
	int	move_size;

	tool->pivot_size = tool->size;
	move_size = tool->size / 2;
	tool->size -= move_size;
	half_set(init_a, init_b, tool, move_size);
	free(tool->a);
	tool->a = NULL;
	posi_lstadd_back(&(tool->a), tool->size);
}

void	a_sort_merge(t_str **init_a, t_str **init_b, t_tool *tool)
{
	t_posi	*b_last;

	tool->name = 'a';
	q_under6_sort(init_a, init_b, tool->a->size, tool);
	b_last = posi_lstlast(tool->b);
	if (b_last != NULL)
		rq_under6_sort(init_b, init_a, b_last->size, tool);
	merge(init_a, init_b, tool);
}

void	a_half_set(t_str **init_a, t_str **init_b, t_tool *tool)
{
	int	tmp_a_size;
	int	move_size;

	while (tool->a->size > 6)
	{
		tool->pivot_size = tool->a->size;
		move_size = tool->a->size / 2;
		tmp_a_size = tool->a->size - move_size;
		half_set(init_a, init_b, tool, move_size);
		free(tool->a);
		tool->a = NULL;
		posi_lstadd_back(&(tool->a), tmp_a_size);
	}
	tool->size += tool->a->size;
}

void	b_sort_merge(t_str **init_a, t_str **init_b, t_tool *tool)
{
	t_posi	*b_last;

	b_last = posi_lstlast(tool->b);
	rq_under6_sort(init_b, init_a, b_last->size, tool);
	while (b_last->size > 0)
	{
		move_stack(init_b, init_a, 'b', tool);
		b_last->size--;
		tool->size++;
	}
	posi_lastclear(&(tool->b));
}

void	b_half_set(t_str **init_a, t_str **init_b, t_tool *tool)
{
	t_posi	*b_last;

	b_last = posi_lstlast(tool->b);
	rq_under6_sort(init_b, init_a, b_last->size, tool);
	while (b_last->size > 6)
	{
		posi_lstadd_back(&(tool->a), b_last->size);
		while (b_last->size > 0)
		{
			move_stack(init_b, init_a, 'b', tool);
			b_last->size--;
		}
		posi_lastclear(&(tool->b));
	}
}

#include "../push_swap.h"
#include "../libft/libft.h"

void	merge(t_str **init_a, t_str **init_b, t_tool *tool)
{
	t_posi	*b_last;

	b_last = posi_lstlast(tool->b);
	if (b_last != NULL)
	{
		while (b_last->size > 0)
		{
			move_stack(init_b, init_a, 'b', tool);
			b_last->size--;
			tool->size++;
		}
	}
	posi_lastclear(&(tool->b));
	if (tool->a != NULL)
		posi_lastclear(&(tool->a));
}

int	half_move(t_str **init_a, t_str **init_b, t_tool *tool, int move_size)
{
	long	pivot;
	long	*sort;
	int		rotate_stack;

	rotate_stack = 0;
	pivot = get_pivot(*init_a, tool->pivot_size, &sort);
	while (move_size > 0)
	{
		while (pivot < (*init_a)->num)
		{
			r_stack(init_a, 'a', tool);
			rotate_stack++;
		}
		move_stack(init_a, init_b, 'a', tool);
		move_size--;
	}
	free(sort);
	return (rotate_stack);
}

void	half_set(t_str **init_a, t_str **init_b, t_tool *tool, int move_size)
{
	int		rotate_stack;
	long	pivot;
	t_str	*tmp;
	long	*sort;

	pivot = get_pivot(*init_a, tool->pivot_size, &sort);
	posi_lstadd_back(&(tool->b), move_size);
	tmp = *init_a;
	while (tmp->num <= pivot)
		tmp = tmp->next;
	rotate_stack = half_move(init_a, init_b, tool, move_size);
	if ((*init_a)->num == tmp->num)
		rotate_stack = 0;
	while (rotate_stack > 0)
	{
		rr_stack(init_a, 'a', tool);
		rotate_stack--;
	}
	free(sort);
}

void	q_under6_sort(t_str **init_a, t_str **init_b, int size, t_tool *tool)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*init_a)->num > (*init_a)->next->num)
			s_stack(init_a, 'a', tool);
	}
	else if (size == 3)
		m_three_sort(init_a, 'a', tool);
	else if (size < 7)
	{
		tool->name = 'a';
		m_move_until_a3(init_a, init_b, size, tool);
		m_three_sort(init_a, 'a', tool);
		tool->name = 'a';
		return_to_a(init_a, init_b, size, tool);
	}
}

void	rq_under6_sort(t_str **init_b, t_str **init_a, int size, t_tool *tool)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*init_b)->num < (*init_b)->next->num)
			s_stack(init_b, 'b', tool);
	}
	else if (size == 3)
		rq_three_sort(init_b, 'b', tool);
	else if (size < 7)
	{
		r_move_until_b3(init_b, init_a, size, tool);
		rq_three_sort(init_b, 'b', tool);
		tool->name = 'b';
		return_to_a(init_b, init_a, size, tool);
	}
}

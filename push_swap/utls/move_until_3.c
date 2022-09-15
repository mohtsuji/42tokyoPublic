#include "../push_swap.h"
#include "../libft/libft.h"

void	return_to_a(t_str **init_a, t_str **init_b, long times, t_tool *tool)
{
	char	r_name;

	if (tool->name == 'a')
		r_name = 'b';
	else
		r_name = 'a';
	while (times > 3)
	{
		move_stack(init_b, init_a, r_name, tool);
		times--;
	}
}

void	m_move_until_a3(t_str **a, t_str **b, long times, t_tool *tool)
{
	int		move_count;
	int		sort;
	long	*sorted;

	move_count = 0;
	sorted = get_sort(*a, times, &sort);
	times -= 3;
	sort = times;
	while (times > 0)
	{
		while ((*a)->num >= sorted[sort])
		{
			r_stack(a, tool->name, tool);
			move_count++;
		}
		move_stack(a, b, tool->name, tool);
		times--;
	}
	while (move_count > 0)
	{
		rr_stack(a, tool->name, tool);
		move_count--;
	}
	rq_under6_sort(b, a, sort, tool);
	free(sorted);
}

void	r_move_until_b3(t_str **b, t_str **a, long times, t_tool *tool)
{
	int		move_count;
	int		sort;
	long	*sorted;

	move_count = 0;
	sorted = get_sort(*b, times, &sort);
	times -= 3;
	sort = times;
	while (times > 0)
	{
		while ((*b)->num < sorted[3])
		{
			r_stack(b, 'b', tool);
			move_count++;
		}
		move_stack(b, a, 'b', tool);
		times--;
	}
	while (move_count > 0)
	{
		rr_stack(b, 'b', tool);
		move_count--;
	}
	q_under6_sort(a, b, sort, tool);
	free(sorted);
}

void	move_until_a3(t_str **init_a, t_str **init_b, long times, t_tool *tool)
{
	t_str	*current;
	int		min_posi;
	long	min;

	while (times > 3)
	{
		min_posi = 0;
		current = *init_a;
		min = get_min(*init_a, &min_posi, tool->a_size);
		while (current->num != min)
		{
			if (min_posi / 2 < 2)
				r_stack(init_a, tool->name, tool);
			else
				rr_stack(init_a, tool->name, tool);
			current = *init_a;
		}
		move_stack(init_a, init_b, tool->name, tool);
		times--;
	}
}

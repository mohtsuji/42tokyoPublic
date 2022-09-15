#include "../push_swap.h"
#include "../libft/libft.h"

void	through(t_ope **ope, int *is_next)
{
	if ((ft_strmatch((*ope)->ope, "sa\n") && ft_strmatch((*ope)->next->ope, "sb\n")) || \
	(ft_strmatch((*ope)->ope, "sb\n") && ft_strmatch((*ope)->next->ope, "sa\n")))
	{
		ft_putstr_fd("ss\n", STDOUT_FILENO);
		(*ope) = (*ope)->next;
	}
	else if ((ft_strmatch((*ope)->ope, "ra\n") && ft_strmatch((*ope)->next->ope, "rb\n")) || \
	(ft_strmatch((*ope)->ope, "rb\n") && ft_strmatch((*ope)->next->ope, "ra\n")))
	{
		ft_putstr_fd("rr\n", STDOUT_FILENO);
		(*ope) = (*ope)->next;
	}
	else if ((ft_strmatch((*ope)->ope, "rra\n") && ft_strmatch((*ope)->next->ope, "rrb\n")) || \
	(ft_strmatch((*ope)->ope, "rrb\n") && \
	ft_strmatch((*ope)->next->ope, "rra\n")))
	{
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
		*ope = (*ope)->next;
	}
	else if ((ft_strmatch((*ope)->ope, "pa\n") && ft_strmatch((*ope)->next->ope, "pb\n")) || \
	(ft_strmatch((*ope)->ope, "pb\n") && ft_strmatch((*ope)->next->ope, "pa\n")))
		*ope = (*ope)->next;
	else
		*is_next = 1;
}

void	put_operation(t_ope *ope)
{
	int	is_next;

	while (ope)
	{
		if (ope->next)
		{
			is_next = 0;
			through(&ope, &is_next);
			if (is_next == 1)
				ft_putstr_fd(ope->ope, STDOUT_FILENO);
		}
		else
			ft_putstr_fd(ope->ope, STDOUT_FILENO);
		ope = ope->next;
	}
}

#include "../push_swap.h"
#include "../libft/libft.h"

void	srsrrs(t_str **init, char name, t_tool *tool)
{
	s_stack(init, name, tool);
	r_stack(init, name, tool);
	s_stack(init, name, tool);
	rr_stack(init, name, tool);
	s_stack(init, name, tool);
}

void	rsrrs(t_str **init, char name, t_tool *tool)
{
	r_stack(init, name, tool);
	s_stack(init, name, tool);
	rr_stack(init, name, tool);
	s_stack(init, name, tool);
}

void	srsrr(t_str **init, char name, t_tool *tool)
{
	s_stack(init, name, tool);
	r_stack(init, name, tool);
	s_stack(init, name, tool);
	rr_stack(init, name, tool);
}

void	rq_three_sort(t_str **init, char name, t_tool *tool)
{
	long	inin;
	long	secn;
	long	thrn;

	inin = (*init)->num;
	secn = (*init)->next->num;
	thrn = (*init)->next->next->num;
	if (inin > secn && secn < thrn && inin < thrn)
		rsrrs(init, name, tool);
	else if (inin < secn && secn < thrn && inin < thrn)
		srsrrs(init, name, tool);
	else if (inin > secn && secn < thrn && inin > thrn)
	{
		r_stack(init, name, tool);
		s_stack(init, name, tool);
		rr_stack(init, name, tool);
	}
	else if (inin < secn && secn > thrn && inin < thrn)
		srsrr(init, name, tool);
	else if (inin < secn && secn > thrn && inin > thrn)
		s_stack(init, name, tool);
}

void	m_three_sort(t_str **init, char name, t_tool *tool)
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
		srsrrs(init, name, tool);
	else if (inin > secn && secn < thrn && inin > thrn)
		srsrr(init, name, tool);
	else if (inin < secn && secn > thrn && inin < thrn)
	{
		r_stack(init, name, tool);
		s_stack(init, name, tool);
		rr_stack(init, name, tool);
	}
	else if (inin < secn && secn > thrn && inin > thrn)
		rsrrs(init, name, tool);
}

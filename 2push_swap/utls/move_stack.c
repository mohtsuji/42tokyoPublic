#include "../push_swap.h"
#include "../libft/libft.h"

void	delete_f(t_str **init_f, t_str *top_f)
{
	if ((*init_f)->next != *init_f)
	{
		(*init_f)->prev->next = top_f;
		top_f->prev = (*init_f)->prev;
		free(*init_f);
		*init_f = top_f;
	}
	else
	{
		free(*init_f);
		*init_f = NULL;
	}
}

void	add_t(t_str **init_t, t_str *top_t)
{
	if (*init_t != NULL)
	{
		if ((*init_t)->next != *init_t)
		{
			(*init_t)->prev->next = top_t;
			top_t->prev = (*init_t)->prev;
		}
		top_t->next = *init_t;
		(*init_t)->prev = top_t;
		if ((*init_t)->next == *init_t)
		{
			(*init_t)->next = top_t;
			top_t->prev = (*init_t);
		}
	}
	else
	{
		top_t->next = top_t;
		top_t->prev = top_t;
	}
	*init_t = top_t;
}

void	move_stack(t_str **init_f, t_str **init_t, char name, t_tool *tool)
{
	t_str	*top_f;
	t_str	*top_t;

	if (*init_f == NULL)
		return ;
	top_t = str_lstnew((*init_f)->num);
	top_f = (*init_f)->next;
	delete_f(init_f, top_f);
	add_t(init_t, top_t);
	if (name == 'b')
		tool_lstadd_back(tool, "pa\n");
	else if (name == 'a')
		tool_lstadd_back(tool, "pb\n");
}

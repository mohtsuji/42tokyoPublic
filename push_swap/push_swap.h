#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_str
{
	long			num;
	struct s_str	*next;
	struct s_str	*prev;
}					t_str;

typedef struct s_ope
{
	char			*ope;
	struct s_ope	*next;
}					t_ope;

typedef struct s_posi
{
	int				ip;
	int				fp;
	int				size;
	struct s_posi	*next;
}					t_posi;

typedef struct s_tool
{
	int				a_size;
	int				b_size;
	char			name;
	t_ope			*ope;
	long			*sorted;
	int				size;
	t_posi			*a;
	t_posi			*b;
	int				pivot_size;
}					t_tool;

void	b_half_set(t_str **init_a, t_str **init_b, t_tool *tool);
void	b_sort_merge(t_str **init_a, t_str **init_b, t_tool *tool);
void	a_sort_merge(t_str **init_a, t_str **init_b, t_tool *tool);
void	a_half_set(t_str **init_a, t_str **init_b, t_tool *tool);
void	init_half_set(t_str **init_a, t_str **init_b, t_tool *tool);
long	get_pivot(t_str *init_a, int size, long **sort);
void	m_three_sort(t_str **init, char name, t_tool *tool);
void	posi_lstadd_back(t_posi **posi, int size);
t_posi	*posi_lstlast(t_posi *posi);
void	posi_lastclear(t_posi **posi);
void	merge(t_str **init_a, t_str **init_b, t_tool *tool);
void	half_set(t_str **init_a, t_str **init_b, t_tool *tool, int move_size);
void	q_under6_sort(t_str **init_a, t_str **init_b, int size, t_tool *tool);
void	rq_under6_sort(t_str **init_a, t_str **init_b, int size, t_tool *tool);
void	tool_lstadd_back(t_tool *tool, char *ope);
int		ft_strmatch(char *s1, char *s2);
void	put_operation(t_ope *ope);
void	ope_lstclear(t_ope **head);
long	*get_sort(t_str *init, int size, int *sort);
void	str_lstadd_back(t_str **lst, t_str *n);
void	str_lstclear(t_str **head);
t_str	*str_lstlast(t_str *lst);
t_str	*str_lstnew(long num);
void	*xmalloc(size_t size);
void	sort_main(int size, t_str **init_a, t_tool *tool);
void	two_sort(t_str **init_a, char name, t_tool *tool);
t_str	*str_getlast(t_str *init_a);
void	move_stack(t_str **init_f, t_str **init_t, char name, t_tool *tool);
void	test_put(t_str *init_a);
t_str	*str_strlast(t_str *init);
void	add_t(t_str **init_f, t_str *top_t);
void	delete_f(t_str **init_t, t_str *top_f);
void	s_stack(t_str **init, char name, t_tool *tool);
void	r_stack(t_str **init, char name, t_tool *tool);
void	rr_stack(t_str **init, char name, t_tool *tool);
void	three_sort(t_str **init, char name, t_tool *tool);
void	three_sort_r(t_str **init, char name, t_tool *tool);
void	rq_three_sort(t_str **init, char name, t_tool *tool);
long	get_min(t_str *init, int *min_posi, int size);
void	move_until_a3(t_str **init_a, t_str **init_b, long times, t_tool *tool);
void	r_move_until_b3(t_str **a, t_str **b, long times, t_tool *tool);
void	m_move_until_a3(t_str **a, t_str **b, long times, t_tool *tool);
void	return_to_a(t_str **init_a, t_str **init_b, long times, t_tool *tool);

#endif

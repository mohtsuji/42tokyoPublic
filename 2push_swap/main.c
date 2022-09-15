#include "push_swap.h"
#include "./libft/libft.h"

//__attribute__((destructor))
//	static void destructor(){
//		system ("leaks push_swap");
//	}

void	check_input(long num)
{
	if (num > 2147483647 || num < -2147483648)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
}

void	check_overlap(t_str *init_a)
{
	t_str	*target;
	t_str	*comp;

	target = init_a;
	while (1)
	{
		comp = target->next;
		while (comp != init_a)
		{
			if (target->num == comp->num)
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				exit(1);
			}
			comp = comp->next;
		}
		target = target->next;
		if (target == init_a)
			break ;
	}
}

void	get_a(t_str **init_a, char **argv)
{
	int		i;
	t_str	*new;
	t_str	*lst;

	*init_a = str_lstnew(ft_atoi(argv[1]));
	check_input((*init_a)->num);
	i = 2;
	while (argv[i])
	{
		new = str_lstnew(ft_atoi(argv[i]));
		check_input(new->num);
		str_lstadd_back(init_a, new);
		i++;
	}
	lst = str_lstlast(*init_a);
	lst->next = *init_a;
	(*init_a)->prev = lst;
}

int	main(int argc, char **argv)
{
	t_str	*init_a;
	int		sort;
	t_tool	tool;

	if (!argv[1])
		return (0);
	init_a = NULL;
	get_a(&init_a, argv);
	check_overlap(init_a);
	sort = 0;
	tool.sorted = get_sort(init_a, argc - 1, &sort);
	if (sort == 0)
	{
		str_lstclear(&init_a);
		free(tool.sorted);
		return (0);
	}
	tool.name = 'a';
	tool.ope = NULL;
	tool.b_size = 0;
	tool.a_size = 0;
	tool.size = argc - 1;
	sort_main(argc - 1, &init_a, &tool);
	str_lstclear(&init_a);
	return (0);
}

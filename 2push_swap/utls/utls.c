#include "../push_swap.h"
#include "../libft/libft.h"

long	get_min(t_str *init, int *min_posi, int size)
{
	long	min;
	t_str	*current;
	int		time;
	int		a_size;

	time = 1;
	min = init->num;
	current = init->next;
	a_size = size - 1;
	while (a_size > 0)
	{
		if (current->num < min)
		{
			min = current->num;
			*min_posi = time;
		}
		current = current->next;
		time++;
		a_size--;
	}
	return (min);
}

int	ft_strmatch(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
		i++;
	if (s1[i] == 0 && s2[i] == 0)
		return (1);
	return (0);
}

void	swap(long **sorted, int i)
{
	long	tmp;

	while (i > 0)
	{
		if ((*sorted)[i] < (*sorted)[i - 1])
		{
			tmp = (*sorted)[i];
			(*sorted)[i] = (*sorted)[i - 1];
			(*sorted)[i - 1] = tmp;
		}
		i--;
	}
}

long	*get_sort(t_str *init, int size, int *sort)
{
	t_str	*current;
	long	*sorted;
	int		i;

	sorted = (long *)xmalloc(sizeof(long) * (size + 1));
	current = init;
	i = 0;
	while (size > 0)
	{
		sorted[i] = current->num;
		current = current->next;
		if (i > 0 && sorted[i] < sorted[i - 1])
		{
			swap(&sorted, i);
			*sort = 1;
		}
		i++;
		size--;
	}
	sorted[i] = '\0';
	return (sorted);
}

long	get_pivot(t_str *init_a, int size, long **sort)
{
	int		tako;

	*sort = get_sort(init_a, size, &tako);
	return ((*sort)[size / 2 - 1]);
}

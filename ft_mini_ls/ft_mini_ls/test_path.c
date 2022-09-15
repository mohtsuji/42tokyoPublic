/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:00:43 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/12/04 01:17:26 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void	ft_put(char *str)
{
	while (*str != 0)
	{
		write(1, str, sizeof(char));
		str++;
	}
	write(1, "\n", 1);
}

void	reverse(t_list **list, int cnt)
{
	int		n;
	int		i;
	t_list	work;

	n = 0;
	i = 0;
	while (n < cnt - 1)
	{
		while (i < cnt - 1)
		{
			if ((*list)[i].time > (*list)[i + 1].time)
			{
				work = (*list)[i];
				(*list)[i] = (*list)[i + 1];
				(*list)[i + 1] = work;
				//printf("[i]%ld:[i + 1]%ld\n", (*list)[i].time, (*list)[i + 1].time);
			}
			i++;
		}
		i = 0;
		n++;
	}
	i = 0;
/*	while (i < cnt)
	{
		ft_put((*list)->name);
		(*list)++;
		i++;
	}*/
}

void	stock(t_list **list, int cnt)
{
	DIR				*dir;
	int				i;
	struct stat		info;
	struct dirent	*dent;
	char			*tmp;

	i = 0;
	dir = opendir("./");
	while ((dent = readdir(dir)) != NULL)
	{
		tmp = dent->d_name;
		if (*tmp != '.')
		{
			(*list)[i].name = tmp;
			stat(dent->d_name, &info);
			(*list)[i].time = info.st_mtime;
			i++;
		}
	}
	reverse(list, cnt);
	//printf("%s:%ld\n", (*list)[i].name, (*list)[i].time);
	i = 0;
	while (i < cnt)
	{
		ft_put((*list)->name);
		//printf("%s:%ld\n", (*list)[i].name, (*list)[i].time);
		(*list)++;
		i++;
	}
	closedir(dir);
}

int		main(int argc, char *argv[])
{
	DIR				*dir;
	struct dirent	*dent;
	char			*tmp;
	int				cnt;
	t_list			*list;

	cnt = 0;
	tmp = NULL;
	dir = opendir("./");
	if (argc != 1 || dir == NULL)
	{
		perror("./");
		return (1);
	}
	while ((dent = readdir(dir)) != NULL)
	{
		tmp = dent->d_name;
		if (*tmp != '.')
			cnt++;
	}
	if (!(list = (t_list *)malloc(sizeof(t_list) * cnt)))
		return (0);
	closedir(dir);
	stock(&list, cnt);
	free(list);
	return (0);
}

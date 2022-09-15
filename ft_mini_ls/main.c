/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:42:39 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/12/03 00:08:17 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <unistd.h>




int main()
{
	DIR				*dir;
	char			*path;
	struct dirent	*dent;
	char			*tmp;
	struct stat		*info;
	char			**str;

	tmp = NULL;
	dir = opendir("./");
	if (dir == NULL)
	{
		perror("./");
		return (1);
	}
	while ((dent = readdir(dir)) != NULL)
	{
		stat(d_fi, info);
		tmp = dent->d_name;
		if (*tmp != '.')
		{
			while (*tmp != 0)
			{
				write(1, tmp, sizeof(char));
				tmp++;
			}
		write(1, "\n", 1);
		}
	}
	closedir(dir);
	return (0);
}

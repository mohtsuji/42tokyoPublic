/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:11:01 by mohtsuji          #+#    #+#             */
/*   Updated: 2022/09/15 15:54:53 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		r;
	char	*get_line;

	(void)argc;
	(void)argv;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	r = 1;
//	fd = 0;
	while (r > 0)
	{
		r = get_next_line(fd, &get_line);
		printf("%d:", r);
		if (r == -1)
		{
			break ;
		}
		printf("%s\n", get_line);
		free(get_line);
	}
	close(fd);
	//while(1){}
	//printf("owari\n");
	return (0);
}

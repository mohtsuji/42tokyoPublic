/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:36:59 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/11/25 15:32:13 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*仕様メモ
・空白行はどの位置においても許容しない（ファイル全体をmapと見做す）
・Pが複数あった場合，一番最後のPのみを採用してplayerは一人にする
・sizeはWindowのサイズに合わせるので，かなり小さいmapしか受け付けられない
*/

#include "so_long.h"

void	get_map_size(t_info *info, char **line)
{
	int	i;

	i = 0;
	info->width = 0;
	info->height = 0;
	while (line[info->height])
		info->height++;
	while (line[0][info->width])
		info->width++;
	info->height -= 1;
	info->w_width = info->width * 64;
	info->w_height = info->height * 64;
	while (i < info->height)
	{
		if (info->width != (int)ft_strlen(line[i]))
		{
			if (line[i][0] == '\0')
				put_error("Error\nblank line");
			put_error("Error\nthis map is not rectangular");
		}
		i++;
	}
}

void	read_map(t_info *info, char ***line, int fd)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	j = 0;
	while (i == 1)
	{
		i = get_next_line(fd, &tmp);
		(*line)[j] = safe_dup(tmp);
		j++;
		free(tmp);
	}
	(*line)[j] = NULL;
	if (i == -1)
		put_error("Error\ninvalid file");
	get_map_size(info, *line);
}

int	line_malloc(char *pass, char ***line)
{
	char	*tmp;
	int		i;
	int		fd;
	int		count;

	i = 1;
	fd = 0;
	count = 0;
	fd = open(pass, O_RDONLY);
	if (fd == -1)
		put_error("Error\ninvalid file");
	tmp = NULL;
	while (i == 1)
	{
		i = get_next_line(fd, &tmp);
		count++;
		free(tmp);
	}
	(*line) = (char **)xmalloc(sizeof(char *) * (count + 1));
	close(fd);
	return (count);
}

void	check_map_name(char *name)
{
	int	len;
	int	i;

	len = ft_strlen(name);
	if (len < 5)
		put_error("Error\ninvalid map name1");
	i = len - 4;
	if (ft_strncmp(name + i, ".ber", 4) != 0)
		put_error("Error\ninvalid map name2");
	return ;
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		fd;
	char	**line;
	int		count;

	if (argc != 2)
		put_error("Error\nargc != 2");
	check_map_name(argv[1]);
	//構造体を初期化
	initialize(&info);
	//mlxの通信を開始
	info.mlx = mlx_init();
	//mapの読み込み
	count = line_malloc(argv[1], &line);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		put_error("Error\ninvalid map");
	read_map(&info, &line, fd);
	close(fd);
	//mapをコピーしてマップのエラーチェック
	copy_map(&info, &line);
	//textureを読み込む
	get_texture(&info);
	//map error check
	check_map_error(&info);
	free_line(&line, count);
	buf_malloc(&info);
	//メインの動作に入る，windowを描画
	loop_mlx(&info);
	return (0);
}

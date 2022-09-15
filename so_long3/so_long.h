/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:38:48 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/30 17:56:57 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifdef __linux__
#  include <X11/Xlib.h>
#  include <sys/ipc.h>
#  include <sys/shm.h>
#  include <X11/extensions/XShm.h>
#  include "./minilibx-linux/mlx.h"
#  define K_A 97
#  define K_S 115
#  define K_D 100
#  define K_W 119
#  define K_ESC 65307

# else
#  include "./minilibx_mms_20200219/mlx.h"
#  define K_A 0
#  define K_S 1
#  define K_D 2
#  define K_W 13
#  define K_ESC 53
# endif

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define BUFFER_SIZE 1000
# define HEIGHT 500
# define WIDTH 500
# define TEXHEIGHT 64
# define TEXWIDTH 64

typedef struct s_img
{
	void			*ptr;
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;

typedef struct s_info
{
	void			*mlx;
	unsigned int	**buf;
	int				**texture;
	char			**worldmap;
	int				posx;
	int				posy;
	void			*win;
	t_img			img;
	long			width;
	long			height;
	long			w_width;
	long			w_height;
	int				c_num;
	int				move_num;
	int				E;
	int				P;
	int				C;
}			t_info;

void	buf_malloc(t_info *info);
void	*xmalloc(size_t size);
void	safe_free(char **ptr);
int		get_next_line(int fd, char **line);
void	put_error(char *str);
char	*safe_dup(const char *str);
void	check_map_error(t_info *info);
void	draw(t_info *info);
void	get_texture(t_info *info);
void	initialize(t_info *info);
void	loop_mlx(t_info *info);
void	put_pixcel_color(t_info *info);
void	copy_map(t_info *info, char ***line);
void	free_line(char ***line, int count);
int		char_atoi(const char c);
int		close_game(t_info *info);
void	move_back(t_info *info);
void	move_front(t_info *info);
void	move_left(t_info *info);
void	move_right(t_info *info);

#endif

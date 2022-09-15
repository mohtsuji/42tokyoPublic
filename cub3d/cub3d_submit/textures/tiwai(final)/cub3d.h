/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:11:49 by tiwai             #+#    #+#             */
/*   Updated: 2020/12/01 11:03:11 by tiwai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# ifdef __linux__
#  include <X11/Xlib.h>
#  include <sys/ipc.h>
#  include <sys/shm.h>
#  include <X11/extensions/XShm.h>
#  include "./minilibx-linux/mlx.h"
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_ESC 65307
# else
#  include "./minilibx_mms/mlx.h"
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_ESC 53
# endif
# define BUFFER_SIZE 1000
# define NOTBLACK 0x00FFFFFF
# define RESOL 1
# define NORTH 2
# define SOUTH 4
# define WEST 8
# define EAST 16
# define SPRITE 32
# define FLOOR 64
# define CEIL 128
# define ALL 255

typedef struct		s_cmap
{
	int				check;
	char			**c_map;
}					t_cmap;

typedef struct		s_player
{
	double			px;
	double			py;
	double			dx;
	double			dy;
	double			plx;
	double			ply;
	int				fwd;
	int				back;
	int				right;
	int				left;
	int				rot_right;
	int				rot_left;
}					t_player;

typedef	struct		s_ray
{
	double			cx;
	double			rdx;
	double			rdy;
	double			sdx;
	double			sdy;
	double			ddx;
	double			ddy;
	double			pdist;
	double			wallx;
	double			step;
	double			tex_pos;
	int				x;
	int				y;
	int				mx;
	int				my;
	int				stx;
	int				sty;
	int				hit;
	int				side;
	int				lh;
	int				dstart;
	int				dend;
	int				tex_num;
	int				tex_x;
	int				tex_y;
}					t_ray;

typedef struct		s_color
{
	char			*dst;
	char			tmp;
	unsigned int	color;
	unsigned char	*src;
	int				bp;
	int				sl;
	int				end;
}					t_color;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*window_ptr;
	void			*img;
	char			*d_img;
	int				bit;
	int				sl;
	int				end;
	int				w;
	int				h;
}					t_mlx;

typedef struct		s_drawspr
{
	double			sprite_x;
	double			sprite_y;
	double			inv;
	double			trsx;
	double			trsy;
	int				stripe;
	int				horizon;
	int				ssx;
	int				sh;
	int				dsx;
	int				dsy;
	int				dey;
	int				sw;
	int				dex;
	char			*sp;
	char			*src;
	int				bp;
	int				sl;
	int				end;
	int				tex;
	int				d;
	int				tey;
	int				color;
}					t_drawspr;

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				i;
	int				bit;
	int				sl;
	int				end;
}					t_sprite;

typedef struct		s_info
{
	int				flag;
	long			rw;
	long			rh;
	int				check;
	char			*texture[5];
	unsigned int	floor_color;
	unsigned int	ceilling_color;
	char			**map;
	char			*map_str;
	char			*map_strdup;
}					t_info;

typedef struct		s_params
{
	t_mlx			*mlx;
	t_player		*player;
	t_ray			*ray;
	t_info			*info;
	t_list			*lst;
	double			*zbuffer;
	void			*tex[5];
	int				tw[5];
	int				th[5];
}					t_params;

void				init_mlxstr(t_mlx *m);
void				init_prmstr(t_params *p);
void				init_plyrstr(t_player *p);
int					get_next_line(int fd, char **line);
int					raycast(t_params *param);
void				sprite(t_params *param);
int					error_str(const char *str);
int					screenshot(t_params *param);
void				error_char(char *str);
void				check_map(t_params *param);
void				check_filename(char *str);
void				free_multi(char ***arr);
int					ft_strcmp(char *s, char *f);
int					get_color(char **color);
int					key_release_event(int key, t_params *param);
int					key_press_event(int key, t_params *param);
int					move_player(t_params *param);
void				draw_floor(t_params *param);
void				draw_texture(t_params *param);
void				draw_ceil(t_params *param);
void				tex_draw_prep(t_params *param);
void				draw_sprite(t_params *param, t_drawspr *draw);
void				sprite(t_params *param);
void				init_player(t_params *param);
void				init_spr(t_params *param, int x, int y);
void				init_tex(t_params *param);
void				init_mlx(t_params *param, int screenshot);
void				init_param(t_params *param);
void				init_info(char *str, t_info *inf);
void				make_map(char *map, t_info *inf);
int					all_flag(int flag);
void				set_resol(t_info *inf, char ***ext);
void				set_texture(t_info *inf, char ***ext, int n, int flag);
void				set_color(t_info *inf, int flag, char **line);
long				new_atoi(const char *str);
int					check_resol(t_params *param);
int					count_splits(char **s);
void				syntax_str(const char *s);
long				new_atoi(const char *s);
void				check_color(char **color);
void				comm_to_space(char **s);
char				*skip_key(char *str);
int					close_game(t_params *param);
int					comp_dist(t_list *current, t_list *next, t_params *p);
void				count_newline(char *s);

#endif

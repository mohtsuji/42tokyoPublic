#ifndef MY_TERM_H
# define MY_TERM_H

# include "../includes/minishell.h"
# include "../includes/type.h"
# include <termcap.h>
# include <termios.h>
# include <term.h>
# include <curses.h>

# define READBUF_SIZE 4096
# define DEL 127
# define ETX 3
# define EOT 4
# define LEFT "\e[D"
# define RIGHT "\e[C"
# define UP "\e[A"
# define DOWN "\e[B"
# define TAB_SPACE "    "
# define READ_STOP 0 
# define READ_CONT 1
# define CTLD 2

char		*start_reading(char *hist_path);
char		*return_null_exit(void);
int			ft_putchar(int c);
t_termnl	*init_struct_term(struct termios *origin, char *hist_path);
t_termnl	*update_struct_term(t_termnl *term, char *newprompt);
void		free_term(t_termnl **term);
int			move_right(t_termnl *term);
int			move_left(t_termnl *term);
int			delete_char(t_termnl *term);
int			edit_line(t_termnl *term, char *buf);
int			insert_input(t_termnl *term, char *buf);
int			up_history(t_termnl *term);
int			down_history(t_termnl *term);
void		open_history(t_termnl *term, char *hist_path);
void		add_history(char *line, struct termios *origin, char *hist_path);
void		exit_with_msg_terminal(struct termios *origin, char *str);
int			cursor_to_index(t_termnl *term);
int			decrease_cursor(t_termnl *term);
void		adjust_col(int wanted_col, int now_col);
void		adjust_line(int wanted_line, int now_line);
void		reset_screen(t_termnl *term);
#endif

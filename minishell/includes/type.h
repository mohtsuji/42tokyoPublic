#ifndef TYPE_H
# define TYPE_H

# include <stdbool.h>

extern int	g_status;

typedef struct s_cd
{
	int		start;
	char	*cdpath;
	char	*target_path;
	_Bool	empty;
	_Bool	flag_lstat;
}			t_cd;

typedef struct s_shell
{
	char			*oldpwd;
	char			*pwd;
	_Bool			on_pwd;
	char			**env_arr;
	struct s_env	*envlist;
	int				stdout_origin;
	int				stdin_origin;
	int				stderror_origin;
	int				usedfd[300];
	_Bool			pipe;
}				t_shell;

typedef struct s_termnl
{
	char			*prev_line;
	char			*prompt;
	int				endcol;
	int				current_col;
	int				current_line;
	int				col;
	int				margin_count;
	int				cursor_start;
	int				hist_size;
	int				current_hist;
	char			*line;
	char			**history;
	struct termios	*original;
}				t_termnl;

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

typedef struct s_cmd
{
	char			**arg;
	char			**rd;
	struct s_dlist	*arglist;
	struct s_dlist	*rdlist;
	int				pipe_fd[2];
}				t_cmd;

typedef struct s_ast
{
	int				type;
	char			*data;
	struct s_cmd	*command;
	struct s_ast	*left;
	struct s_ast	*right;
}				t_ast;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				equal;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct s_pwd
{
	char			*pwd;
	char			*oldpwd;
}				t_pwd;

typedef struct s_dlist
{
	void			*data;
	struct s_dlist	*prev;	
	struct s_dlist	*next;	
}				t_dlist;

typedef struct s_expand
{
	int				*escape_table;
	char			*quote_table;
	char			*str;
	struct s_env	*env;
}				t_expand;

#endif

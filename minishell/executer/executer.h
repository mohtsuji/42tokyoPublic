#ifndef EXECUTER_H
# define EXECUTER_H

# define FD_MAX 256
# define FOUND 0
# define NOTFOUND_FILE 1
# define NOTFOUND_DIR 2
# define NOTFOUND_CMD 3
# define NOTFOUND_NOTDIR 4
# define NOTFOUND_PERM 5 
# include "../includes/minishell.h"
# include "../includes/type.h"

int		executer(t_ast *node, t_shell *shell);
int		search_cmd(char *file, t_shell *shell, char **ans);
int		slash_case(char *file, char **ans);
int		path_set_case(char *file, t_shell *shell, char **ans);
_Bool	set_redirection(char **rd_list, t_shell *shell);
void	undo_redirection(t_shell *shell);
_Bool	left_rd(char *rd_sign, char *file, t_shell *shell);
_Bool	right_rd(char *rd_sign, char *file, t_shell *shell);
int		get_num(char *rd_sign);
int		save_and_dup(int to_fd);
void	skip_digit(char **str);
void	check_status(int status);
int		exec_simple_cmd(t_ast *node, t_shell *shell);
int		exec_pipe(t_ast *node, t_shell *shell);
void	run_pipe_cmd(t_cmd *cmd, t_shell *shell);
char	**make_path_table(t_cmd **pipe_table, t_shell *shell);
t_cmd	**make_pipe_table(t_ast *node);
void	free_pipe_table(t_cmd **table);
_Bool	is_builtin(char *cmd);
int		rd_and_run_builtin(t_cmd *cmd, t_shell *shell, int cmdexist);
int		run_builtin(t_cmd *cmd, t_shell *shell);
int		rd_forground(t_ast *node, t_shell *shell);
void	output_errmsg(int res, t_shell *shell, char *file);
void	put_msg_and_exit(int res, t_shell *shell, char *file, char *cmdpath);
int		check_permission(char *file, t_shell *shell, char *file_name);
#endif

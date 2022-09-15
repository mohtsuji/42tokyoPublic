#ifndef BUILDIN_H
# define BUILDIN_H

# include "../includes/minishell.h"
# include "../includes/type.h"

char	*absolute_pwd(char *path, int *slush_count);
_Bool	init_cdpath(t_cd *cd, t_shell *shell);
int		top_slush(char *path);
int		top_slush(char *path);
_Bool	check_cdpath(t_cmd *cmd, t_shell *shell, char **position);
void	replace_value(char *str, t_env **env, char *value_tmp, int flag);
void	join_path(char **new, char **tmp, char ***path, int i);
int		end_process(t_cmd *cmd, char **position, t_shell *shell, int fail);
int		check_dir_exist(char *path);
void	set_pwd_or_oldpwd(t_env *new, t_shell *shell, char *key_tmp);
char	*replace(int i, char ***path, int slush_count, _Bool *flag_lstat);
void	delete_one_env(t_env **del);
void	put_export(t_shell *shell);
void	rewrite_pwd(t_shell *shell);
void	rewrite_oldpwd(t_shell *shell);
int		count_slush(char *tmp);
void	set_pwd(t_shell *shell, char **position);
int		our_cd(t_cmd *cmd, t_shell *shell);
int		our_pwd(t_cmd *cmd, t_shell *shell);
int		our_env(t_cmd *cmd, t_shell *shell);
int		our_unset(t_cmd *cmd, t_shell *shell);
int		our_export(t_cmd *cmd, t_shell *shell);
int		our_echo(t_cmd *cmd);
int		our_exit(t_cmd *cmd, int *status);
void	numeric_argument_required(int *status, char *str);
void	env_lstclear(t_env **head);
int		env_lstsize(t_env *lst);
void	env_lstadd_back(t_env **lst, t_env *n);
t_env	*env_lstlast(t_env *lst);
t_env	*env_lstnew(char *str, int flag);
t_env	*env_oneclear(t_env *target);
void	put_env(t_env *env, int fd);
void	ft_putstr_fd(char *s, int fd);
void	exec_export(t_env **env, char *str, int fd, int *status);
size_t	size_vlen(char *str);
size_t	size_klen(char *str);
int		ft_strmatch(char *s1, char *s2);
void	get_key_value(char *str, char **key, char **value, int flag);
void	env_copy(t_env **env, char *envv[]);
void	env_init_change(t_env **env);
char	**env_trunc(t_env *env);
int		ft_strstr(char *big, char *little);
void	pwd_join(char **position, t_shell *shell, t_cmd *cmd);
char	*no_current(char *path, t_shell *shell);
char	*set_position(char **now, int i);
void	count_current(char **now, int *current, int *back);
int		count_position(char **now);
void	relative(char **path, char **pwd);
void	back(char **tmp);
char	*absolute_pwd(char *path, int *slush_count);

#endif

#ifndef UTLS_H
# define UTLS_H

# include "../includes/minishell.h"
# include "../includes/type.h"
# define BUFFER_SIZE 1000
# define PERMISSTION ": Permission denied\n"
# define NOSUCHFILE ": No such file or directory\n"
# define CMDNOTFOUND ": command not found\n"
# define ITISDIR ": is a directory\n"
# define NOTDIR ": Not a directory\n"

void	safe_trijoin(char **ans, char *s1, char *s2, char *s3);
void	safe_strjoin(char **ans, char *s1, char *s2);
void	free_dup(char **ans, char *s);
char	*ft_trijoin(char *s1, char *s2, char *s3);
void	*xmalloc(size_t size);
void	free_multi(char ***arr);
int		get_next_line(int fd, char **line);
int		ft_strmatch(char *s1, char *s2);
t_env	*ft_getenv(char *str, t_env *env);
void	safe_free(char **ptr);
int		count_escape(char *head, char *now);
int		check_newline(char **store);
char	*ft_charjoin(char const *s1, char c);
_Bool	is_env_variable(char c);
void	errmsg_with_status(char *file, t_shell *shell, char *msg, int status);
void	no_such_file_or_dir(char *name, t_shell *shell);
void	command_not_found(char *cmd, t_shell *shell);
void	permission_denied(char *file, t_shell *shell);
void	it_is_dir(char *file, t_shell *shell);
void	bad_fd(char *fd, t_shell *shell);
void	exit_with_msg(char *str);
_Bool	ft_atol(const char *str, int *sign, unsigned long long *ans);
void	ignore(void);
char	*safe_dup(const char *str);
char	*safe_join(const char *s1, const char *s2);
char	*safe_join_no_exit(const char *s1, const char *s2);
char	**safe_split(const char *str, const char c);
char	*safe_substr(const char *s, unsigned int start, size_t len);
void	*safe_calloc(size_t count, size_t size);
t_dlist	*create_elm(void *d);
t_dlist	*dlstlast(t_dlist *lst);
t_dlist	*search_elm(t_dlist *head, void *d);
void	insert_elm(t_dlist *head, void *pre, void *d);
void	dlstadd_back(t_dlist **lst, t_dlist *n);
void	dlstdelone(t_dlist *lst);
void	dlstclear(t_dlist **lst);
t_dlist	*create_elm_strdup(char *d);
int		dlist_size(t_dlist *lst);
void	addback_elm_with_data(t_dlist **head, char *s1, char *s2);
char	**list_to_array(t_dlist *lst);
char	**make_path_list(t_env *env, char *file, char *str);
void	sort_if_needed(t_env **head, t_env *list);
void	list_mergesort(t_env **head);
#endif

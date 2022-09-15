#ifndef EXPANSION_H
# define EXPANSION_H

# include "../includes/minishell.h"
# include "../includes/type.h"

void	arg_expansion_from_node(t_ast *node, t_env *env);
void	expand_the_argnode(t_cmd *cmd, t_env *env);
void	arg_expand_str(t_dlist **head, t_expand *exp);
void	split_if_needed(t_dlist **head, t_expand *exp, char **ans, int i);

_Bool	rd_expansion_from_node(t_ast *node, t_env *env);
_Bool	expand_the_rdnode(t_cmd *cmd, t_env *env);
_Bool	rd_expand_str(t_dlist **head, t_expand *exp);
_Bool	rd_expand_doller(t_expand *exp, char **ans, int *i);

void	copy_one_letter(char **ans, t_expand *exp, int i);
void	substitute_doller(char **ans, t_expand *exp, int i);
void	init_expand(t_expand *exp, char *s, t_env *env);
void	delete_expand(t_expand *exp);
int		*make_dp_table(char *str);
void	make_quote_table(char *str, t_expand *exp);
char	*init_quote_table(int size);
char	*expand_env(t_expand *exp, char *str);
_Bool	escaped(int escape_count);
_Bool	skip_some_token(t_expand *exp, char **ans, int *i);

_Bool	is_special(t_expand *exp, int i);

_Bool	skip_back_slash(t_expand *exp, int *i);
void	deal_with_single(t_expand *exp, char **ans, int *i);
#endif

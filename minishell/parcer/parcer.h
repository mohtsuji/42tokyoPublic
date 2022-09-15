#ifndef PARCER_H
# define PARCER_H

# include "../includes/minishell.h"
# include "../includes/type.h"

_Bool				parcer(t_token *token_list, t_ast **ast);
t_ast				*make_node(char *str, int typ);
void				node_add(t_ast *root, t_ast *l, t_ast *r);
void				delete_node(t_ast **node);
void				ast_clear(t_ast **root);
t_ast				*cmmd_line(t_token **lst);
t_ast				*list(t_token **lst);
t_ast				*list_semicolon(t_token **lst);
t_ast				*pipeline(t_token **lst);
t_ast				*pipe_inbetween(t_token **lst);
t_ast				*command(t_token **lst);
t_ast				*rd_command(t_token **lst);
t_ast				*word_command(t_token **lst);
t_ast				*simple_word_cmmd(t_token **lst);
t_ast				*simple_rd(t_token **lst);
t_ast				*simple_word(t_token **lst);
void				put_error(t_token **lst);
void				make_cmd_table(t_ast *node, int tokensize);
void				cmmd_clear(t_cmd *command);

#endif

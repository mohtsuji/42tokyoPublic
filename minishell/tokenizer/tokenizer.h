#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "../includes/minishell.h"
# include "../includes/type.h"

# define GREATER 0
# define N_GREATER 1
# define DOUBLEGRT 2
# define N_DOUBLEGRT 3
# define SMALLER 4
# define N_SMALLER 5
# define SEMICOLON 6
# define PIPE 7
# define GENERAL 8
# define AMPERSAND 9
# define ESCAPE 10
# define NEWLINE 11
# define DQUOTE 12
# define SQUOTE 13
# define SPACE 14
# define TAB 15
# define CMD 16

void		start_tokenizer(char *line, t_token **list, size_t len);
int			check_type(char c, char d);
void		double_greater(t_token **now, size_t len, int *i);
void		double_smaller(t_token **now, size_t len, int *i);
void		set_generaltoken(t_token **now, size_t len, char *line, int *i);
void		greatersmaller_n(t_token **now, int *i, char *line);
void		num_greater_smaller(t_token **now, char *line, int start, int end);
void		num_double_greater(t_token **now, char *line, int start, int end);
t_token		*token_lstnew(size_t len);
t_token		*token_lstlast(t_token *lst);
void		token_lstadd_back(t_token **lst, t_token *newlst);
int			token_lstsize(t_token *lst);
void		token_lstclear(t_token **head);
_Bool		check_quote_token(t_token *list);
_Bool		token_empty(t_token **token_list);
#endif

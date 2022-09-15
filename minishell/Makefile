# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/21 13:24:38 by tiwai             #+#    #+#              #
#    Updated: 2021/05/19 12:00:15 by tiwai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := minishell
DEBUG := debug
DEBUG2 := debug2
LIBDIR := ./libft/
LIBFT := $(LIBDIR)libft.a
TOKEN := ./tokenizer/tokenizer.c \
		./tokenizer/tokenizer_general.c \
		./tokenizer/tokenizer_redirect.c\
		 ./tokenizer/tokenlst_utls.c \
		 ./tokenizer/check_quote_token.c
PARCER := ./parcer/parcer.c \
		./parcer/parcer_utls.c \
		./parcer/parcer_simples.c \
		./parcer/parcer_pipe.c \
		./parcer/parcer_list.c \
		./parcer/parcer_commands.c \
		./parcer/make_cmd_table.c \
		./parcer/ast_utls.c
UTLS := ./utls/count_escape.c \
		./utls/error_msg.c \
		./utls/exit_with_msg.c \
		./utls/free_dup.c \
		./utls/free_multi.c \
		./utls/ft_atol.c \
		./utls/ft_charjoin.c \
		./utls/ft_getenv.c \
		./utls/ft_strmatch.c \
		./utls/ft_strstr.c \
		./utls/ft_trijoin.c \
		./utls/get_next_line.c \
		./utls/ignore.c \
		./utls/is_env_variable.c \
		./utls/safe_free.c \
		./utls/xmalloc.c \
		./utls/safe_str.c \
		./utls/dlist.c \
		./utls/dlist_create_add.c \
		./utls/make_path_list.c \
		./utls/merge_sort.c
BUILTINS := ./builtins/unset.c \
			./builtins/pwd.c \
			./builtins/put_export.c \
			./builtins/export.c \
			./builtins/exit.c \
			./builtins/env.c \
			./builtins/env_utls.c \
			./builtins/env_trunc.c \
			./builtins/env_libft.c \
			./builtins/env_key_value.c \
			./builtins/env_copy.c \
			./builtins/echo.c \
			./builtins/cd.c \
			./builtins/cd_utls.c \
			./builtins/export_utls.c \
			./builtins/cd_utls2.c \
			./builtins/cdpath_utls.c \
			./builtins/cd_path.c
SIGNAL := ./signal/signal.c \
		./signal/handler_main.c
TERMINAL := ./terminal/cursor_history.c \
			./terminal/cursor_right_left.c \
			./terminal/delete.c \
			./terminal/history.c \
			./terminal/init_terminal.c \
			./terminal/edit_line.c \
			./terminal/edit_line_insert.c \
			./terminal/read_line.c \
			./terminal/terminal_utls.c \
			./terminal/cursor_utls.c
EXPANSION := ./expansion/arg_expansion.c \
			./expansion/arg_expand_str.c \
			./expansion/arg_split_if_needed.c \
			./expansion/init_delete_expand.c \
			./expansion/rd_expansion.c \
			./expansion/rd_expand_str.c \
			./expansion/expand_utls.c \
			./expansion/expansion_tables.c \
			./expansion/expand_utls_spchar.c \
			./expansion/rd_expand_utls.c 
EXECUTER := ./executer/builtins_exec.c \
			./executer/check_status.c \
			./executer/executer.c \
			./executer/pipe_exec_utls.c \
			./executer/pipe_exec.c \
			./executer/pipe_table.c \
			./executer/redirection_left.c \
			./executer/redirection_right.c \
			./executer/redirection_utls.c \
			./executer/redirection.c \
			./executer/search_cmd.c \
			./executer/search_path_set_case.c \
			./executer/search_utls.c \
			./executer/simple_cmd_exec.c
SRCS := main.c $(TOKEN) $(PARCER) $(UTLS) $(SIGNAL) $(TERMINAL) $(EXPANSION) $(EXECUTER) $(BUILTINS)
OBJS := $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(OBJS) -ltermcap -L $(LIBDIR) -lft -I ./includes -o $@

$(DEBUG):$(OBJS) $(LIBFT)
	clang -g -fsanitize=address $(OBJS) -ltermcap -L $(LIBDIR) -lft -I ./includes -o $@

$(DEBUG2):$(SRCS) $(LIBFT)
	clang -g $(SRCS) -ltermcap -L $(LIBDIR) -lft -I ./includes -o $@

$(LIBFT):
	make -C $(LIBDIR)

bonus: all

clean:
	$(RM) $(OBJS) leakmain.o
	make clean -C $(LIBDIR)

fclean:clean
	$(RM) $(NAME) $(DEBUG) $(DEBUG2) $(NAME_LEAKS)
	make fclean -C $(LIBDIR)

re:fclean all

.PHONY: all clean fclean bonus

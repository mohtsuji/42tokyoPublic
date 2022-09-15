CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := push_swap
LIBDIR := ./libft/
LIBFT := $(LIBDIR)libft.a

UTLS := ./utls/str_utls.c \
			./utls/xmalloc.c \
			./utls/test_put.c \
			./utls/action.c \
			./utls/sort_utls.c \
			./utls/utls.c \
			./utls/ope_utls.c \
			./utls/posi.c \
			./utls/over6_sort.c \
			./utls/over_utls.c \
			./utls/move_until_3.c \
			./utls/put_operation.c \
			./utls/move_stack.c

SRCS := main.c \
		sort.c \
		$(UTLS)

OBJS := $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBDIR) -lft -I ./includes -o $@

$(LIBFT):
	make -C $(LIBDIR)

bonus: all

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBDIR)

fclean:clean
	$(RM) $(NAME) $(NAME_LEAKS)
	make fclean -C $(LIBDIR)

re:fclean all

.PHONY: all clean fclean bonus

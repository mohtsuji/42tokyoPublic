# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 13:22:07 by mohtsuji          #+#    #+#              #
#    Updated: 2021/09/30 12:12:06 by mohtsuji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTLS = utls/get_next_line.c \
		utls/put_error.c \
		utls/safe_free.c \
		utls/xmalloc.c \
		utls/free.c \
		utls/char_atoi.c \
		utls/safe_str.c

SRCS := main.c \
		ready_map.c \
		draw.c \
		loop_mlx.c \
		put_pixcel_color.c \
		initialize.c \
		check_map_error.c \
		get_texture.c \
		key_move.c \
		$(UTLS)
OBJS := $(SRCS:.c=.o)
CC := gcc -g
RM := rm -f
CFLAGS := -Wall -Wextra -Werror -I./
NAME := so_long
LIBFT := libft.a
LIBFT_DIR := ./libft
DYLIB := libmlx.dylib
DYLIB_DIR := ./minilibx_mms_20200219
LIBMLX := libmlx_Linux.a
LIBMLX_DIR := ./minilibx-linux

all:$(NAME)

ifeq ($(shell uname),Linux)
$(NAME):$(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $^ -L. -lXext -lX11 -lm -o $@
clean:
	$(RM) $(OBJS) && make clean -C $(LIBFT_DIR) && make clean -C $(LIBMLX_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX) && make fclean -C $(LIBFT_DIR)

else

$(NAME):$(OBJS) $(LIBFT) $(DYLIB)
	$(CC) $(CFLAGS) $^ -o $@
	$(warning OBJS=$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(DYLIB) -o $(NAME))
clean:
	$(RM) $(OBJS) && make clean -C $(LIBFT_DIR) && make clean -C $(DYLIB_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(DYLIB) && make fclean -C $(LIBFT_DIR)

endif

$(LIBFT):
	make -C $(LIBFT_DIR) && cp $(LIBFT_DIR)/$(LIBFT) .
$(LIBMLX):
	make -C $(LIBMLX_DIR) && cp $(LIBMLX_DIR)/$(LIBMLX) .
$(DYLIB):
	make -C $(DYLIB_DIR) && cp $(DYLIB_DIR)/$(DYLIB) .

re:			fclean all

.PHONY:		clean fclean re all

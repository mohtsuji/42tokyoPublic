# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 16:52:47 by mohtsuji          #+#    #+#              #
#    Updated: 2021/03/26 22:56:59 by mohtsuji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME	= get_eswe.c \
			get_fcs.c \
			main.c \
			get_info.c \
			get_next_line.c \
			search_pos.c \
			load_image.c \
			key_press.c \
			key_press2.c \
			main_loop.c \
			sprite.c \
			calc.c \
			bitmap.c \
			close_game.c \
			check.c \
			check2.c \
			ft_newatoi.c \
			utils.c \
			calc2.c \
			put_error.c \
			initialize.c \
			file_malloc.c \
			freeeee.c \

OBJS := $(SRCNAME:.c=.o)
CC := gcc -g
RM := rm -f
CFLAGS := -Wall -Wextra -Werror -I./
NAME := cub3D
LIBFT := libft.a
LIBFT_DIR := ./libft
LIBMLX := libmlx_Linux.a
LIBMLX_DIR := ./minilibx-linux
DYLIB := libmlx.dylib
DYLIB_DIR := ./minilibx_mms_20200219


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

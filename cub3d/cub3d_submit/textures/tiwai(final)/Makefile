# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 22:10:46 by tiwai             #+#    #+#              #
#    Updated: 2020/11/30 21:49:52 by tiwai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCS := check.c draw.c draw_sprite.c get_next_line.c init_else.c init_info.c init_player.c init_struct.c \
 key.c main.c move.c ray.c screenshot32.c setter.c setter_utls.c setter_utls2.c sprite.c utls.c
OBJS := $(SRCS:.c=.o)
CUB_HEADER := cub3.h
LIB_HEADER := libft.h
NAME := cub3D
LIBFT := libft.a
LIBFT_DIR := ./libft
DYLIB := libmlx.dylib
DYLIB_DIR := ./minilibx_mms
LIBMLX := libmlx_Linux.a
LIBMLX_DIR := ./minilibx-linux

all:$(NAME)

ifeq ($(shell uname),Linux)

$(NAME):$(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $^ -L. -lXext -lX11 -lm -o $@

clean:
	$(RM) $(OBJS) && make clean -C $(LIBFT_DIR) && make clean -C $(LIBMLX_DIR)

fclean:clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX) && make fclean -C $(LIBFT_DIR)

else

$(NAME):$(OBJS) $(LIBFT) $(DYLIB) 
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS) && make clean -C $(LIBFT_DIR) && make clean -C $(DYLIB_DIR)

fclean:clean
	$(RM) $(NAME) $(LIBFT) $(DYLIB) && make fclean -C $(LIBFT_DIR)

endif

$(LIBFT):
	make bonus -C $(LIBFT_DIR) && cp $(LIBFT_DIR)/$(LIBFT) .

$(LIBMLX):
	make -C $(LIBMLX_DIR) && cp $(LIBMLX_DIR)/$(LIBMLX) .

$(DYLIB):
	make -C $(DYLIB_DIR) && cp $(DYLIB_DIR)/$(DYLIB) .

re:fclean all

.PHONY:all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 13:17:12 by mohtsuji          #+#    #+#              #
#    Updated: 2021/11/25 13:05:17 by mohtsuji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
CLIENT_NAME := client
SERVER_NAME := server
B_CLIENT_NAME := client_bonus
B_SERVER_NAME := server_bonus
NAME := minitalk
BONUS := bonus

UTLS := ./utls/ft_putstr_fd.c \
			./utls/ft_atoi.c \
			./utls/ft_strlen.c \
			./utls/send_signal.c \
			./utls/ft_putnbr_fd.c \
			./utls/error.c

CLIENT_SRCS := client.c $(UTLS)
SERVER_SRCS := server.c $(UTLS)

B_UTLS := ./bonus/ft_putnbr_fd_bonus.c \
				./bonus/error_bonus.c \
				./bonus/ft_putstr_fd_bonus.c \
				./bonus/send_signal_bonus.c \
				./bonus/ft_atoi_bonus.c \
				./bonus/ft_strlen_bonus.c


B_CLIENT_SRCS := ./bonus/client_bonus.c $(B_UTLS)
B_SERVER_SRCS := ./bonus/server_bonus.c $(B_UTLS)

CLIENT_OBJS := $(CLIENT_SRCS:.c=.o)
SERVER_OBJS := $(SERVER_SRCS:.c=.o)

B_CLIENT_OBJS := $(B_CLIENT_SRCS:.c=.o)
B_SERVER_OBJS := $(B_SERVER_SRCS:.c=.o)

all:$(NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -I . -o $@
$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -I . -o $@

$(B_CLIENT_NAME): $(B_CLIENT_OBJS)
	$(CC) $(CFLAGS) $(B_CLIENT_OBJS) -I ./bonus -o $@
$(B_SERVER_NAME): $(B_SERVER_OBJS)
	$(CC) $(CFLAGS) $(B_SERVER_OBJS) -I ./bonus -o $@

$(NAME):$(CLIENT_NAME) $(SERVER_NAME)

$(BONUS):$(B_CLIENT_NAME) $(B_SERVER_NAME)

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS) $(B_CLIENT_OBJS) $(B_SERVER_OBJS)

fclean:clean
	$(RM) $(NAME) $(CLIENT_NAME) $(SERVER_NAME) $(bONUS) $(B_CLIENT_NAME) $(B_SERVER_NAME)

re:fclean all


.PHONY: all clean fclean re bonus $(NAME)

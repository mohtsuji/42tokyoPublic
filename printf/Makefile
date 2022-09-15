# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 07:14:48 by mohtsuji          #+#    #+#              #
#    Updated: 2022/09/15 15:29:13 by mohtsuji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	:=	ft_printf.c\
			di_out.c\
			s_out.c\
			c_out.c\
			ft_atoi.c\
			ft_strchr.c\
			ft_strlen.c\
			put.c\
			u_out.c\
			pa_out.c\
			x_out.c\
			x_hontai.c\
			p_out.c\
			p_hontai.c\
			di_hontai.c\
			u_hontai.c\

OBJS	:= $(SRCS:.c=.o)

NAME	:= libftprintf.a

CC		:= gcc

CFLAGS	:= -Wall -Wextra -Werror

AR		:= ar rc

RM		:= rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/26 15:21:03 by mohtsuji          #+#    #+#              #
#    Updated: 2022/01/13 14:45:46 by mohtsuji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
BONUS_SRCNAME	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS	= ${SRCNAME:.c=.o}
BONUS_OBJS	= ${BONUS_SRCNAME:.c=.o}
NAME	= libft.a
NAME_BONUS = bonus.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I./

ifdef MAKE_BONUS
	OBJS_ALL = ${OBJS} ${BONUS_OBJS}
else
	OBJS_ALL = $(OBJS)
endif

${NAME}:	${OBJS_ALL}
			ar rc ${NAME} ${OBJS_ALL}

${NAME_BONUS}:	${OBJS_ALL}
			ar rc ${NAME_BONUS} ${OBJS_ALL}

all:		${NAME}

bonus:
		make MAKE_BONUS=1
		${all}
		

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all

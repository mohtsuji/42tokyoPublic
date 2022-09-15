# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiwai <tiwai@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/27 15:47:37 by tiwai             #+#    #+#              #
#    Updated: 2020/07/02 17:12:37 by tiwai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := -rv
SRCS := ft_isalnum.c ft_itoa.c ft_memmove.c ft_putstr_fd.c ft_strlcat.c ft_strnstr.c ft_toupper.c\
 ft_isalpha.c ft_memccpy.c ft_memset.c ft_split.c ft_strlcpy.c ft_strrchr.c ft_atoi.c ft_isascii.c\
 ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcmp.c\
 ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_substr.c ft_calloc.c ft_isprint.c ft_memcpy.c ft_putnbr_fd.c\
 ft_strjoin.c ft_strncmp.c ft_tolower.c
OBJS := $(SRCS:.c=.o)
HEADER := libft.h
NAME := libft.a
SRCS_BONUS := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_BONUS := $(SRCS_BONUS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus:$(NAME) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY:all clean fclean re bonus

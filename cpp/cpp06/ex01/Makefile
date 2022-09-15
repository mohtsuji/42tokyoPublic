CXX := clang++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp \
		Data.cpp

OBJS := $(SRCS:.cpp=.o)

NAME := reintrerpret

all : $(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re


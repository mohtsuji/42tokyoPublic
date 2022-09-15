CXX := clang++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := tester/ft_test.cpp

OBJS := $(SRCS:.cpp=.o)

NAME := ft_test

all : $(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re

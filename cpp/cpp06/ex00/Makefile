CXX := clang++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp \
		Convert.cpp \
		Char.cpp \
		Int.cpp \
		Float.cpp \
		Double.cpp \
		execConvert.cpp

OBJS := $(SRCS:.cpp=.o)

NAME := convert

all : $(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re


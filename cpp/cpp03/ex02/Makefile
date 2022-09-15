CXX := clang++

CXXFLAGS := -Wall -Wextra -Werror

NAME := clap

SRCS := main.cpp \
		ClapTrap.cpp \
		FragTrap.cpp \
		ScavTrap.cpp

OBJS := $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



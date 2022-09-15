CXX := c++

CXXFLAGS := -Wall -Wextra -Werror

NAME := materia

SRCS := main.cpp \
		AMateria.cpp \
		MateriaSource.cpp \
		Ice.cpp \
		Cure.cpp \
		Character.cpp

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



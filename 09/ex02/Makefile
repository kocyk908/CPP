NAME       = PmergeMe

CPP        = c++
CPPFLAGS   = -Wall -Wextra -Werror -std=c++98 -O3 -march=native -DNDEBUG -pipe -flto
LDFLAGS    = -flto

SRC        = main.cpp PmergeMe.cpp vector.cpp deque.cpp
OBJ        = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
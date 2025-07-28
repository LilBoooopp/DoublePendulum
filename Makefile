CC = c++
FLAGS = #-Werror -Wextra -Wall 
NAME = doublepen

SRCS = main.cpp pendulum.cpp Trail.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

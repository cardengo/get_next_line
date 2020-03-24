NAME = gnl

SRC = main.c get_next_line.c libft/ft*

HEAD = get_next_line.h

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -I $(HEAD)
all:
	$(NAME)

val:
	valgrind --leak-check=yes ./$(NAME)

clean:
	rm -rf $(NAME)


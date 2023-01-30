SRC=*.c
NAME=minishell
CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
LIBS=-lreadline
COMPILED_OBJS=$(shell find . -name '*.o')

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIBS)

clean:
	rm -rf $(COMPILED_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

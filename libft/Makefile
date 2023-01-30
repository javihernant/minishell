# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahernan <jahernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 17:18:21 by jahernan          #+#    #+#              #
#    Updated: 2023/01/30 20:13:35 by jahernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS= -I./include
DBG = 

NAME := libft.a
SRC := \
	ft_isspace.c \
	ft_min.c \
	ft_strcpy_range.c \
	ft_strlen.c 
			
SRC := $(addprefix src/,$(SRC))

COMPILED_OBJS = $(shell find . -name '*.o')

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ $(DBG)

clean:
	rm -rf $(COMPILED_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.phony: all clean fclean re

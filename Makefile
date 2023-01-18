# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 10:29:13 by hmoulher          #+#    #+#              #
#    Updated: 2018/11/29 11:55:24 by hmoulher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

CFLAGS = -Wall -Wextra -Werror -I ./includes
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		make -C libft/ fclean && make -C libft
		clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
		clang  -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
		clang -o gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
clean:
		rm -f main.o get_next_line.o
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

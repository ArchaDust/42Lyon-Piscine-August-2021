# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 14:59:12 by aberneli          #+#    #+#              #
#    Updated: 2021/08/25 10:57:03 by lgeniaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := bsq

CC := gcc
FLAGS := -Wall -Wextra -Werror -O3

SRC := main.c ft_memset.c ft_line.c ft_strcpy.c ft_file.c ft_square.c \
	ft_getters.c ft_print_bsq.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FlAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

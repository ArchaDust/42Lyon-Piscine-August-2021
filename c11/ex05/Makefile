# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberneli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 14:59:12 by aberneli          #+#    #+#              #
#    Updated: 2021/08/21 23:05:59 by aberneli         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := do-op

CC := gcc
FLAGS := -Wall -Wextra -Werror

SRC := main.c ft_atoi.c ft_op.c ft_putnbr.c ft_putstr.c
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FlAGS) $(OBJ) -o $(NAME)

%.o: %.c do_op.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberneli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 14:59:12 by aberneli          #+#    #+#              #
#    Updated: 2021/08/26 09:15:32 by aberneli         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := ft_hexdump

CC := gcc
FLAGS := -Wall -Wextra -Werror

SRC := main.c ft_strlen.c ft_readcat.c ft_format.c ft_memcmp.c ft_dumpc.c \
	ft_memcpy.c ft_dump.c ft_err.c
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberneli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/22 23:09:23 by aberneli          #+#    #+#              #
#    Updated: 2021/08/22 23:20:29 by aberneli         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := rush-02

CC := gcc
FLAGS := -Wall -Wextra -Werror -fsanitize=address

SRC := main.c ft_split.c ft_strlen.c ft_strcat.c ft_file.c \
	ft_parse_utils.c ft_sanitize_input.c ft_start_dict.c \
	ft_format.c ft_cat_register.c ft_digit_split.c ft_itoa.c ft_memset.c \
	ft_power_to_array.c ft_atoicheck.c ft_assign_digit.c ft_putstr.c

OBJ := $(SRC:.c=.o)
HEADER := dict.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

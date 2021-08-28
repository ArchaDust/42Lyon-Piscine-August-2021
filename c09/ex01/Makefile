# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberneli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 14:59:12 by aberneli          #+#    #+#              #
#    Updated: 2021/08/20 21:23:13 by aberneli         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := gcc
FLAGS := -Wall -Wextra -Werror
AR_NAME := ar
AR_FLAGS := rcs

SRC := ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ := $(SRC:.c=.o)
HEADER := ft.h

SRC_DIR := ./srcs/
INC_DIR := ./includes/

SRCS := $(addprefix $(SRC_DIR), $(SRC))
OBJS := $(addprefix $(SRC_DIR), $(OBJ))
INCS := $(addprefix $(INC_DIR), $(HEADER))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR_NAME) $(AR_FLAGS) $(NAME) $(OBJS)

./srcs/%.o: ./srcs/%.c $(INCS)
	$(CC) $(FLAGS) -I includes -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

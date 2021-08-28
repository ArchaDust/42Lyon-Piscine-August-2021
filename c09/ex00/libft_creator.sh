# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberneli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 14:50:38 by aberneli          #+#    #+#              #
#    Updated: 2021/08/19 19:09:30 by aberneli         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

gcc -Wall -Wextra -Werror -c ft_putchar.c -o ft_putchar.o
gcc -Wall -Wextra -Werror -c ft_swap.c -o ft_swap.o
gcc -Wall -Wextra -Werror -c ft_strlen.c -o ft_strlen.o
gcc -Wall -Wextra -Werror -c ft_putstr.c -o ft_putstr.o
gcc -Wall -Wextra -Werror -c ft_strcmp.c -o ft_strcmp.o
ar rcs libft.a ft_putchar.o ft_swap.o ft_strlen.o ft_putstr.o ft_strcmp.o

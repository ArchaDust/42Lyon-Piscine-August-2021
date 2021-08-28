/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 10:43:15 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/15 16:40:08 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boxes.h"

static int	ft_is_num(char c)
{
	return (c >= '1' && c <= '9');
}

static int	ft_convert_input_to_length(int n)
{
	if (n % 4 != 0)
		return (0);
	return (n / 4);
}

int	ft_get_input_length(char *input)
{
	int	i;

	if (!input)
		return (0);
	i = 0;
	while (input[i] != '\0')
	{
		if (i % 2 == 0 && !ft_is_num(input[i]))
			return (0);
		if (i % 2 == 1 && input[i] != ' ')
			return (0);
		i++;
	}
	return (ft_convert_input_to_length(i / 2 + 1));
}

int	ft_check_input(char *input, int n)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (ft_is_num(input[i]))
		{
			if (input[i] - '0' > n)
				return (-1);
		}
		i++;
	}
	return (0);
}

void	ft_get_input_data(t_board *board, char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < board->length * 2)
	{
		board->border_up[j] = input[i] - '0';
		board->border_down[j] = input[i + board->length * 2] - '0';
		board->border_left[j] = input[i + board->length * 4] - '0';
		board->border_right[j] = input[i + board->length * 6] - '0';
		i += 2;
		j++;
	}
}

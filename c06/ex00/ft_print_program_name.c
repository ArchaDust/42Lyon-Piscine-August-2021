/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:34:48 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/07 15:39:21 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_printstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc > 0)
		ft_printstr(argv[0]);
	return (0);
}

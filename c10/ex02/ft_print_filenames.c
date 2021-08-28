/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_filenames.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 08:38:54 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/23 08:41:39 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

static void	ft_putstr(char *str)
{
	int		i;

	i = ft_strlen(str);
	write(1, str, i);
}

void	ft_print_filenames(char *filename, int flag)
{
	if (!flag)
		return ;
	ft_putstr("==> ");
	ft_putstr(filename);
	ft_putstr(" <==\n");
}

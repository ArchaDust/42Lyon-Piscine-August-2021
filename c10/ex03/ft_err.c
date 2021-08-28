/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 08:59:16 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 09:15:43 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

static void	ft_puterror(char *str, char *pname, char *fname)
{
	int		i;
	int		p;
	int		f;

	i = ft_strlen(str);
	p = ft_strlen(pname);
	f = ft_strlen(fname);
	write(2, pname, p);
	write(2, ": ", 2);
	write(2, fname, f);
	write(2, ": ", 2);
	write(2, str, i);
	write(2, "\n", 1);
}

void	ft_err(int errcode, char *pname, char *fname)
{
	char	*str;

	str = strerror(errcode);
	if (str)
		ft_puterror(str, pname, fname);
}

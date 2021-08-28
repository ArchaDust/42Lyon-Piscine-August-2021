/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 08:23:37 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 11:11:19 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail(t_file *f, int c)
{
	int	pos;

	if (!f->f || f->len == 0)
		return ;
	pos = f->len - c;
	if (pos < 0)
	{
		pos = 0;
		c = f->len - 1;
	}
	write(1, &f->f[pos], c);
}
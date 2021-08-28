/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 08:46:37 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/09 16:11:13 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strlen_checkbase(char *str)
{
	int				i;
	unsigned char	base_check[256];

	i = 0;
	while (i < 256)
		((unsigned char *)base_check)[i++] = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (-1);
		base_check[(unsigned char)str[i]]++;
		if (base_check[(unsigned char)str[i]] > 1)
			return (-1);
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

static void	ft_put_base(unsigned int c, char *b, int blen)
{
	unsigned char	digit;

	digit = b[c % blen];
	c /= blen;
	write(1, &digit, 1);
	if (c > 0)
		ft_put_base(c, b, blen);
}

static void	ft_recurse(unsigned int nbr, char *base, int blen)
{
	if (nbr > (unsigned int)(blen - 1))
		ft_recurse(nbr / blen, base, blen);
	ft_put_base(nbr % blen, base, blen);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				blen;
	unsigned int	nb;

	if (!base)
		return ;
	blen = ft_strlen_checkbase(base);
	if (blen < 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = -nbr;
	}
	else
		nb = nbr;
	ft_recurse(nb, base, blen);
}

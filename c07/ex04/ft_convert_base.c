/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:36:10 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/18 17:37:08 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen_checkbase(char *str);

int	ft_trim(char *str, char *base);

int	ft_atoi_base(char *str, char *base);

static int	ft_get_num_len(int nbr, int blen)
{
	int				len;
	unsigned int	check;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len = 1;
		check = -nbr;
	}
	else
		check = nbr;
	while (check > 0)
	{
		check /= blen;
		len++;
	}
	return (len);
}

static void	ft_itoa_base_fill(char *str, unsigned int nbr, char *base, int nlen)
{
	int		i;
	int		blen;

	blen = ft_strlen_checkbase(base);
	i = nlen - 1;
	while (nbr > 0)
	{
		str[i] = base[nbr % blen];
		nbr /= blen;
		i--;
	}
	str[nlen] = '\0';
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*result;
	int		num_len;
	int		blen;

	blen = ft_strlen_checkbase(base);
	num_len = ft_get_num_len(nbr, blen);
	result = malloc(sizeof(char) * (num_len + 1));
	if (!result)
		return (NULL);
	if (nbr == 0)
	{
		result[0] = base[0];
		result[1] = '\0';
		return (result);
	}
	result[0] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		ft_itoa_base_fill(result, -nbr, base, num_len);
	}
	else
		ft_itoa_base_fill(result, nbr, base, num_len);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		bf_len;
	int		bt_len;
	char	*converted;
	int		tmp;

	if (!nbr || !base_from || !base_to)
		return (NULL);
	bf_len = ft_strlen_checkbase(base_from);
	bt_len = ft_strlen_checkbase(base_to);
	if (bf_len < 2 || bt_len < 2)
		return (NULL);
	tmp = ft_atoi_base(nbr, base_from);
	converted = ft_itoa_base(tmp, base_to);
	return (converted);
}

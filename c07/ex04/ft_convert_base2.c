/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:13:04 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/18 13:43:06 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen_checkbase(char *str)
{
	int				i;
	unsigned char	base_check[256];

	i = 0;
	while (i < 256)
		((unsigned char *)base_check)[i++] = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ' \
				|| str[i] == '\t' || str[i] == '\v' || str[i] == '\r' \
				|| str[i] == '\n' || str[i] == '\f')
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

int	ft_trim(char *str, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
				return (i);
			j++;
		}
		if (str[i] == '-' || str[i] == '+')
			return (i);
		if (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
					str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_managesigns(char *str, int *i, char *base)
{
	int	negative;
	int	j;

	negative = 1;
	while (str[*i] != '\0' && (str[*i] == '-' || str[*i] == '+'))
	{
		if (str[*i] == '-')
			negative = -negative;
		(*i)++;
	}
	j = 0;
	while (base[j] != '\0')
	{
		if (str[*i] == base[j])
			return (negative);
		j++;
	}
	return (0);
}

static int	ft_to_base(char *str, char *base, int blen)
{
	int	j;
	int	base_test;
	int	result;

	result = 0;
	while (*str != '\0')
	{
		j = 0;
		base_test = -1;
		while (base[j] != '\0')
		{
			if (*str == base[j])
				base_test = j;
			j++;
		}
		if (base_test == -1)
			return (result);
		result *= blen;
		result += base_test;
		str++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	negative;
	int	blen;

	if (!str || !base)
		return (0);
	blen = ft_strlen_checkbase(base);
	if (blen < 2)
		return (0);
	i = ft_trim(str, base);
	if (i < 0 || str[i] == '\0')
		return (0);
	negative = ft_managesigns(str, &i, base);
	if (negative == 0)
		return (0);
	result = ft_to_base(&str[i], base, blen);
	return (result * negative);
}

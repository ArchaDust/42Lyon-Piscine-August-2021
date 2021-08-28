/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:13:04 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/12 15:24:47 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

static int	ft_trim(char *str, char *base)
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

static int	ft_to_base(char *str, char *base, int *result)
{
	int	j;
	int	base_test;

	j = 0;
	base_test = -1;
	while (base[j] != '\0')
	{
		if (*str == base[j])
			base_test = j;
		j++;
	}
	if (base_test < 0)
		return (-1);
	(*result) += base_test;
	return (1);
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
	result = 0;
	while (str[i] != '\0')
	{
		result *= blen;
		if (ft_to_base(&str[i], base, &result) < 0)
			return (result * negative);
		i++;
	}
	return (result * negative);
}

#include <stdio.h>

int main()
{
	printf("%d\n", ft_atoi_base("-\t128", "0123456789"));
}

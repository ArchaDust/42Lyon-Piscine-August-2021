/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:42:42 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 17:41:41 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	check_asc;
	int	check_des;

	if (!tab || !f)
		return (1);
	i = 0;
	check_asc = 1;
	check_des = 1;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			check_asc = 0;
		if ((*f)(tab[i], tab[i + 1]) < 0)
			check_des = 0;
		i++;
	}
	return (check_asc || check_des);
}

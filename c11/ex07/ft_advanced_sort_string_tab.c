/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:52:27 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 17:44:19 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort(char **tab, int i, int (*cmp)(char *, char*))
{
	char	*tmp;

	if ((*cmp)(tab[i], tab[i + 1]) > 0)
	{
		tmp = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = tmp;
	}
	i++;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char*))
{
	int		len;
	int		i;
	int		high;

	len = 0;
	if (!tab || !cmp)
		return ;
	while (tab[len] != 0)
		len++;
	high = len - 1;
	while (high > 0)
	{
		i = 0;
		while (i < high)
		{
			ft_sort(tab, i, cmp);
			i++;
		}
		high--;
	}
}

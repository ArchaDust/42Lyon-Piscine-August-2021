/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:45:35 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 17:44:06 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if ((unsigned char)(*s1) != (unsigned char)(*s2))
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
	}
	if (*s1 == '\0' || *s2 == '\0')
	{
		if ((unsigned char)(*s1) != (unsigned char)(*s2))
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
	}
	return (0);
}

void	ft_sort(char **tab, int i)
{
	char	*tmp;

	if (ft_strcmp(tab[i], tab[i + 1]) > 0)
	{
		tmp = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = tmp;
	}
	i++;
}

void	ft_sort_string_tab(char **tab)
{
	int		len;
	int		i;
	int		high;

	len = 0;
	if (!tab)
		return ;
	while (tab[len] != 0)
		len++;
	high = len - 1;
	while (high > 0)
	{
		i = 0;
		while (i < high)
		{
			ft_sort(tab, i);
			i++;
		}
		high--;
	}
}

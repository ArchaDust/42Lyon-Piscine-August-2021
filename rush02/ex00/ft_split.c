/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:48:12 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 01:02:23 by lgeniaux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static int	ft_is_sep(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_count_words(char *str, char *charset)
{
	size_t	count;
	int		in_word;
	int		i;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_sep(str[i], charset) && !in_word)
		{
			in_word = 1;
			count++;
		}
		if (ft_is_sep(str[i], charset) && in_word)
			in_word = 0;
		i++;
	}
	return (count);
}

static size_t	ft_strlen_sep(char *str, char *charset)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && !ft_is_sep(str[i], charset))
		i++;
	return (i);
}

static char	*ft_get_next_word(char *str, char *charset, int *i)
{
	char	*result;
	size_t	len;
	size_t	j;

	len = ft_strlen_sep(&str[*i], charset);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (str[*i] != '\0' && !ft_is_sep(str[*i], charset))
	{
		result[j] = str[*i];
		(*i)++;
		j++;
	}
	result[len] = '\0';
	while (str[*i] != '\0' && ft_is_sep(str[*i], charset))
		(*i)++;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**spl;
	size_t	words;
	size_t	w;
	int		i;

	if (!str || !charset)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && ft_is_sep(str[i], charset))
		i++;
	words = ft_count_words(str, charset);
	spl = (char **)malloc((words + 1) * sizeof(char *));
	if (!spl)
		return (NULL);
	w = 0;
	while (w < words)
	{
		spl[w] = ft_get_next_word(str, charset, &i);
		w++;
	}
	spl[w] = NULL;
	return (spl);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 10:34:46 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/22 23:16:59 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_dict
{
	char		*key;
	char		*value;
}				t_dict;

typedef struct s_cat_reg
{
	char		*data;
	int			valid;
}				t_cat_reg;

// ft_split.c
char	**ft_split(char *str, char *charset);

// ft_strlen.c
int		ft_strlen(char *str);

// ft_strcat.c
char	*ft_strcat(char *dest, char *src);

// ft_file.c
char	*ft_full_read(char *file_name);
char	*ft_full_stdin_read(char **key);

// ft_sanitize_input.c
t_dict	*ft_sanitize_input(char **spl);

// ft_parse_utils.c
int		ft_is_ws(char c);
char	*ft_get_key(char *str);
char	*ft_get_value(char *str);

// ft_start_dict.c
int		ft_start_dict(char *file, char *input_key, int s_f, t_cat_reg *reg);

//ft_format.c
char	*find_key(t_dict *dict, char *key);
char	*get_number_array(char *line_array);

//ft_digit_split
void	ft_digit_split(t_dict *dict, t_cat_reg *reg, char *input);

// ft_cat_register.c
void	ft_register(t_cat_reg *reg, char *str);

//ft_memset.c
void	ft_memset(void *mem, uint8_t val, size_t size);

//ft_itoa.c
char	*ft_itoa(int nb);

//ft_power_to_array.c
char	*ft_power_to_array(int power);

//ft_assign_digit.c
void	if_hundreds(char *group, t_dict *dict, t_cat_reg *reg, int i);
void	if_tens(char *group, t_dict *dict, t_cat_reg *reg, int i);
void	if_units(char *group, t_dict *dict, t_cat_reg *reg, int i);

// ft_atoicheck.c
int		ft_atoicheck(char *str);

// ft_putstr.c
void	ft_putstr(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:23:49 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 09:11:40 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>

typedef struct s_file
{
	uint8_t		*f;
	size_t		len;
}				t_file;

//ft_readcat.c
int		fetch_file(t_file *f, int fd);

// ft_atoi.c
int		ft_atoi(char *str);

// ft_memcmp.c
int		ft_memcmp(uint8_t *s1, uint8_t *s2, unsigned int n);

// ft_memcpy.c
void	ft_memcpy(uint8_t *mem, uint8_t *src, size_t len);

// ft_strlen.c
int		ft_strlen(char *str);

// ft_tail.c
void	ft_tail(t_file *f, int c);

// ft_print_filenames.c
void	ft_print_filenames(char *filename, int flag);

// ft_err.c
void	ft_err(int errcode, char *pname, char *fname);

#endif

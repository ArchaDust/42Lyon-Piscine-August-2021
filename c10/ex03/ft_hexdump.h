/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 23:08:54 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/26 09:22:05 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

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

// ft_strlen.c
int		ft_strlen(char *str);

// ft_memcmp.c
int		ft_memcmp(uint8_t *s1, uint8_t *s2, unsigned int n);

// ft_memcpy.c
void	ft_memcpy(uint8_t *mem, uint8_t *src, size_t len);

// ft_format.c
void	write_readable_c(uint8_t *str, int len);
void	write_offset_c(uint32_t offset, int s);
void	write_offset(uint32_t offset, int s);
void	write_hex(uint8_t c);

// ft_dumpc.c
void	ft_dumpc(t_file *f);

// ft_dump.c
void	ft_dump(t_file *f);

// ft_err.c
void	ft_err(int errcode, char *pname, char *fname);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:24:26 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/25 13:18:42 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_bsq
{
	int			sqr;
	int			x;
	int			y;
}				t_bsq;

typedef struct s_map
{
	t_bsq		bsq;
	int			**map;
	int			h;
	int			w;
	char		empty;
	char		obstacle;
	char		fill;
}				t_map;

typedef struct s_line
{
	int			*line;
	int			size;
	int			cap;
}				t_line;

typedef struct s_map_parse
{
	t_line		line;
	int			**map;
	int			w;
	int			h;
	int			x;
	int			y;
	char		empty;
	char		obstacle;
	char		fill;
	char		err_flag;
}				t_map_parse;

// ft_memset.c
void			ft_memset(void *addr, uint8_t val, size_t size);

// ft_strcpy.c
char			*ft_strcpy(char *dst, char *src);

// ft_line.c
void			ft_push_to_line(t_line *l, int x);
int				ft_prep_line(t_line *l);

// ft_file.c
int				read_file(t_map_parse *m, int fd);

//ft_getters.c
int				get_cell(t_map *m, int x, int y);
int				get_cell_nextx(t_map *m, int x, int y);
int				get_cell_nexty(t_map *m, int x, int yi);

//ft_algo.c
void			ft_square(t_map *m);

// ft_print_bsq.c
void			ft_print_bsq(t_map *m);

#endif

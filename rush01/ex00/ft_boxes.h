/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boxes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:53:00 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/15 21:16:30 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOXES_H
# define FT_BOXES_H

# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_byte;

typedef struct s_lookup
{
	t_byte		*data;
	int			filled;
	int			fact;
}				t_lookup;

typedef struct s_board
{
	t_lookup	look;
	t_byte		*cell;
	int			*border_up;
	int			*border_down;
	int			*border_left;
	int			*border_right;
	int			length;
}				t_board;

// ft_board.c
void	ft_display_board(t_board *board);
void	ft_delete_board(t_board *board);
int		ft_init_board(t_board *board, int length);

// ft_parse.c
int		ft_get_input_length(char *input);
int		ft_check_input(char *input, int n);
void	ft_get_input_data(t_board *board, char *input);

// ft_valid.c
int		ft_valid_up(t_board *board, int pos);
int		ft_valid_down(t_board *board, int pos);
int		ft_valid_left(t_board *board, int pos);
int		ft_valid_right(t_board *board, int pos);

// ft_solve.c
int		ft_verif_depth(t_board *board, int depth);
int		ft_solve(t_board *board, int depth);

// ft_lookup.c
void	ft_generate_lookup(t_lookup *look, int size);

#endif

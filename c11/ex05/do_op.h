/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:33:10 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/20 13:21:23 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

//ft_atoi.c
int		ft_atoi(char *str);

//ft_putnbr.c
void	ft_putnbr(int nb);

//ft_putstr.c
void	ft_putstr(char *str);

//ft_op.c
void	ft_plus(int a, int b);
void	ft_minus(int a, int b);
void	ft_mult(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);

#endif

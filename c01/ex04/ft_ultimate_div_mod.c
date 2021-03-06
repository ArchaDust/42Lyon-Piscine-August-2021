/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:19:29 by aberneli          #+#    #+#             */
/*   Updated: 2021/08/04 19:34:01 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (!a || !b)
		return ;
	div = (*a) / (*b);
	mod = (*a) % (*b);
	*a = div;
	*b = mod;
}

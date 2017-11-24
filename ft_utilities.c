/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:40:11 by pclement          #+#    #+#             */
/*   Updated: 2017/11/24 13:57:10 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_int_strlen(char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int		ft_nb_tetri(t_tetri *first)
{
	int i;

	i = 0;
	while (first)
	{
		i++;
		first = first->next;
	}
	return (i);
}

int		ft_min_square(t_info info)
{
	int nb;

	nb = 1;
	while (nb * nb < (info.nb_tetri * 4))
		nb++;
	return (nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:52:24 by nvergnac          #+#    #+#             */
/*   Updated: 2017/11/21 19:18:42 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min_width(t_tetri *element)
{
	int i;
	int min;

	min = 0;
	i = 0;
	while (i < 4)
	{
		if (element->coord[i][0] < min)
			min = element->coord[i][0];
		i++;
	}
	return (min);
	
}

int		ft_max_width(t_tetri *element)
{
	int i;
	int max;

	max = 0;
	i = 0;
	while (i < 4)
	{
		if (element->coord[i][0] > max)
			max = element->coord[i][0];
		i++;
	}
	return (max);

}

int		ft_max_height(t_tetri *element)
{
	int i;
	int max;

	max = 0;
	i = 0;
	while (i < 4)
	{
		if (element->coord[i][1] > max)
			max = element->coord[i][1];
		i++;
	}
	return (max + 1);
}

void	ft_getclean_coord(t_tetri *element)
{
	int j;

	j = 1;
	while (j <= 3)
	{
		element->coord[j][0] = element->coord[j][0] - element->coord[0][0];
		element->coord[j][1] = element->coord[j][1] - element->coord[0][1];
	}
	element->coord[0][0] = 0;
	element->coord[0][1] = 0;
	element->heigth = ft_max_height(element);
	element->width = (ft_max_width - ft_min_width) + 1;
}

t_tetri	*ft_fill_struct(char *buf)
{
	int		i;
	int		j;
	t_tetri	*element;

	i = 0;
	j = 0;
	if (!(element = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	while (buf[i] != 0)
	{
		if (buf[i] == '#')
		{
			element->coord[j][0] = (i % 5);
			element->coord[j][1] = (i / 5);
			j++;
		}
		i++;
	}
	ft_getclean_coord(element);
	return (element);
}


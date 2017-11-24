/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:52:24 by nvergnac          #+#    #+#             */
/*   Updated: 2017/11/24 15:01:41 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_min_width(t_tetri *element)
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

static int	ft_max_width(t_tetri *element)
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

static int	ft_max_heigth(t_tetri *element)
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
	return (max);
}

void		ft_getclean_coord(t_tetri *element)
{
	int j;

	j = 1;
	while (j <= 3)
	{
		element->coord[j][0] = element->coord[j][0] - element->coord[0][0];
		element->coord[j][1] = element->coord[j][1] - element->coord[0][1];
		j++;
	}
	element->coord[0][0] = 0;
	element->coord[0][1] = 0;
	element->max_y = ft_max_heigth(element);
	element->min_x = (ft_min_width(element));
	element->max_x = (ft_max_width(element));
}

t_tetri		*ft_fill_struct(char *buf, char letter)
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
	element->letter = letter;
	element->next = NULL;
	return (element);
}

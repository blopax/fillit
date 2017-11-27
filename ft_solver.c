/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:40:59 by pclement          #+#    #+#             */
/*   Updated: 2017/11/27 15:51:44 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_tab(t_info info)
{
	int i;

	i = 0;
	while (i < info.min_square - 1)
	{
		free(info.tab[i]);
		i++;
	}
	free(info.tab);
}

t_tetri	*ft_getnext_letter(t_tetri *first, char letter)
{
	while (first->letter != letter)
		first = first->next;
	return (first);
}

int		ft_fill_size_tab(t_info info, t_tetri *first, char letter, int k)
{
	int		y;
	int		x;

	first = ft_getnext_letter(first, letter);
	y = k / info.min_square;
	while (y < info.min_square)
	{
		if (y + first->max_y < info.min_square)
		{
			x = 0;
			if (y == k / info.min_square)
				x = k % info.min_square;
			while (x < info.min_square)
			{
				if (IT[y][x] == '.' && x + FMIN >= 0 && x + FMAX < ITM)
				{
					if (ft_put_tetri(info, first, y, x) == 1)
						return (y * info.min_square + x);
				}
				x++;
			}
		}
		y++;
	}
	return (-1);
}

int		ft_size_solver(t_info info, t_tetri *first, char letter, int k)
{
	int		j;

	if (letter - 'A' == info.nb_tetri)
		return (1);
	if (k < info.min_square * info.min_square)
	{
		j = ft_fill_size_tab(info, first, letter, k);
		if (j >= 0)
		{
			if (ft_size_solver(info, first, letter + 1, 0) == 1)
				return (1);
			ft_remove_tetr_from_table(info, first, letter, j);
			if (ft_size_solver(info, first, letter, j + 1) == 1)
				return (1);
		}
	}
	return (0);
}

int		ft_solver(t_tetri *first)
{
	t_info	info;
	int		flag;

	info.nb_tetri = ft_nb_tetri(first);
	info.min_square = ft_min_square(info);
	flag = 0;
	while (flag == 0)
	{
		info.tab = ft_redim_info_table(info);
		if ((ft_size_solver(info, first, 'A', 0)) == 1)
			flag = 1;
		info.min_square = (info.min_square) + 1;
		if (flag == 0)
			ft_free_tab(info);
	}
	ft_write_solution(info);
	ft_free_tab(info);
	return (1);
}

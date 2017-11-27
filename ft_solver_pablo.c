/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:40:59 by pclement          #+#    #+#             */
/*   Updated: 2017/11/24 19:57:50 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"
#include <stdio.h>

int		ft_fill_size_tab(t_info info, t_tetri *first, char letter, int k)
{
	int		y;
	int		x;

	while (first->letter != letter)
		first = first->next;
	/*	printf("LETTER :\t%c\tmin_square :\t%d\n",first->letter,info.min_square);
		printf("first->heigth :\t%d\tfirst->width :\t%d\n\n",first->max_y ,first->max_x);*/
	y = k / 5;
	while (y < info.min_square)
	{
		if (y + first->max_y < info.min_square)
		{
			x = 0;
			if (y == k/ 5)
				x = k % 5;
			while (x < info.min_square)
			{
				if (info.tab[y][x] == '.' && x + first->min_x >= 0 && x + first->max_x < info.min_square)
				{
					if (ft_put_tetri(info, first, y, x) == 1)
					{
						k = y * 5 + x;
						return (k);
					}
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
//	int		i;

	if (letter - 'A'  == info.nb_tetri)
		return (1);
	if (k < info.min_square * info.min_square)
	{
		j = ft_fill_size_tab(info, first, letter, k);
		//le pose t il ??? en modifiant info ?
		if (j >= 0)
		{
//			write(1,"TESTz\n",6);
			if (ft_size_solver(info, first, letter + 1, 0) == 1)
			{
//				write(1,"TESTB\n",6);
				return (1);
			}

			ft_remove_tetr_from_table(info, letter);
			if (ft_size_solver(info, first, letter, j + 1) == 1)
			{
//				write(1,"TESTC\n",6);
				return (1);
			}
//				write(1,"TESTy\n",6);

//				write(1,"TESTx\n",6);
			ft_remove_tetr_from_table(info, letter);
//				write(1,"TESTw\n",6);
		}
	}
	return (0);
}

char	*ft_init_free_tetri(t_info info)
{
	int		i;

	i = 0;
	if (!(info.free_tetri = (char*)malloc(sizeof(char) * info.nb_tetri)))
		return (0);
	while (i < info.nb_tetri)
	{
		info.free_tetri[i] = '.';
		i++;
	}
	return (info.free_tetri);
}


int		ft_solver(t_tetri *first)
{
	t_info	info;
	int		flag;

	info.nb_tetri = ft_nb_tetri(first);
	info.min_square = ft_min_square(info);
	//printf("nb_tetri :\t%d\tmin_square :\t%d\n",info.nb_tetri,info.min_square);
	flag = 0;
	while (flag == 0)
	{
		info.tab = ft_redim_info_table(info);
		if ((info.free_tetri = ft_init_free_tetri(info)) == 0)
			return (0);
//		write(1,"TEST1\n",6);
		if ((ft_size_solver(info, first, 'A', 0)) == 1)
			flag = 1;
		info.min_square = (info.min_square) + 1;
//		write(1,"TEST2\n",6);
		if (flag == 0)
			ft_free_tab(info);
//		write(1,"TEST3\n",6);
	}
	ft_write_solution(info);
	ft_free_tab(info);
	return (1);
}

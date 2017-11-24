/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:40:59 by pclement          #+#    #+#             */
/*   Updated: 2017/11/22 20:07:37 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"
#include <stdio.h>

int	ft_fill_info_struct(t_tetri *first)
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

int		ft_init_max_square(t_tetri *first)
{
	t_tetri	*position;
	int		max_square;

	max_square = 0;
	position = first;
	while (position)
	{
		max_square = ft_min(position->width, position->heigth) + max_square;
		position = position->next;
	}
	return (max_square);
}

int		ft_min_square(t_info info)
{
	int nb;

	nb = 1;
	while (nb * nb < (info.nb_tetri * 4))
		nb++;
	return (nb);
}

char **ft_redim_info_table(t_info info)
{
	int i;
	int j;

	i = 0;
	info.tab = (char**)malloc(sizeof(char*) * info.max_square);
	while (i < info.max_square)
	{
		j = 0;
		info.tab[i] = (char*)malloc(sizeof(char) * info.max_square);
		while (j < info.max_square)
		{
			info.tab[i][j] = '.';
			//write(1,&(info.tab[i][j]), 1);
			j++;
		}
		i++;
	}
	return (info.tab);
}

int ft_fill_tab(t_tetri *position, t_info info, int i, int j)
{
	int	case_index;
	int	case_index_abs;
	int	case_index_ord;

	case_index = 1;
	write(1, "TEST6\n", 6);
	while (case_index <= 3)
	{
		case_index_abs = j + position->coord[case_index][0];
		case_index_ord = i + position->coord[case_index][1];
		if (info.tab[case_index_ord][case_index_abs] != '.'
				|| case_index_abs < 0 || case_index_abs >= info.max_square 
				|| case_index_ord < 0 || case_index_ord >= info.max_square)
			return (0);
		case_index++;
	}
	case_index = 0;
	while (case_index <= 3)
	{
		case_index_abs = j + position->coord[case_index][0];
		case_index_ord = i + position->coord[case_index][1];
		printf("i :\t%d\tABS :\t%d\tORD :\t%d\n",i, case_index_abs, case_index_ord);
		info.tab[case_index_ord][case_index_abs] = position->letter;
		case_index++;
	}
	return (1);
}

void	ft_first_solution(t_tetri *first, t_info info)
{
	int i;
	int j;
	int next_flag;

	while (first)
	{
		i = 0;
		next_flag = 0;
		while (i < info.max_square && next_flag == 0)
		{
			j = 0;
			while (j < info.max_square && next_flag == 0)
			{
				if (info.tab[i][j] == '.')
				{
					write(1, "TEST5\n", 6);
					next_flag = ft_fill_tab(first, info, i, j);
				}
				j++;
			}
			i++;
		}
		first = first->next;
	}
	i = 0;
	while (i < info.max_square)
	{
		write(1,info.tab[i],info.max_square);
		write(1,"\n", 1);
		i++;
	}
}

void	ft_solver(t_tetri *first)
{
	t_info info;

	info.nb_tetri = ft_fill_info_struct(first);
	info.max_square = ft_max(ft_init_max_square(first), 4);
	info.min_square = ft_min_square(info);
	info.tab = ft_redim_info_table(info);
	printf("nb_tetri :\t%d\tmin_square :\t%d\tmax_square :\t%d\n",info.nb_tetri,info.min_square,info.max_square);
	write(1, "TEST1\n", 6);
	ft_first_solution(first, info);
}
/*
   int		ft_tetr_pos(t_tetri *first, t_info info, char tested_letter, char **tab)
   {
   int		i;
   int		j;

   i = 0;
   j = 0;
   */

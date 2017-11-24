/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:40:59 by pclement          #+#    #+#             */
/*   Updated: 2017/11/24 14:17:23 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"
#include <stdio.h>

int		ft_put_tetri(t_info info, t_tetri *position, int y, int x)
{
	int		case_index;
	int		case_index_abs;
	int		case_index_ord;

	//printf("X :\t%d\tY :\t%d\n\n",x,y);
	case_index = 1;
	while (case_index <= 3)
	{
		case_index_abs = x + position->coord[case_index][0];
		case_index_ord = y + position->coord[case_index][1];
		if (case_index_abs < 0 || case_index_ord < 0 || case_index_abs >=
				info.min_square || case_index_ord >= info.min_square)
			return (0);
		if (info.tab[case_index_ord][case_index_abs] != '.')
			return (0);
		case_index++;
	}
	case_index = 0;
	while (case_index <= 3)
	{
		case_index_abs = x + position->coord[case_index][0];
		case_index_ord = y + position->coord[case_index][1];
//		printf("i :\t%d\tABS :\t%d\tORD :\t%d\tLETTER : %c\n\n",y, case_index_abs, case_index_ord, position->letter);
		info.tab[case_index_ord][case_index_abs] = position->letter;
		case_index++;
	}
	return (1);
}

int		ft_fill_size_tab(t_info info, t_tetri *first, int i)
{
	int		y;
	int		x;

	while (first->letter != 'A' + i)
		first = first->next;
//	printf("nb_tetri :\t%d\tmin_square :\t%d\n",info.nb_tetri,info.min_square);
//	printf("first->heigth :\t%d\tfirst->width :\t%d\n\n",first->heigth,first->width);
	y = 0;
	while (y < info.min_square)
	{
		x = 0;
		while (x < info.min_square)
		{
			if (info.tab[y][x] == '.')
			{
				if (ft_put_tetri(info, first, y, x) == 1)
				{
					return (1);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_size_solver(t_info info, t_tetri *first)
{
	int		i;
	int		j;
	int		k;

	if (ft_no_zero_in_tab(info) == 0)
	{
		return (1);
	}
	i = 0 % info.nb_tetri;
	while (i < info.nb_tetri)
	{
		k = 0;
/*		while (k < info.nb_tetri)
		{
			write(1, &(info.free_tetri[k]),1);
			write(1, "\n",1);
			write(1, "\n",1);
			k++;
		}*/
		if (info.free_tetri[i] == '.')
		{
			if (ft_fill_size_tab(info, first, i) == 0)
				return (0);
			j = 0;
/*			while (j < info.min_square)
			{
				write(1,info.tab[j],info.min_square);
				write(1,"\n", 1);
				j++;
			}
			write(1,"\n", 1);*/
			info.free_tetri[i] = 'A' + i;
			if (ft_size_solver(info, first) == 1)
				return (1);
			ft_remove_tetr_from_table(info, i);
			j = 0;
/*			while (j < info.min_square)
			{
				write(1,info.tab[j],info.min_square);
				write(1,"\n", 1);
				j++;
			}*/
			info.free_tetri[i] = '.';
		}
		i++;
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
	/*printf("nb_tetri :\t%d\tmin_square :\t%d\n",info.nb_tetri,info.min_square);*/
	flag = 0;
	while (flag == 0)
	{
		info.tab = ft_redim_info_table(info);
		if ((info.free_tetri = ft_init_free_tetri(info)) == 0)
			return (0);
		if ((ft_size_solver(info, first)) == 1)
			flag = 1;
		info.min_square = (info.min_square) + 1;
		if (flag == 0)
		{
			free(info.free_tetri);
			free(info.tab);
		}
	}
	flag = 0;
	while (flag < info.min_square)
	{
		write(1, info.tab[flag], info.min_square);
		write(1, "\n", 1);
		flag++;
	}
	return (1);
}

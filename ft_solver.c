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

int		ft_fill_size_tab(t_info info, t_tetri *first, int i)
{
	int		y;
	int		x;

	while (first->letter != 'A' + i)
		first = first->next;
	/*	printf("LETTER :\t%c\tmin_square :\t%d\n",first->letter,info.min_square);
		printf("first->heigth :\t%d\tfirst->width :\t%d\n\n",first->max_y ,first->max_x);*/
	y = 0;
	while (y < info.min_square)
	{
		x = 0;
		if (y + first->max_y < info.min_square)
		{
			while (x < info.min_square)
			{
				if (info.tab[y][x] == '.' && x + first->min_x >= 0 && x + first->max_x < info.min_square)
				{
					if (ft_put_tetri(info, first, y, x) == 1)
					{
						return (1);
					}
				}
				x++;
			}
		}
		y++;
	}
	return (0);
}

int		ft_fill_size_tab_rev(t_info info, t_tetri *first, int i)
{
	int		y;
	int		x;

	while (first->letter != 'A' + i)
		first = first->next;
	/*	printf("LETTER :\t%c\tmin_square :\t%d\n",first->letter,info.min_square);
		printf("first->heigth :\t%d\tfirst->width :\t%d\n\n",first->max_y ,first->max_x);*/
	y = 0;
	while (y < info.min_square)
	{
		x = info.min_square - 1;
		if (y + first->max_y < info.min_square)
		{
			while (x >= 0)
			{
				if (info.tab[y][x] == '.' && x + first->min_x >= 0 && x + first->max_x < info.min_square)
				{
					if (ft_put_tetri(info, first, y, x) == 1)
					{
						return (1);
					}
				}
				x--;
			}
		}
		y++;
	}
	return (0);
}
int		ft_size_solver(t_info info, t_tetri *first)
{
	int		i;
	//	int		j;
	int		k;

	if (ft_no_zero_in_tab(info) == 0)
		return (1);
	i = 0 % info.nb_tetri;
	while (i < info.nb_tetri)
	{
		k = 0;
		/*write(1, "Contenu de Free_tetri\n\n",23);
		  while (k < info.nb_tetri)
		  {
		  write(1, &(info.free_tetri[k]),1);
		  write(1, "\n",1);
		  k++;
		  }
		  write(1, "\n",1);*/
		if (info.free_tetri[i] == '.')
		{
			if (ft_fill_size_tab(info, first, i) == 0)
				return (0);
			/*j = 0;
			  while (j < info.min_square)
			  {
			  write(1,info.tab[j],info.min_square);
			  write(1,"\n", 1);
			  j++;
			  }
			  write(1,"\n", 1);*/
			info.free_tetri[i] = 'A' + i;
			/*write(1,&info.free_tetri[i],1);
			  write(1,"\n", 1);*/
			if (ft_size_solver(info, first) == 1)
				return (1);
			/*write(1,"REMOVE\n", 7);
			  write(1,&info.free_tetri[i],1);
			  write(1,"\n", 1);
			  write(1,"\n", 1);*/
			ft_remove_tetr_from_table(info, i);
			/*write(1,"Apercu de tab apres REMOVE\n", 27);
			  j = 0;
			  while (j < info.min_square)
			  {
			  write(1,info.tab[j],info.min_square);
			  write(1,"\n", 1);
			  j++;
			  }
			  write(1,"\n", 1);*/
			if (info.nb_tetri <= 7)
			{
				write(1,"TEST\n", 5);
				if (ft_fill_size_tab_rev(info, first, i) == 0)
					return (0);
				info.free_tetri[i] = 'A' + i;
				if (ft_size_solver(info, first) == 1)
					return (1);
				ft_remove_tetr_from_table(info, i);
			}
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
	printf("nb_tetri :\t%d\tmin_square :\t%d\n",info.nb_tetri,info.min_square);
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
			ft_free_tab(info);
	}
	ft_write_solution(info);
	ft_free_tab(info);
	return (1);
}

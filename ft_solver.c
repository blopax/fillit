/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:40:59 by pclement          #+#    #+#             */
/*   Updated: 2017/11/23 20:59:26 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"
#include <stdio.h>

int	ft_nb_tetri(t_tetri *first)
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

/*
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
   */

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
	if(!(info.tab = (char**)malloc(sizeof(char*) * info.min_square)))
		return (0);
	while (i < info.min_square)
	{
		j = 0;
		if (!(info.tab[i] = (char*)malloc(sizeof(char) * info.min_square)))
			return (0);
		while (j < info.min_square)
		{
			info.tab[i][j] = '.';
			//write(1,&(info.tab[i][j]), 1);
			j++;
		}
		i++;
	}
	return (info.tab);
}

/*int ft_fill_tab(t_tetri *position, t_info info, int i, int j)
  {
  int	case_index;
  int	case_index_abs;
  int	case_index_ord;

  case_index = 1;
//	write(1, "TEST6\n", 6);
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
//write(1, "TEST5\n", 6);
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
}*/



int		ft_no_zero_in_tab(t_info info)
{
	int		i;

	i = 0;
	while (i < info.nb_tetri)
	{
		if (info.free_tetri[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

void	ft_remove_tetr_from_table(t_info info, int i)
{
	int		j;
	int		k;

	j = 0;
	while (j < info.min_square)
	{
		k = 0;
		while (k < info.min_square)
		{
			if (info.tab[j][k] == 'A' + i)
				info.tab[j][k] = '.';
			k++;
		}
		j++;
	}
}
//on peut l'optimiser en recuperant le premier et ajoutant et retirant abscisse des cases mais faut rajouter tetri
// on peut l optimiser en conservant en tmp les coordonnees du dernier tetri pose


int		ft_put_tetri(t_info info, t_tetri *position, int y, int x)
{
	int	case_index;
	int	case_index_abs;
	int	case_index_ord;

	//printf("X :\t%d\tY :\t%d\n\n",x,y);
	case_index = 1;
	while (case_index <= 3)
	{
		case_index_abs = x + position->coord[case_index][0];
		case_index_ord = y + position->coord[case_index][1];
			if (case_index_abs < 0 || case_index_ord < 0 
				|| case_index_abs >= info.min_square || case_index_ord >= info.min_square)
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
		first = first -> next;


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

//renvoi 1 si trouve une solution pour une taille donnee)
int	ft_size_solver(t_info info, t_tetri *first)
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
		/*	while (j < info.min_square)
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
	int i;

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

int	ft_solver(t_tetri *first)
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
		write(1,info.tab[flag],info.min_square);
		write(1,"\n", 1);
		flag++;
	}
	return (1);
}


//rajouter other checks si forme deja utilisee


/*
   int		ft_tetr_pos(t_tetri *first, t_info info, char tested_letter, char **tab)
   {
   int		i;
   int		j;

   i = 0;
   j = 0;
   */

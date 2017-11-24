/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_utilities.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:47:34 by pclement          #+#    #+#             */
/*   Updated: 2017/11/24 14:58:53 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_redim_info_table(t_info info)
{
	int i;
	int j;

	i = 0;
	if (!(info.tab = (char**)malloc(sizeof(char*) * info.min_square)))
		return (0);
	while (i < info.min_square)
	{
		j = 0;
		if (!(info.tab[i] = (char*)malloc(sizeof(char) * info.min_square)))
			return (0);
		while (j < info.min_square)
		{
			info.tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (info.tab);
}

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

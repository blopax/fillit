/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_utilities.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:47:34 by pclement          #+#    #+#             */
/*   Updated: 2017/11/27 15:39:28 by pclement         ###   ########.fr       */
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

void	ft_remove_tetr_from_table(t_info info, t_tetri *first, char alfa, int k)
{
	int		x;
	int		y;
	int		case_index;
	int		case_index_abs;
	int		case_index_ord;

	y = k / info.min_square;
	x = k % info.min_square;
	while (first->letter != alfa)
		first = first->next;
	case_index = 0;
	while (case_index <= 3)
	{
		case_index_abs = x + first->coord[case_index][0];
		case_index_ord = y + first->coord[case_index][1];
		info.tab[case_index_ord][case_index_abs] = '.';
		case_index++;
	}
}

int		ft_put_tetri(t_info info, t_tetri *position, int y, int x)
{
	int		case_index;
	int		case_index_abs;
	int		case_index_ord;

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
		info.tab[case_index_ord][case_index_abs] = position->letter;
		case_index++;
	}
	return (1);
}

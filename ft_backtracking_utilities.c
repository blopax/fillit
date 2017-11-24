/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking_utilities.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:47:34 by pclement          #+#    #+#             */
/*   Updated: 2017/11/24 13:56:39 by pclement         ###   ########.fr       */
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

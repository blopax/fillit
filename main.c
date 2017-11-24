/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:00:34 by nvergnac          #+#    #+#             */
/*   Updated: 2017/11/24 16:09:31 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <fcntl.h>
#include <stdio.h>

void		ft_get_next_lst(t_tetri *first, t_tetri *index, char letter)
{
	if (letter != 'A')
	{
		while (first->next)
			first = first->next;
		first->next = index;
	}
}

t_tetri		*ft_treatment(int fd)
{
	int		ret;
	char	buf[22];
	t_tetri	*first;
	t_tetri	*index;
	char	letter;

	letter = 'A';
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (letter > 'Z' || ft_str_check(buf) == 1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		index = ft_fill_struct(buf, letter);
/*
** printf("case_1_X :\t%d\tcase_1_Y :\t%d\thauteur :\t%d\tlargeur :\t%d\tlettre :\t%c\n",index->coord[0][0],index->coord[0][1], index->heigth, index->width, index->letter);
** printf("case_2_X :\t%d\tcase_2_Y :\t%d\thauteur :\t%d\tlargeur :\t%d\tlettre :\t%c\n",index->coord[1][0],index->coord[1][1], index->heigth, index->width, index->letter);
** printf("case_3_X :\t%d\tcase_3_Y :\t%d\thauteur :\t%d\tlargeur :\t%d\tlettre :\t%c\n",index->coord[2][0],index->coord[2][1], index->heigth, index->width, index->letter);
** printf("case_4_X :\t%d\tcase_4_Y :\t%d\thauteur :\t%d\tlargeur :\t%d\tlettre :\t%c\n",index->coord[3][0],index->coord[3][1], index->heigth, index->width, index->letter);
*/
		if (letter == 'A')
			first = index;
		ft_get_next_lst(first, index, letter);
		index = index->next;
		letter++;
	}
//	free(index);
	return (first);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_tetri *first;

	if (argc != 2)
	{
		write(1, "usage: fill_it source_file\n", 27);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	first = ft_treatment(fd);
	ft_solver(first);
//	free(first);
	close(fd);
	sleep(1000000);
	return (0);
}

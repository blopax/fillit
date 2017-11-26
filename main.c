/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:00:34 by nvergnac          #+#    #+#             */
/*   Updated: 2017/11/24 17:18:23 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_write_solution(t_info info)
{
	int		i;

	i = 0;
	info.min_square--;
	while (i < info.min_square)
	{
		write(1, info.tab[i], info.min_square);
		write(1, "\n", 1);
		i++;
	}
}

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
	free(info.free_tetri);
}

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
	buf[20] = 'x';
	while ((ret = read(fd, buf, 21)) && letter <= 'Z')
	{
		buf[ret] = '\0';
		if (letter > 'Z' || ft_str_check(buf) == 1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		index = ft_fill_struct(buf, letter);
		if (letter == 'A')
			first = index;
		ft_get_next_lst(first, index, letter);
		index = index->next;
		letter++;
	}
	if (buf[20] != 0 || letter > 'Z')
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (first);
}
// pour gagner lignes ou on envoie buf 22 initialise de facon a ce que buf 20 different de 0 et letter = A 
// et on peut remplacer le dernier if return par une fonction et a la fin on return la fonction qui renvoie first ou 0 en ecrivant

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
	if (first)
		ft_solver(first);
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:00:34 by nvergnac          #+#    #+#             */
/*   Updated: 2017/11/22 12:48:00 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <fcntl.h>

/*void	ft_lst_change(int ret_total, t_tetri *first, t_tetri *index, char a, char *buf)
// pas sur a quoi sert cette fonction
{
	if (ret_total == 21)
	{
		first = ft_fill_struct(buf, a);
		index = first;
	}
	else
	{
		index->next = ft_fill_struct(buf, a);
		index = index->next;
	}
}*/

int	ft_treatment(int fd)
{
	int		ret;
	char	buf[22];
	t_tetri	*first; // il faut l'initialiser ici 
	t_tetri	*index; // il faut linitialier ici
	char	letter;

	letter = 'A';
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (letter > 'Z' || ft_str_check(buf) == 1)
		{
			write(1, "error\n", 6);
			return (1);
		}
		index = ft_fill_struct(buf, letter);
		if (letter == 'A')
			first = index;
		index = index->next;
		letter++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		write(1, "usage: fill_it source_file\n", 27);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ft_treatment(fd);
	//a mon avis renvoie tetr* lst qu'on doit imprimer apres
}

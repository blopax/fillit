/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:00:34 by nvergnac          #+#    #+#             */
/*   Updated: 2017/11/21 19:00:38 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		ret_total;
	char	buf[22];
	t_tetri	*first;
	t_tetri	*index;

	//547 car 21 x 25 + 20 + 1 (verifie si le fichier ne contient pas + du max) + 1 (pour le \0)
	if (argc != 2)
	{
		write(1, "fill_it target_file\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, 21)))
	{
		if ((ret_total = ret_total + ret) > 546)
		{
			write(1, "error\n", 6);
			return (0);
		}
		buf[ret] = '\0';
		if (ft_str_check(buf) == 1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		if (ret_total == 21)
		{
			start = ft_fill_struct(buf);
			index = start;
		}
		else
		index->next = ft_fill_struct(buf);
		index = index->next;
	}
	return (0);
}

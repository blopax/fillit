/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:00:34 by nvergnac          #+#    #+#             */
/*   Updated: 2017/11/21 19:47:35 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <fcntl.h>


void	ft_lst_change(int ret_total, t_tetri *first, t_tetri *index, char a, char *buf)
{
	if (ret_total == 21)
	{
		first = ft_fill_struct(buf, a);
		index = first;
	}
	else
		index->next = ft_fill_struct(buf, a);
	index = index->next;
}

int	ft_treatment(int fd)
{
	int	ret;
	int	ret_total;
	char	buf[22];
	t_tetri	*first;
	t_tetri	*index;
	char	a;

	a = 65;
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
		ft_lst_change(ret_total, first, index, a, buf);
		a++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		write(1, "fill_it target_file\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ft_treatment(fd);
}

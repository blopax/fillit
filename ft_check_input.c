/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:09:01 by nvergnac          #+#    #+#             */
/*   Updated: 2017/11/21 16:56:53 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_check(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != 0)
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (1);
	}
	return (0);
}
*/
void	ft_getclean_coord(t_tetri *element)
{
	int j;

	j = 1;
	while (j <= 3)
	{
		element->coord[j][0] = element->coord[j][0] - element->coord[0][0];
		element->coord[j][1] = element->coord[j][1] - element->coord[0][1];
	}
	element->coord[0][0] = 0;
	element->coord[0][1] = 0;
}

t_tetri	*ft_fill_struct(char *buf)
{
	int		i;
	int		j;
	t_tetri	*element;

	i = 0;
	j = 0;
	if (!(element = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	while (buf[i] != 0)
	{
		if (buf[i] == '#')
		{
			element->coord[j][0] = (i % 5);
			element->coord[j][1] = (i / 5);
			j++;
		}
		i++;
	}
	ft_getclean_coord(element);
	return (element);
}

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

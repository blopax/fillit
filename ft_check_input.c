/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:09:01 by nvergnac          #+#    #+#             */
/*   Updated: 2017/11/20 18:37:05 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != 0)
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (1);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[22];
	int		end;

	//547 car 21 x 25 + 20 + 1 (verifie si le fichier ne contient pas + du max) + 1 (pour le \0)
	if (argc != 2)
	{
		write(1, "fill_it target_file\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, 546)))
	{
		if (ret == 20)
			end == 1;
		buf[ret] = '\0';
		if (ft_check(buf) == 1)
			write(1, "error\n", 6)

	ft_check (buf);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:25:39 by pclement          #+#    #+#             */
/*   Updated: 2017/11/22 14:40:24 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/libft.h"

static int	ft_adjacent_count(char *s, int i, int size)
{
	int		adjacent_count;

	adjacent_count = 0;
	if (i > 1 && s[i - 1] == '#')
		adjacent_count++;
	if (i > 5 && s[i - 5] == '#')
		adjacent_count++;
	if (i + 1 < size && s[i + 1] == '#')
		adjacent_count++;
	if (i + 5 < size && s[i + 5] == '#')
		adjacent_count++;
	return (adjacent_count);
}

/*
 ** Check that no # has no adjacent # and that at least 1 has 2 adjacent #
*/

static int	ft_str_shape_check(char *s, int size)
{
	int		i;
	int		count;
	int		flag;
	int		adjacent_count;

	i = 0;
	count = 0;
	flag = 0;
	adjacent_count = 0;
	while (i < size && count < 4)
	{
		if (s[i] == '#')
		{
			if (ft_adjacent_count(s, i, size) > 0)
				adjacent_count++;
			if (adjacent_count > 1)
				flag = 1;
			count++;
		}
		i++;
	}
	if (flag != 1 || adjacent_count != 4)
		return (1);
	return (0);
}

/*
** check the structure of the table (4 by 4 + \n at the end if not last
** tetromino + check that 4# (shape checked in other function)
*/

static int	ft_str_table_check(char *s, int size)
{
	int		i;
	int		count;

	if (size != 20 && size != 21)
	{
		return (1);
	}
	i = 0;
	count = 0;
	while (i < size)
	{
		if (i % 5 == 4 && s[i] != '\n')
			return (1);
		else if (i == 20 && s[i] != '\n')
			return (1);
		else if (!(i % 5 == 4 || i == 20) && s[i] == '\n')
			return (1);
		if (s[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		return (1);
	return (0);
}

static int	ft_str_char_check(char *s)
{
	while (*s)
	{
		if (*s != '.' && *s != '#' && *s != '\n')
			return (1);
		s++;
	}
	return (0);
}

/*
** Check if ONE tetromino (given as a str)  is valid (no matter first or last)
** Doesn't check number of tetrominos
*/

int			ft_str_check(char *s)
{
	if (ft_str_table_check(s, ft_int_strlen(s)))
		return (1);
	if (ft_str_char_check(s))
		return (1);
	if (ft_str_shape_check(s, ft_int_strlen(s)))
		return (1);
	else
		return (0);
}

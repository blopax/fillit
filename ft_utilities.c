/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:40:11 by pclement          #+#    #+#             */
/*   Updated: 2017/11/22 17:55:35 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_int_strlen(char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

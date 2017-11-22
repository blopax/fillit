/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:45:11 by nvergnac          #+#    #+#             */
/*   Updated: 2017/11/22 15:37:38 by pclement         ###   ########.fr       */
/*   Updated: 2017/11/21 18:14:13 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_tetri
{
	char			letter;
	int				coord[4][2];
	struct s_tetri	*next;
	int				heigth;
	int				width;
	int				opt_pos[2];
	int				test_pos[2];
}					t_tetri;

int					ft_str_check(char *s);
void				ft_getclean_coord(t_tetri *element);
t_tetri				*ft_fill_struct(char *buf, char a);
t_tetri				*ft_treatment(int fd);
int					ft_int_strlen(char *s);
#endif


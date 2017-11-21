/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:45:11 by nvergnac          #+#    #+#             */
<<<<<<< HEAD:libft.h
/*   Updated: 2017/11/21 19:18:39 by nvergnac         ###   ########.fr       */
=======
/*   Updated: 2017/11/21 18:14:13 by pclement         ###   ########.fr       */
>>>>>>> 57da9ddf7d41e0e9f586bdae5aad74303718f88b:header.h
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

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_str_check(char *s);
void				ft_getclean_coord(t_tetri *element);
t_tetri				*ft_fill_struct(char *buf);

#endif

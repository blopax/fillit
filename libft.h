/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:45:11 by nvergnac          #+#    #+#             */
/*   Updated: 2017/11/21 16:46:15 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
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


int		ft_str_check(char *s);

#endif

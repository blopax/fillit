/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:57:36 by pclement          #+#    #+#             */
/*   Updated: 2017/11/27 15:52:24 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define IT info.tab
# define ITM info.min_square
# define FMIN first->min_x
# define FMAX first->max_x

typedef struct		s_info
{
	int				nb_tetri;
	int				min_square;
	char			**tab;
}					t_info;

typedef struct		s_tetri
{
	char			letter;
	int				coord[4][2];
	struct s_tetri	*next;
	int				max_y;
	int				min_x;
	int				max_x;
}					t_tetri;

int					ft_str_check(char *s);
void				ft_getclean_coord(t_tetri *element);
t_tetri				*ft_fill_struct(char *buf, char a);
t_tetri				*ft_treatment(int fd);
int					ft_solver(t_tetri *lst);
int					ft_int_strlen(char *s);
char				**ft_redim_info_table(t_info info);
int					ft_no_zero_in_tab(t_info info);
void				ft_remove_tetr_from_table(t_info info, t_tetri *first,
		char letter, int k);
int					ft_nb_tetri(t_tetri *first);
int					ft_min_square(t_info info);
int					ft_put_tetri(t_info info, t_tetri *position, int y, int x);
void				ft_free_tab(t_info info);
void				ft_write_solution(t_info info);
#endif

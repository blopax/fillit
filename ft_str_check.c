# include "libft.h"

int		ft_str_shape_check(char	*s);
//prend coordonnees de # et pour chaque verifie que a x+1 ou x-1 ou y+1 ou y-1 
//il y a un # (et qu on reste entre 0,0 et 3,3)

int		ft_str_table_check(char	*s, int	size);
// prends longuer car 21 ou 20 si dernier 
// verifie que \n q modulo 21 et 20 
// verifie que 4# et reste sont des points

int		ft_str_char_check(char *s);
//check # et . et \n


int		ft_str_check(char*	s)
/*return 1 if error , 0 if OK*/
{
	if (ft_str_table_check(s, ft_strlen(s)))
		return (1);
	if (ft_str_char_check(s))
		return (1);
	if (ft_str_shape_check(s))
		return (1);
	else
		return (0);
}

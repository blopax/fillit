# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclement <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:57:53 by pclement          #+#    #+#              #
#    Updated: 2017/11/21 19:45:41 by pclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = .
SRC_NAME = ft_min.c ft_max.c ft_strcat.c ft_strchr.c ft_strcpy.c\
	  ft_strncpy.c ft_strdup.c ft_strlen.c\
	  ft_strncat.c ft_strlcat.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	  ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c\
	  ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c\
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
	  ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c\
	  ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = .
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS = -I.
#*. peut etre remplace par include ou le nom du dossier ou se trouvent les #include *

LDFLAGS = -L.
# *dossier de la lib*
LDLIBS = -lft
#*nom librairie par exp lft pour libft*

all: $(NAME)

$(NAME): $(OBJ)
	ar rc libft.a $(OBJ)
	ranlib libft.a

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir (OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# 1e ligne cree une regle par fichier .o et chaque fichier va tester le .c correspondant
# 2e ligne cree dossier correspondant pour lettre les .o le 2> /dev/null est la pour eviter les messages du type le dossier existe deja et  true pour que makefile continue meme si dossier existe deja 

#	si on veut rajouter une commande librairie ms pas ac obj mais dossier lib
#	ar rc libft.a $(dossier lib)
#	ranlib libft.a


clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	
fclean: clean
	rm -f $(NAME)

re: fclean all

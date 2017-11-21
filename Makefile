# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclement <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 18:57:53 by pclement          #+#    #+#              #
#    Updated: 2017/11/21 15:53:01 by pclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = .
SRC_NAME = $(wildcard *.c)
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
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

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

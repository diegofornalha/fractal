# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 09:10:47 by dida-sil          #+#    #+#              #
#    Updated: 2022/10/06 13:23:56 by dida-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOM		= libmlx.a
SRC		= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC		+= mlx_png.c mlx_mouse.m
OBJ1	= $(SRC:.c=.o)
OBJ		= $(OBJ1:.m=.o)
CFLAGS	+= -O2
CFLAGS	+= -DSTRINGPUTX11 -w

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dida-sil <dida-sil@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 13:18:43 by dida-sil          #+#    #+#              #
#    Updated: 2022/10/06 13:22:48 by dida-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= cc

INC		= /usr/include

INCLIB	= /usr/lib

LFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

CFLAGS	= -I$(INC) -O3 -Imlx -g

HEADER	= fractol.h

SRCS	= main.c prog_utils.c hooks.c fractal_formula.c

RM 		= rm -f

OBJS	= $(SRCS:%.c=%.o)

MLBX 	= mlx/libmlx.a

%.o: %.c $(HEADER)
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(MLBX)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

$(MLBX):
	@make -C mlx

norm:
	norminette *.c & norminette *.h

clean:
			${RM} ${OBJS} 
			@make clean -C mlx

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
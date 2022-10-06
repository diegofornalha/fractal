NAME = fractol

CC = cc

INC=/usr/include

INCLIB=/usr/lib

LFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

CFLAGS= -I$(INC) -O3 -Imlx -g

HEADER = fractol.h

SRCS = main.c prog_utils.c hooks.c fractal_formula.c

RM = rm -f

OBJS = $(SRCS:%.c=%.o)

%.o: %.c $(HEADER)
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(MLBX)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

$(MLBX):
	@make -C mlx

norm:
	norminette fractal_formula.c
	norminette fractol.h
	norminette hooks.c
	norminette main.c
	norminette prog_utils.c

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			clean all

.PHONY:		all clean fclean re
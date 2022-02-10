CC = gcc
LDLIBS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror 
SRCS = fractol.c events.c mandelbrot.c utils.c julia.c burningship.c

OBJS = ${SRCS:.c=.o}

NAME = fractol
HEADER = fractol.h

%.o:%.c
	@$(CC) $(CLFAGS) -c $^ -I $(HEADER)

${NAME}: ${OBJS}
	@$(CC) $(CLFAGS) $(LDLIBS) $^ -o $@ -I $(HEADER)
	@echo "\n\tVotre programme est pret a etre utiliser\n"

all: ${NAME}

clean:
	@rm -f ${OBJS}

fclean:	clean
	@rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
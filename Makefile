SRCS			=	src/main.c src/complex.c src/draw.c src/fractal.c \
					src/hooks.c src/init.c src/ft_strcmp.c src/ft_itoa.c \
					src/hooks_2.c src/ft_putstr.c

OBJS			= $(SRCS:.c=.o)

INCLUDES		= includes/fractol.h includes/bind_key.h
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -I.
LIBS			= libmlx/libmlx.a -framework OpenGL -framework AppKit -lm
MLX				= libmlx.dylib

NAME			= fractol

all:		$(NAME)

%.o: %.c	$(INCLUDES)
				$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o) -Ofast -O3

$(NAME):		 $(OBJS) $(INCLUDES)
				make -C libmlx
				$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	
clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
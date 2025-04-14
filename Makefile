
NAME	=	fract-ol

CCW		=	cc -Wall -Wextra -Werror -O2 -Iheader -Iminilibx-linux

CFLAG	=	$(LIBS) $(OUTFILE) 
OUTFILE	=	-o $(NAME)
LIBS	=	-L00_libft -lft -Lminilibx-linux -lmlx -lX11 -lXext

RMFLAG	=	rm -rf

SRCS	=	01_srcs/00_main.c 01_srcs/01_init.c 01_srcs/02_draw.c 01_srcs/03_draw_mandel.c \
			01_srcs/04_draw_julia.c 01_srcs/05_draw_ship.c 01_srcs/06_calculations.c \
			01_srcs/07_key_hook.c 01_srcs/08_mouse_hook.c 01_srcs/10_utils.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) libft -C ./00_libft
	@$(CCW) $(OBJS) $(CFLAG)
	@echo "> make fract-ol executed in current directory"

%.o: %.c
	@$(CCW) -c $< -o $@

bonus: all

clean:
	@$(MAKE) clean -C ./00_libft
	@$(RMFLAG) $(OBJS)
	@echo "> clean executed in current directory"

fclean: clean
	@$(MAKE) fclean -C ./00_libft
	@$(RMFLAG) $(NAME)
	@echo "> fclean executed in current directory"

re: fclean all

.PHONY: all bonus re clean fclean
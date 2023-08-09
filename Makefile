GREEN		= 	\033[0;32m
RED			= 	\033[0;31m
RESET		= 	\033[0m

NAME		=	cub3d

LFT			=	libft/obj libft/libft.a

MLX			=	mlx/Makefile.gen

HEADER		=	./includes -I ./libft/includes -I ./mlx

OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))

SRC			=	src/cub3d.c \
				src/game_hook.c \
				src/game_render.c


CC			=	cc
FLAGS		=	-I${HEADER} #-Wall -Wextra -Werror -g #-fsanitize=address

all:		$(MLX) $(LFT) obj $(NAME) 

$(NAME):	$(OBJ)
			@$(CC) -o $@ $^ $(FLAGS) -L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm

$(LFT):		
			@@echo " [ .. ] | Compiling libft.."
			@$(MAKE) -C libft -f Makefile all --no-print-directory
			@@echo " [ $(GREEN)OK$(RESET) ] | Libft ready!"

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@$(MAKE) -s -C mlx -f Makefile all --no-print-directory
			@echo " [ $(GREEN)OK$(RESET) ] | Minilibx ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c ./includes/cub3d.h
			@$(CC) $(FLAGS) -o $@ -c $<
			@echo "$@ $(GREEN)created$(RESET)"

valgrind:	all
			valgrind --leak-check=full --show-leak-kinds=all ./minishell

clean:
			@rm -rf $(OBJ) obj
			@$(MAKE) -C libft -f Makefile clean --no-print-directory
			@echo "Object files $(RED)removed.$(RESET)"

fclean:		clean
			@rm -rf $(NAME)
			@$(MAKE) -C libft -f Makefile fclean --no-print-directory

re:			fclean all

.PHONY:		all clean fclean re
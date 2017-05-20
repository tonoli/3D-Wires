# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 14:21:39 by itonoli-          #+#    #+#              #
#    Updated: 2017/05/19 20:57:10 by itonoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fdf
FLAGS   = -Wall -Wextra -Werror -g
SRC   = main.c motion.c color.c read.c parse.c put_xmp.c fill_image.c draw.c draw_lines.c init_fdf.c
OBJ = $(SRC:.c=.o)
LIBFT  = -L./libft -lft
MLX = -L./minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
		@ make -C libft/
		@ gcc $(FLAGS) -I libft/ -I./minilibx/ -c $(SRC)
		@ gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
		@ echo "\033[32mCompilation done : FDF is ready to be used\033[0m"

fdf_only:
		@ gcc $(FLAGS) -I libft/ -I./minilibx/ -c $(SRC)
		@ gcc $(FLAGS) -g -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
		@ echo "\033[32mCompilation done : FDF is ready to be used\033[0m"

clean:
		@ make -C libft/ clean
		@ make -C minilibx/ clean
		@ rm -f $(OBJ)
		@ echo "\033[32mThe cleaning is done my friend!\033[0m"

fclean: clean
		rm -f $(NAME)
		make -C libft/ fclean
		make -C minilibx/ fclean
		@ echo "\033[32mThe cleaning is done my friend!\033[0m"

re: fclean all

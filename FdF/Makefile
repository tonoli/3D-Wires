# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 14:21:39 by itonoli-          #+#    #+#              #
#    Updated: 2017/05/11 17:45:00 by itonoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fdf
FLAGS   = -Wall -Wextra -Werror
SRC   = main.c read.c image.c draw.c draw_lines.c
OBJ = $(SRC:.c=.o)
MLX  = -L./libft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
		@ make -C libft/
		@ gcc $(FLAGS) -I libft/ -I./minilibx/ -c $(SRC)
		@ gcc $(FLAGS) -o $(NAME) $(OBJ) $(MLX)

fdf_only:
		@ gcc $(FLAGS) -I libft/ -I./minilibx/ -c $(SRC)
		@ gcc $(FLAGS) -o $(NAME) $(OBJ) $(MLX)

clean:
		make -C libft/ clean
		make -C minilibx/ clean
		rm -f $(OBJ) libft.a libmlx.a

fclean: clean
		rm -f $(NAME)
		make -C libft/ fclean

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 14:21:39 by itonoli-          #+#    #+#              #
#    Updated: 2017/05/13 20:19:19 by itonoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fdf
FLAGS   = -Wall -Wextra -Werror -g
SRC   = main.c read.c parse.c fill_image.c draw.c draw_lines.c init_fdf.c
OBJ = $(SRC:.c=.o)
LIBFT  = -L./libft -lft
MLX = -L./minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
		@ make -C libft/
		@ gcc $(FLAGS) -I libft/ -I./minilibx/ -c $(SRC)
		@ gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

fdf_only:
		@ gcc $(FLAGS) -I libft/ -I./minilibx/ -c $(SRC)
		@ gcc $(FLAGS) -g -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

clean:
		make -C libft/ clean
		make -C minilibx/ clean
		rm -f $(OBJ) libft.a libmlx.a

fclean: clean
		rm -f $(NAME)
		make -C libft/ fclean
		make -C minilibx/ fclean

re: fclean all

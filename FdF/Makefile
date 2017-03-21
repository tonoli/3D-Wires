# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 14:21:39 by itonoli-          #+#    #+#              #
#    Updated: 2017/03/21 19:42:33 by itonoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fdf
FLAGS   = -Wall -Wextra -Werror
SRC   = main.c read.c
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
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)
		make -C libft/ fclean

re: fclean all

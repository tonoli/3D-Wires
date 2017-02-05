# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 14:21:39 by itonoli-          #+#    #+#              #
#    Updated: 2017/02/05 14:25:44 by itonoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fdf
FLAGS   = -Wall -Wextra -Werror
FILES   = main.c read.c draw.c run.c position.c depth.c rotation.c draw_line.c
OBJECTS = $(FILES:.c=.o)
ATTACH  = -L./libft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
		make -C libft/
		gcc $(FLAGS) -I libft/ -I./minilibx/ -c $(FILES)
		gcc $(FLAGS) -o $(NAME) $(OBJECTS) $(ATTACH)

fdf_only:
		gcc $(FLAGS) -I libft/ -I./minilibx/ -c $(FILES)
		gcc $(FLAGS) -o $(NAME) $(OBJECTS) $(ATTACH)

run42:
		./fdf test_maps/42.fdf

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)
		make -C libft/ fclean

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 14:21:39 by itonoli-          #+#    #+#              #
#    Updated: 2017/05/20 20:02:26 by itonoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PROGRAM NAME
NAME = fdf

#SOURCES AND OBJECTS
SRC_NAME = main.c \
motion.c \
color.c \
read.c \
parse.c \
put_xmp.c \
fill_image.c \
draw.c \
draw_lines.c \
init_fdf.c \
help.c \
style.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = src/
OBJ_PATH = obj/
LIB_PATH = libft/includes/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -I,$(LIB_PATH))

#COMPILATION
CC = gcc
FLAGS = -Wall -Wextra -Werror -I.inc

#LIBRARY
LIBFT  = -L./libft -lft
MLX = -L./minilibx -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME):$(OBJ)
		@ make -C libft/
		@ make -C minilibx/
		@ $(CC) $(FLAGS) $(LIBFT) $(MLX) $^ -o $@
		@ echo "\033[32mCompilation done : FDF is ready to be used\033[0m"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
		@ mkdir -p $(OBJ_PATH)
		@ $(CC) $(FLAGS) $(LIB) -o $@ -c $<

fdf_only:
		@ $(CC) $(FLAGS) -I libft/ -I./minilibx/ -c $(SRC)
		@ $(CC) $(FLAGS) -g -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
		@ echo "\033[32mCompilation done : FDF is ready to be used\033[0m"

clean:
		@ echo "\033[32mCleaning the following files: \033[0m"
		@ make -C libft/ clean
		@ make -C minilibx/ clean
		@ rm -vf $(OBJ)
		@ rm -rfv $(OBJ_PATH)
		@ echo "\033[32mThe cleaning is done my friend!\033[0m"

fclean: clean
		@ rm -vf $(NAME)
		@ make -C libft/ fclean
		@ make -C minilibx/ fclean
		@ echo "\033[32mThe cleaning is done my friend!\033[0m"

norm:
		@ echo "\033[34;1mNorminette...\033[0m"
		@ norminette src inc

re: fclean all

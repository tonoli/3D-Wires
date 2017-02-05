# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/17 10:08:39 by aliandie          #+#    #+#              #
#    Updated: 2015/02/04 12:02:30 by aliandie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

CC		= gcc
CFLAGS  = -Wall -Werror -Wextra

SRC		+= draw_line.c
SRC		+= expose_hook.c
SRC		+= get_next_line.c
SRC		+= gnl_counter.c
SRC		+= key_hook.c
SRC		+= main.c
SRC		+= print_map.c
SRC		+= readmap.c

OBJ		= $(SRC:.c=.o)

INC		= fdf.h

LIBX	= -L/usr/X11/lib -lmlx -lXext -lX11


all: $(NAME) 

$(NAME): $(OBJ)
	@make -C libft/ re
	$(CC) $(LIBX) -Llibft -lft -o $@ $(OBJ)

clean:
	@make clean -C libft/
	rm -rf $(OBJ)
fclean : clean
	@make fclean -C libft/
	rm -rf $(NAME)

re: fclean all


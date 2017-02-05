/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 10:18:58 by aliandie          #+#    #+#             */
/*   Updated: 2015/02/04 13:29:55 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"

typedef	struct	s_point
{
	int			x;
	int			y;
	int			c;
	int			i;
}				t_point;

typedef	struct	s_map
{
	int			map_line;
	int			map_col;
	int			**map;
	int			z;
	int			l;
	int			c;
	int			ct;
}				t_map;

typedef struct	s_line
{
	t_point		start;
	t_point		end;
}				t_line;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	t_map		map;
}				t_env;

void			draw_line(t_env *e, t_point start, t_point end, int color);
void			print_map(t_map map, t_env *env);
int				expose_hook(t_env	*env);
int				key_hook(int	keycode, t_env	*env);
t_map			readmap(char *f, char *line);
int				gnl_counter(char *f, char *line);
#endif

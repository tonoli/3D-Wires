/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:03:34 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/16 23:44:30 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "macros.h"
# include <math.h>

# define WIDTH		1360
# define HEIGHT		900
# define RED		156
# define GREEN		200
# define BLUE		255
# define ESC_KEY	53

typedef struct		s_point
{
	int		x;
	int		y;
	int		color;
}					t_point;

typedef struct	s_diff
{
	int		x;
	int		y;
	int		absx;
	int		absy;
}				t_diff;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*ptr_img;
	int		*img_data;
	int 	**mapi;
	t_point	**grid;
	t_point	poss;
	int		zoom;
	int		deepth;
	double	rot;
	int		proj;
	int		move_h;
	int		move_v;
	int		lines;
	int		col;
	int		bpp;
	int		size_line;
	int		endian;
	int		dx;
	int		dy;
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
	t_diff	diff;
}					t_env;


int		ft_read(char *path, t_env *env);
void	parse(t_env *env);
void	initenv(t_env *env);
int		key_hook(int key, t_env *env);
//void	fill_pixel(t_env *env, int x, int y, int color);
void    fill_img(t_env *env);
void	new_img(t_env *env);
void    draw(t_env *env, t_point start, t_point end);
void    draw_lines(t_env *env);
void    draw_col(t_env *env);

#endif

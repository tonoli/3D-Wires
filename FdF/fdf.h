/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:03:34 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/12 22:22:22 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
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
}					t_point;

typedef struct	s_diff
{
	int		x;
	int		y;
	int		abs_x;
	int		abs_y;
}				t_diff;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*ptr_img;
	char	*img_str;
	int 	**mapi;
	t_point	**grid;
	t_point view;
	int		lines;
	int		col;
	int		depth;
	int		bpp;
	int		size_line;
	int		endian;
	t_diff	diff;
}					t_env;

int		ft_read(char *path, t_env *env);
void	parse(t_env *env);
void	fill_pixel(int x, int y, t_env *env);
void    create_image(t_env *env);
void    fill_img(t_env *env);
void    draw(t_env *env, t_point start, t_point end);
void    draw_lines(t_env *env);
void    draw_col(t_env *env);

#endif

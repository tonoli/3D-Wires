/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:03:34 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/11 21:34:00 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

# define WIDTH		1560
# define HEIGHT		600
# define RED		255
# define GREEN		255
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
	int		lines;
	int		col;
	int		bpp;
	int		size_line;
	int		endian;
	t_point start;
	t_point	end;
	t_diff	diff;
}					t_env;

int		ft_read(char *path, t_env *env);
void	fill_pixel(int x, int y, t_env *env);
void    create_image(t_env *env);
void    fill_img(t_env *env);
void    draw(t_env *env, t_point start, t_point end);
void    draw_lines(t_env *env);
void    draw_col(t_env *env);

#endif

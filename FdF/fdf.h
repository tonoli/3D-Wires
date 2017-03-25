/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:03:34 by itonoli-          #+#    #+#             */
/*   Updated: 2017/03/25 01:40:25 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

# define WIDTH	2560
# define HEIGHT	1400
# define RED	255
# define GREEN	255
# define BLUE	255

struct		s_point
{
	int		x;
	int		y;
	int		z;
	int		c;
}typedef	t_point;

struct		s_env
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
	int		draw_start;
	int		draw_end;
	t_point start;
	t_point	end;
}typedef	t_env;


typedef struct	s_diff
{
	int		x;
	int		y;
	int		abs_x;
	int		abs_y;
}				t_diff;

int		ft_read(char *path, t_env *env);
void	fill_pixel(int x, int y, t_env *env);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:03:34 by itonoli-          #+#    #+#             */
/*   Updated: 2017/01/28 18:21:25 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

# define WIDTH	2560
# define HEIGHT	1400


struct		s_point
{
	int		x;
	int		y;
	int		z;
	int		c;
}typedef	t_point;

struct		s_map
{
	int		col_len;
	int		line_len;
	t_point	*points;
}typedef	t_map;

struct		s_env
{
	void	*mlx;
	void	*win;
	t_image	*img;
	t_map	*map;
	double	point_d;
	double	z_max;
	double	z_min;
}typedef	t_env;


typedef struct	s_delta
{
	int		x;
	int		y;
	int		abs_x;
	int		abs_y;
}				t_delta;
/*
typedef struct	s_fdf
{
	int		height;
	int		width;
	int		depth;
	t_point	view;
	t_point	pos;
	int		**input;
	t_point	**grid;
}				t_fdf;

typedef struct	s_mlx
{
	int		height;
	int		width;
	void	*mlx;
	void	*window;
}				t_mlx;

typedef struct	s_data
{
	t_fdf	*fdf;
	t_mlx	*mlx;
}				t_data;
*/

#endif

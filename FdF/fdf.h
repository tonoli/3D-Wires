/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:03:34 by itonoli-          #+#    #+#             */
/*   Updated: 2017/03/23 18:13:24 by itonoli-         ###   ########.fr       */
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

struct		s_env
{
	void	*mlx;
	void	*win;
	void	*ptr_img;
	char	*img_str;
	int 	**mapi;
	int		lines;
	int		col;
}typedef	t_env;


typedef struct	s_delta
{
	int		x;
	int		y;
	int		abs_x;
	int		abs_y;
}				t_delta;

int		ft_read(char *path, t_env *env);

#endif

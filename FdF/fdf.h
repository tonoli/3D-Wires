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
# include <mlx.h>

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
	t_map	map;
}typedef	t_env;

#endif

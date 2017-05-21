/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:03:34 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/20 22:59:41 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "macros.h"
# include <math.h>

typedef struct		s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}					t_point;

typedef struct		s_diff
{
	int		x;
	int		y;
	int		absx;
	int		absy;
}					t_diff;

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*ptr_img;
	void	*logo;
	void	*icon_help;
	void	*icon_color;
	void	*icon_reset;
	void	*iso;
	void	*icon_zoom;
	int		*img_data;
	void	*ptr_menu;
	int		*menu_data;
	int		**mapi;
	t_point	**grid;
	t_point	poss;
	double	zoom;
	double	deepth;
	double	rotp;
	double	roti0;
	double	roti1;
	int		help;
	int		proj;
	int		color;
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
	char	*line;
	char	**tab;
	int		z_max;
	int		z_min;
	t_diff	diff;
}					t_env;

void				ft_read(char *path, t_env *env);
void				parse(t_env *env);
void				new_menu(t_env *env);
void				initenv(t_env *env);
void				init_val(t_env *env);
void				init_zoom_deepth(t_env *env);
long				get_zmax(t_env *env);
int					key_hook(int key, t_env *env);
int					mouse_hook(int key, int x, int y, t_env *env);
void				put_color(t_env *env, t_point start, t_point end);
void				put_xmp(t_env *env);
void				openhelp(t_env *env);
void				closehelp(t_env *env);
void				proj(t_env *env);
void				color(t_env *env);
void				reinit(t_env *env);
void				rotate(t_env *env, int key);
void				fill_img(t_env *env);
void				new_img(t_env *env);
void				draw(t_env *env, t_point start, t_point end);
void				draw_lines(t_env *env);
void				draw_col(t_env *env);

#endif

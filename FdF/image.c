/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:59:42 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/12 20:01:24 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_image(t_env *env)
{
	int		bbp;
	int		sizeline;
	int		endian;

	env->ptr_img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_str = mlx_get_data_addr(env->ptr_img, &bbp, &sizeline, &endian);
}

void	fill_pixel(int x, int y, t_env *env)
{
//		ft_putendl("pixel start");
		env->img_str[(env->bpp / 8) * x + env->size_line * y] = mlx_get_color_value(env->mlx, BLUE);
		env->img_str[(env->bpp / 8) * x + env->size_line * y + 1] = mlx_get_color_value(env->mlx, GREEN);
		env->img_str[(env->bpp / 8) * x + env->size_line * y + 2] = mlx_get_color_value(env->mlx, RED);
//		ft_putendl("pixel put");
}
void	fill_img(t_env *env)
{
	draw_lines(env);
	ft_putendl("lines_fill............OK");
	mlx_put_image_to_window(env->mlx, env->win, env->ptr_img, WIDTH, HEIGHT);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:59:42 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/11 18:03:21 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_image(t_env *env)
{
	env->ptr_img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_str = mlx_get_data_addr(env->ptr_img, &env->bpp, &env->size_line, &env->endian);
}

void	fill_pixel(int x, int y, t_env *env)
{
	env->img_str[(env->bpp / 8) * x + env->size_line * y] = mlx_get_color_value(env->mlx, BLUE);
	env->img_str[(env->bpp / 8) * x + env->size_line * y + 1] = mlx_get_color_value(env->mlx, GREEN);
	env->img_str[(env->bpp / 8) * x + env->size_line * y + 2] = mlx_get_color_value(env->mlx, RED);
}

void	fill_img(t_env *env)
{

/*
 * Prendre l'image et allumer tous les 
 * points necessaire grace aux fonctions draw_lines/col qui diront 
 * lesquels allumer et fill_pixel qui viendra les allumer deriere
 */	
	draw_lines(env);
	draw_col(env);
	mlx_put_image_to_window(env->mlx, env->win, env->ptr_img, 420, 420);
}

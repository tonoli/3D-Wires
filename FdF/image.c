/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:59:42 by itonoli-          #+#    #+#             */
/*   Updated: 2017/03/24 21:52:11 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_image(t_env *env)
{
	env->ptr_img = mlx_new_image(env -> mlx, WIDTH, HEIGHT);
	env->img_str = mlx_get_data_addr(env->ptr_img, &env->bpp, &env->size_line, &env->endian);
}

void	fill_pixel(int x, int y, t_env *env)
{
	env->img_str[(env->bpp / 8) * x + env->size_line * y] = mlx_get_color_value(env->mlx, BLUE);
	env->img_str[(env->bpp / 8) * x + env->size_line * y + 1] = mlx_get_color_value(env->mlx, GREEN);
	env->img_str[(env->bpp / 8) * x + env->size_line * y + 2] = mlx_get_color_value(env->mlx, RED);
}

void	fill_img(t_env *env, int current_x)
{
	// Prendre l'image et allumer tous les points necessaire grace
	// aux fonctions draw qui diront lesquels alluner  et fill_pixel qui
	// viendra les allumer deriere
	int pen = env->draw_start;
	create_image(env);
	while	(pen != env->draw_end)
	{
		put_pixel_to_img(env, current_x, pen);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 420, 420);
		pen++;
	}
}

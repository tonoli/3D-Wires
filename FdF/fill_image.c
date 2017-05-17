/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:59:42 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/16 11:11:41 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


	/*
	 *
	 * Draw the menu and arrows
	 *
	 */
void	draw_menu(t_env *env)
{
	int x, y;

	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			//mlx_pixel_put(env->mlx, env->win, x, y, CO);
			//fill_pixel(env, x, y, CO);
			if (x > 200 && x < 200 && y>200 && y < 200)
				env->img_data[x * WIDTH + y] = 0xFFFFFF;
			y++;
		}
		x++;
	}
}

void	new_img(t_env *env)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = (int*)mlx_get_data_addr(IMG, &BPP, &SL, &ENDIAN);
}

void	fill_img(t_env *env)
{
	draw_lines(env);
	//draw_test(env);
	mlx_put_image_to_window(env->mlx, env->win, env->ptr_img, 0, 0);
}

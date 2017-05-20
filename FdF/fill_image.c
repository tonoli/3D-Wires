/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:59:42 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/19 23:30:34 by itonoli-         ###   ########.fr       */
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
	int x;
	int y;

	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			env->menu_data[x * WIDTH + y] = WHITE;
			if ((x < 42 && x > 39) || (x < 150 && x > 147))
				env->menu_data[x * WIDTH + y] = 0x000000;
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

void	new_menu(t_env *env)
{
	int		bpp;
	int		size_line;
	int		endian;
	env->ptr_menu = mlx_new_image(MLX, WIDTH, HEIGHT);
	env->menu_data = (int*)mlx_get_data_addr(env->ptr_menu, &bpp, &size_line, &endian);
}

void	fill_img(t_env *env)
{

	draw_lines(env);
	draw_menu(env);
	mlx_put_image_to_window(env->mlx, env->win, env->ptr_menu, 0, 0);
	put_xmp(env);
	mlx_put_image_to_window(env->mlx, env->win, env->ptr_img, 50, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:08:05 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/14 00:25:45 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define COLOR 0xFFFFFF
# define color 0xFFFFFF

void	init_diff(t_env *env, t_point start, t_point end)
{
	env->diff.x = end.x - start.x;
	env->diff.y = end.y - start.y;
	env->diff.abs_x = abs(env->diff.x);
	env->diff.abs_y = abs(env->diff.y);
}
void	draw_one(t_env *env, t_point start, t_point end)
{
	int		e;
	int		e_one;
	int		e_two;
	int		inc_y;

	ft_putendl("DRAW ONE");
	inc_y = (env->diff.y > 0) ? 1 : -1;
	e = -(env->diff.abs_x);
	e_one = 2 * env->diff.abs_y;
	e_two = -2 * env->diff.abs_x;
	if (env->diff.x > 0)
	{
		while (start.x <= end.x)
		{
			//mlx_pixel_put(env->mlx, env->win, start.x, start.y, RD);
			if ((start.x * WIDTH + start.y) <= WIDTH*HEIGHT)
				env->img_data[start.x * WIDTH + start.y] = color;
			if ((e += e_one) >= 0)
			{
				start.y += inc_y ;
				e += e_two;
			}
			start.x += 1;
		}
	}
	else
	{
		while (start.x >= end.x)
		{
			//mlx_pixel_put(env->mlx, env->win, start.x, start.y, RD);
			if ((start.x * WIDTH + start.y) <= WIDTH*HEIGHT)
				env->img_data[start.x * WIDTH + start.y] = color;
			if ((e += e_one) >= 0)
			{
				start.y += inc_y ;
				e += e_two;
			}
			start.x -= 1;
		}
	}
}
void	draw_two(t_env *env, t_point start, t_point end)
{
	int		e;
	int		inc_x;

	ft_putendl("DRAW TWO");
	inc_x = (env->diff.x > 0) ? 1 : -1;
	e = -(env->diff.abs_y);
	if (env->diff.y > 0)
	{
		while (start.y <= end.y)
		{
			if ((start.x * WIDTH + start.y) <= WIDTH*HEIGHT)
				env->img_data[start.x * WIDTH + start.y] = color;
	//		mlx_pixel_put(env->mlx, env->win, start.x, start.y, RD);
//			fill_pixel(start.y, start.x, env);
			if ((e += 2 * env->diff.abs_x) >= 0)
			{
				start.x += inc_x ;
				e -= 2 * env->diff.abs_y;
			}
			start.y += 1;
		}
	}
	else
	{
		while (start.y <= end.y)
		{
			if ((start.x * WIDTH + start.y) <= WIDTH*HEIGHT)
				env->img_data[start.x * WIDTH + start.y] = color;
			//mlx_pixel_put(env->mlx, env->win, start.x, start.y, RD);
//			fill_pixel(start.y, start.x, env);
			if ((e += 2 * env->diff.abs_x) >= 0)
			{
				start.x += inc_x ;
				e -= 2 * env->diff.abs_y;
			}
			start.y -= 1;
		}
	}
}
/*
 void	draw_two(t_diff *diff, t_env *env, t_point start, t_point end)
 {
 	int		e;
 	int		inc_x;
 	int		inc_y;

 	inc_x = (diff->x > 0) ? 1 : -1;
 	inc_y = (diff->y > 0) ? 1 : -1;
 	e = -diff->abs_y;
 	while (start.y <= end.y)
 	{
		if (start.x >= 0 && start.x < HEIGHT && start.y >= 0 && start.y < WIDTH)
 			env->img_data[start.x * WIDTH + start.y] = color;
 		if ((e += 2 * diff->abs_x) >= 0)
 		{
 			start.x += inc_x ;
 			e -= 2 * diff->abs_y;
 		}
 		start.y += inc_y;
 	}
 }

void	draw_one(t_env *env, t_point start, t_point end)
{
	int x;
	int y;
	int dx;
	int dy;
	int e;

	x = start.x;
	y = start.y;
	dx = env->diff.abs_x;
	dy = 2 * env->diff.abs_y;
	e = dx;

	while(x < end.x)
	{
//		mlx_pixel_put(env->mlx, env->win, x, y, COLOR);
		if (x >= 0 && x < env->col && y >= 0 && y < env->lines)
		fill_pixel(env, x, y, color);
		x++;
	}
}
void	draw_two(t_env *env, t_point start, t_point end)
{
	int x;
	int y;

	x = start.x;
	y = start.y;

	while(y < end.y)
	{
//		mlx_pixel_put(env->mlx, env->win, x, y, COLOR);
		fill_pixel(env, y, x, color);
		y++;
	}
}
*/
void	draw(t_env *env, t_point start, t_point end)
{
	init_diff(env, start, end);

	if (env->diff.x >= env->diff.y)
		draw_one(env, start, end);
	else
		draw_two(env, start, end);
}

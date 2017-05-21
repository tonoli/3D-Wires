/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:08:05 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/20 21:36:08 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void draw_one(t_env *env, t_point start, t_point end)
{
	int sx = (end.x - start.x < 0) ? -1 : 1;
	int sy = (end.y - start.y < 0) ? -1 : 1;
	int err = DIFX + DIFY;
	int e2;

	while (start.x != end.x)
	{
		if ((start.x * WIDTH + start.y) <= WIDTH * HEIGHT && start.x > 0
			&& start.y > 0 && start.y < WIDTH && start.x < HEIGHT)
			put_color(env, start, end);
		if (start.x == end.x && start.y == end.y) break;
		e2 = 2 * err;
		if (e2 >= DIFX)
		{
			err += DIFY;
			start.x += sx;
		}
		if (e2 <= DIFX)
		{
			err += DIFX;
			start.y += sy;
		}
	}
}

void draw_two(t_env *env, t_point start, t_point end)
{
	int sx = (end.x - start.x < 0) ? -1 : 1;
	int sy = (end.y - start.y < 0) ? -1 : 1;
	int err = DIFX + DIFY;
	int e2;

	while (start.y != end.y)
	{
		if ((start.x * WIDTH + start.y) <= WIDTH * HEIGHT && start.x > 0
			&& start.y > 0 && start.y < WIDTH && start.x < HEIGHT)
			put_color(env, start, end);
		if (start.x == end.x && start.y == end.y) break;
		e2 = 2 * err;
		if (e2 >= DIFY)
		{
			err += DIFY;
			start.x += sx;
		}
		if (e2 <= DIFX)
		{
			err += DIFX;
			start.y += sy;
		}
	}
}

void	draw(t_env *env, t_point start, t_point end)
{
	env->dx = abs(end.x - start.x);
	env->dy = -abs(end.y - start.y);

	if ((-env->dy) < env->dx)
		draw_one(env, start, end);
	else
		draw_two(env, start, end);
}

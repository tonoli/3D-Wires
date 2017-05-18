/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:08:05 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/17 19:17:36 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_one(t_env *env, int x0, int y0, int x1, int y1)
{
	int sx = (x1 - x0 < 0) ? -1 : 1;
	int sy = (y1 - y0 < 0) ? -1 : 1;
	int err = DIFX + DIFY;
	int e2;

	while (x0 != x1)
	{
		if ((x0 * WIDTH + y0) <= WIDTH * HEIGHT && x0 > 0
			&& y0 > 0 && y0 < WIDTH && x0 < HEIGHT)
			put_color(env, x0, y0);
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= DIFX)
		{
			err += DIFY;
			x0 += sx;
		}
		if (e2 <= DIFX)
		{
			err += DIFX;
			y0 += sy;
		}
	}
}

void draw_two(t_env *env, int x0, int y0, int x1, int y1)
{
	int sx = (x1 - x0 < 0) ? -1 : 1;
	int sy = (y1 - y0 < 0) ? -1 : 1;
	int err = DIFX + DIFY;
	int e2;

	while (y0 != y1)
	{
		if ((x0 * WIDTH + y0) <= WIDTH * HEIGHT && x0 > 0
			&& y0 > 0 && y0 < WIDTH && x0 < HEIGHT)
			put_color(env, x0, y0);
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= DIFY)
		{
			err += DIFY;
			x0 += sx;
		}
		if (e2 <= DIFX)
		{
			err += DIFX;
			y0 += sy;
		}
	}
}


void	draw(t_env *env, t_point start, t_point end)
{
	env->dx = abs(end.x - start.x);
	env->dy = -abs(end.y - start.y);

	if (start.x == end.x && start.y == end.y)
		DATA[start.x * WIDTH + start.y] = start.color;
	else
	{
		if ((-env->dy) < env->dx)
			draw_one(env, start.x, start.y, end.x, end.y);
		else
			draw_two(env, start.x, start.y, end.x, end.y);
	}
}
